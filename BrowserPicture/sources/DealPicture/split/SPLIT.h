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
class _declspec(dllexport) SPLIT   //������point
#else
class _declspec(dllimport) SPLIT   //������point
#endif
{
public:
  SPLIT();

  virtual ~SPLIT();

public:	
  bool release();
  bool getGridUnitByLine(int _lineIndex, int _rowIndex);
  bool savePicByR_G_B();//ͼ����RGBֵ�����洢
  bool savePicByGray_N(int n);//����rgb�洢�󣬽��лҶȽ׽��д洢  n��ȡֵ��ΧΪ 0 - 8
  bool setLineRowNum(int _mLineNum, int _mRowNum);
  bool init(int _mlineNum, int _mRowNum, const char *pSzFileNameIn);		//��ʼ������
  bool init(const char *pSzFileNameIn);
  bool doSplit();		//��������
  bool validCheck();	//check ������Ч��
  bool mergeGray();	//�ϲ��ҶȽ׵�ͼ��
  bool mergeGray(int,int);//���������ϲ��ҶȽ�
  bool mergeRGB();	//�ϲ�RGBͨ��
  bool mergeRGB(const char*);	//����R����G��B��RGBͨ���ϲ�
  bool mergeSplit();   //�ϲ��ָ��ͼ��
  bool mergeSplit(int,int,int,int);//�������ϲ��ָ��ͼ��
  void formatFileName(int,int);//��ʽ���ļ������е�����
  BMIH getBMIH(const char *pSzFileNameIn);
  BMFH getBMFH(const char *pSzFileNameIn);
  bool getGridUnitByStep(int _lineIndex, int rowIndex);
  bool setMethod(int m);//m=0 Ϊsplit->rgb->gray  m=1Ϊrgb->split->gray  m=2Ϊrgb->gray->split
  bool setSplit(int m);
  bool setRGB(int);
  bool setGray(int);
  char* returnFileName(char *pathname,char c);//��ȡ���c�ַ�������ַ���
  char* returnFirstFileName(char *filename,char c);//��ȡ��һ��c�ַ�����ַ���
private:
  bool writeNewFileHeader(FILE *_fp);
  bool mNeedLog;		//�Ƿ���ҪLog
  BMFH bmfh;			//�����ļ�ͷ����Ϣ
  BMIH bmih;
  BMFH bmfhOut;			//����ļ�ͷ����Ϣ
  BMIH bmihOut;
  int mLineNum, mRowNum;	//Grid��������Ŀ
  int tmLineNum,tmRowNum;

  FILE *fpIn;				//�����ļ����
  char szFileNameIn[1024];	//�����ļ�ȫ����
  char szFileName[1024]; //�����ļ���
  bool setFilePath(const char* pSzFileNameIn);		//���������ļ�·��
  bool safeReadDataFromFile( int offset, char* buffer, int size, int number, FILE* fp ); //���ض��ζ�ȡ����

  int mNewHeight, mNewWidth;
  char* pNewHeaderBuf;		//���ļ�ͷָ��
  bool makeNewFileHeader(int _mHeight,int _mWidth);	//�������ļ�ͷ
  bool getFileHeader();//��ȡλͼ��Ϣͷ

  int  bitBitCount;//��¼��ɫλ��
  int step;//��ɫ���ֽ���
  char chLine[10];//�����ֵĸ�ʽ���ַ��洢
  char chRow[10];//�����ֵĸ�ʽ���ַ��洢
  char *rowBuf;
  int method;
  int split_pic;
  int rgb_pic;
  int gray_pic;
};

#endif // !defined(AFX_SPLIT_H__5F2347B9_4C3B_40E6_8C71_4A0185D26FC3__INCLUDED_)
