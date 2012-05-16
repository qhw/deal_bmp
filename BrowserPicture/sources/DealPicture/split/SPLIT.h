// SPLIT.h: interface for the SPLIT class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPLIT_H__5F2347B9_4C3B_40E6_8C71_4A0185D26FC3__INCLUDED_)
#define AFX_SPLIT_H__5F2347B9_4C3B_40E6_8C71_4A0185D26FC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _Split_Version_
#define _Split_Version_ 1.0
#endif

//bool SplitBMPwarnings = true;
#include "../easy/EasyBMP.h"
using namespace std;

#define  BMP_FILE_HEADER_LEN 14
#define  BMP_INFO_HEADER_LEN 40
#ifdef DLL_FILE
class _declspec(dllexport) SPLIT   //导出类point
#else
class _declspec(dllimport) SPLIT   //导入类point
#endif
{
public:
  SPLIT();

  virtual ~SPLIT();

public:	
  bool release();
  bool getGridUnitByLine(int _lineIndex, int _rowIndex);
  bool savePicByR_G_B();//图像按照RGB值单独存储
  bool savePicByGray_N(int n);//按照rgb存储后，进行灰度阶进行存储  n的取值范围为 0 - 8
  bool setLineRowNum(int _mLineNum, int _mRowNum);
  bool init(int _mlineNum, int _mRowNum, const char *pSzFileNameIn);		//初始化函数
  bool init(const char *pSzFileNameIn);
  bool doSplit();		//启动函数
  bool validCheck();	//check 参数有效性
  bool mergeGray();	//合并灰度阶的图像
  bool mergeGray(int,int);//按照条件合并灰度阶
  bool mergeRGB();	//合并RGB通道
  bool mergeRGB(const char*);	//按照R或者G或B或RGB通道合并
  bool mergeSplit();   //合并分割的图像
  bool mergeSplit(int,int,int,int);//按条件合并分割的图像
  void formatFileName(int,int);//格式化文件名的中的数字
  BMIH getBMIH(const char *pSzFileNameIn);
  BMFH getBMFH(const char *pSzFileNameIn);
  bool getGridUnitByStep(int _lineIndex, int rowIndex);
  bool setMethod(int m);//m=0 为split->rgb->gray  m=1为rgb->split->gray  m=2为rgb->gray->split
  bool setSplit(int m);
  bool setRGB(int);
  bool setGray(int);
  char* returnFileName(char *pathname,char c);//获取最后c字符后面的字符串
  char* returnFirstFileName(char *filename,char c);//获取第一个c字符后的字符串
private:
  bool writeNewFileHeader(FILE *_fp);
  bool mNeedLog;		//是否需要Log
  BMFH bmfh;			//输入文件头部信息
  BMIH bmih;
  BMFH bmfhOut;			//输出文件头部信息
  BMIH bmihOut;
  int mLineNum, mRowNum;	//Grid的行列数目
  int tmLineNum,tmRowNum;

  FILE *fpIn;				//输入文件句柄
  char szFileNameIn[1024];	//输入文件全名称
  char szFileName[1024]; //输入文件名
  bool setFilePath(const char* pSzFileNameIn);		//设置输入文件路径
  bool safeReadDataFromFile( int offset, char* buffer, int size, int number, FILE* fp ); //从特定段读取数据

  int mNewHeight, mNewWidth;
  char* pNewHeaderBuf;		//新文件头指针
  bool makeNewFileHeader(int _mHeight,int _mWidth);	//适配新文件头
  bool getFileHeader();//获取位图信息头

  int  bitBitCount;//记录颜色位数
  int step;//颜色的字节数
  char chLine[10];//行数字的格式化字符存储
  char chRow[10];//列数字的格式化字符存储
  char *rowBuf;
  int method;
  int split_pic;
  int rgb_pic;
  int gray_pic;
};

#endif // !defined(AFX_SPLIT_H__5F2347B9_4C3B_40E6_8C71_4A0185D26FC3__INCLUDED_)
