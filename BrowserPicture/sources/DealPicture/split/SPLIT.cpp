// SPLIT.cpp: implementation of the SPLIT class.
//
//////////////////////////////////////////////////////////////////////
#ifndef DLL_FILE
#define DLL_FILE
#endif
#include "SPLIT.h"
#include <ctime>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SPLIT::SPLIT()
{
  method = 0;
  mLineNum=0;
  mRowNum=0;
  mNewHeight=0;
  mNewWidth=0;
  mNeedLog=true;
  pNewHeaderBuf=NULL;
  rowBuf=NULL;
  fpIn = NULL;
  memset(szFileNameIn,0,1024*sizeof(char));
  memset(szFileName,0,1024*sizeof(char));
}

SPLIT::~SPLIT()
{
  if (pNewHeaderBuf)
  {
    free(pNewHeaderBuf);
  }
  if (rowBuf)
  {
    free(rowBuf);
  }
  if (fpIn)
  {
    fclose(fpIn);
  }
}

bool SPLIT::init(const char *pSzFileNameIn)
{
  setFilePath(pSzFileNameIn);
  bmfh = bmfhOut =GetBMFH(szFileNameIn);
  bmih = bmihOut =GetBMIH(szFileNameIn);	

  //��ʾͼ����Ϣ
  DisplayBitmapInfo(szFileNameIn);

  //double check valid
  if (!validCheck())
  {
    return false;
  }
  fpIn = fopen( szFileNameIn,"rb");	
  //��ȡ�µ�ͷ����Ϣ
  getFileHeader();
  //	rowBuf = (char *) malloc(step);
  return true;
}

bool SPLIT::init(int _mlineNum, int _mRowNum, const char *pSzFileNameIn)
{
  setLineRowNum(_mlineNum, _mRowNum);
  setFilePath(pSzFileNameIn);
  bmfh = bmfhOut =GetBMFH(szFileNameIn);
  bmih = bmihOut =GetBMIH(szFileNameIn);	

  //�����µ��п�����
  if ((bmih.biHeight%_mlineNum) || (bmih.biWidth%_mRowNum))
  {
    //��������
    cout << endl
      << "��������������Ŀ������!" << endl
      << "ԭͼ�񳤿���" << bmih.biWidth << " * " << bmih.biHeight << endl
      << "���зָ�Ϊ��" << _mlineNum	<< "*" << _mRowNum << endl;
    return false;
  }
  else
  {
    DisplayBitmapInfo(szFileNameIn);
  }

  mNewHeight	= bmih.biHeight/_mlineNum;
  mNewWidth	= bmih.biWidth/_mRowNum;

  //double check valid
  if (!validCheck())
  {
    return false;
  }
  fpIn = fopen( szFileNameIn,"rb");	
  //��ȡ�µ�ͷ����Ϣ
  makeNewFileHeader(mNewHeight,mNewWidth);
  rowBuf = (char *) malloc(mNewWidth * step);
  return true;
}
/************************************************************************/
/* �ϲ��ָ��ͼ��
*/
/************************************************************************/
bool SPLIT::mergeSplit()
{
  int i,j;
  int k = 0;
  int BytesWritten;
  int len = bmfh.bfOffBits - BMP_INFO_HEADER_LEN-BMP_FILE_HEADER_LEN;
  int height = int(pNewHeaderBuf[len-2]);
  int width = int(pNewHeaderBuf[len-1]);
  char inPutFileName[64];
  char outPutFileName[64];

  long offset = bmfh.bfOffBits;

  char tszFileName[1024];
  char tmpszFileName[1024];
  sprintf(tszFileName,"%s",szFileName);
  sprintf(tmpszFileName,"%s",szFileName);
  returnFileName(tszFileName,'_');
  returnFirstFileName(tmpszFileName,'_');
  returnFirstFileName(tmpszFileName,'_');

  //�µ�λͼ��Ϣ
  bmihOut.biHeight=bmihOut.biHeight * height;
  bmihOut.biWidth= bmihOut.biWidth * width;
  int bytePad = 0;
  if((bmihOut.biWidth * step) % 4 != 0)
  {
    bytePad = (4 - ((bmihOut.biWidth * step) % 4)) * bmihOut.biHeight;
  }
  bmihOut.biSizeImage=bmihOut.biHeight * bmihOut.biWidth * step + bytePad;
  bmfhOut.bfOffBits = bmfh.bfOffBits - 3;
  //�µ��ļ���Ϣ
  //bmfhOut
  printf("---->%d\n",sizeof(BMIH));

  if(bmfhOut.bfSize)
    bmfhOut.bfSize =bmihOut.biSizeImage+bmfh.bfOffBits - 3;
  FILE **fp;
  FILE *fpout;
  fp = new FILE* [width];

  if(method%3 == 0)
  {
    sprintf(outPutFileName,"%s//Merge//%s",tszFileName,tmpszFileName);
  }
  else if(method%3 == 1)
  {
    if(rgb_pic == 1)
    {
      sprintf(outPutFileName,"%s//Merge//rgb//%s",tszFileName,tmpszFileName);
    }
    else
    {
      sprintf(outPutFileName,"%s//Merge//%s",tszFileName,tmpszFileName);
    }
  }
  else
  {
    if(gray_pic == 1)
    {
      sprintf(outPutFileName,"%s//Merge//gray//%s",tszFileName,tmpszFileName);
    }
    else if(rgb_pic == 1)
    {
      sprintf(outPutFileName,"%s//Merge//rgb//%s",tszFileName,tmpszFileName);
    }
    else
    {
      sprintf(outPutFileName,"%s//Merge//%s",tszFileName,tmpszFileName);
    }
  }
  //	sprintf(outPutFileName,"%s//Merge//%s",tszFileName,tszFileName);
  fpout = fopen(outPutFileName,"wb");
  rowBuf = (char *) malloc(bmih.biWidth * step);
  writeNewFileHeader(fpout);
  for(i=height - 1; i >= 0; i--)
  {
    offset = bmfh.bfOffBits;
    k = 0;
    for(j=0; j < width; j++)
    {
      formatFileName(i,j);
      if(method%3 == 2)
      {
        sprintf(inPutFileName,"%s//split//split//L%s_C%s_%s",tszFileName,chLine,chRow,tmpszFileName);
      }
      else
      {
        if(method == 1)
        {
          if(gray_pic == 1)
          {
            sprintf(inPutFileName,"%s//Merge//split//L%s_C%s_%s",tszFileName,chLine,chRow,tmpszFileName);
          }
          else
          {
            sprintf(inPutFileName,"%s//split//split//L%s_C%s_%s",tszFileName,chLine,chRow,tmpszFileName);
          }
        }
        if(method == 0)
        {
          if(rgb_pic == 1 || gray_pic == 1)
          {
            sprintf(inPutFileName,"%s//Merge//split//L%s_C%s_%s",tszFileName,chLine,chRow,tmpszFileName);
          }
          else
          {
            sprintf(inPutFileName,"%s//split//split//L%s_C%s_%s",tszFileName,chLine,chRow,tmpszFileName);
          }
        }
        //	sprintf(inPutFileName,"%s//split//split//L%s_R%s_%s",tszFileName,chLine,chRow,tszFileName);
      }

      fp[k++] = fopen(inPutFileName,"rb");
      fseek(fp[k-1],offset,SEEK_SET);
    }
    char word[4] = {'\0'};
    //�ϲ�ͼ��
    for (int j = 0; j < bmih.biHeight; ++j)
    {
      for(k=0; k<width; k++)
      {
        safeReadDataFromFile(0,rowBuf,bmih.biWidth * step,1,fp[k]);
        fwrite( (char*) (rowBuf),1,bmih.biWidth * step, fpout);
      }
      if((bmih.biWidth * step) % 4 != 0)//���ֽڲ���
      {
         for(k=0; k<width; k++)
         {
           fseek(fp[k],4 - ((bmih.biWidth * step) % 4),SEEK_CUR);
         }
      }
      if((bmihOut.biWidth * step) % 4 !=0)
      {
        fwrite( (char*) (word),1,4 - ((bmihOut.biWidth * step) % 4), fpout);
      }
    }
    for(int j = 0; j < width; ++j)
    {
      fclose(fp[j]);
    }
  }

  delete []rowBuf;
  rowBuf = NULL;
  delete []fp;
  fclose(fpout);
  //cout << "�ϲ��ָ��ͼ�� Complete " << outPutFileName << "!" << endl;
  //cout << "--------------------------------------" << endl;
  //DisplayBitmapInfo(outPutFileName);
  return true;
}
/************************************************************************/
/* ���ո����ϲ������ϲ��ָ��ͼ��
*/
/************************************************************************/
bool SPLIT::mergeSplit(int top,int left,int down,int right)
{
  int i,j;
  int k = 0;
  int BytesWritten;
  int len = bmfh.bfOffBits - BMP_INFO_HEADER_LEN-BMP_FILE_HEADER_LEN;
  int height = int(pNewHeaderBuf[len-2]);
  int width = int(pNewHeaderBuf[len-1]);
  if(top >= height || left >= width)
  {
    return false;
  }
  if(down >= height)
  {
    down = height - 1;
  }
  if(right >= width)
  {
    right = width - 1;
  }
  char inPutFileName[1024];
  char outPutFileName[1024];

  long offset = bmfh.bfOffBits;

  char tszFileName[1024];
  char tmpszFileName[1024];
  sprintf(tszFileName,"%s",szFileName);
  sprintf(tmpszFileName,"%s",szFileName);
  returnFileName(tszFileName,'_');
  returnFirstFileName(tmpszFileName,'_');
  returnFirstFileName(tmpszFileName,'_');

  //�µ�λͼ��Ϣ
  bmihOut.biHeight=bmihOut.biHeight * (down - top + 1);
  bmihOut.biWidth= bmihOut.biWidth * (right - left + 1);
  int bytePad = 0;
  if((bmihOut.biWidth * step) % 4 != 0)
  {
    bytePad = (4 - (bmihOut.biWidth * step) % 4) * bmihOut.biHeight;
  }
  bmihOut.biSizeImage=bmihOut.biHeight * bmihOut.biWidth * step + bytePad;
  bmfhOut.bfOffBits = bmfh.bfOffBits - 3;
  //�µ��ļ���Ϣ
  //bmfhOut
  printf("---->%d\n",sizeof(BMIH));

  if(bmfhOut.bfSize)
    bmfhOut.bfSize = bmihOut.biSizeImage+bmfh.bfOffBits - 3;
  FILE **fp;
  FILE *fpout;
  fp = new FILE* [right - left + 1];

  if(method%3 == 0)
  {
    sprintf(outPutFileName,"%s//Merge//%s",tszFileName,tmpszFileName);
  }
  else if(method%3 == 1)
  {
    if(rgb_pic == 1)
    {
      sprintf(outPutFileName,"%s//Merge//rgb//%s",tszFileName,tmpszFileName);
    }
    else
    {
      sprintf(outPutFileName,"%s//Merge//%s",tszFileName,tmpszFileName);
    }
  }
  else
  {
    if(gray_pic == 1)
    {
      sprintf(outPutFileName,"%s//Merge//gray//%s",tszFileName,tmpszFileName);
    }
    else if(rgb_pic == 1)
    {
      sprintf(outPutFileName,"%s//Merge//rgb//%s",tszFileName,tmpszFileName);
    }
    else
    {
      sprintf(outPutFileName,"%s//Merge//%s",tszFileName,tmpszFileName);
    }
  }
  fpout = fopen(outPutFileName,"wb");
  rowBuf = (char *) malloc(bmih.biWidth * step);
  writeNewFileHeader(fpout);
  for(i=down; i >= top; i--)
  {
    offset = bmfh.bfOffBits;
    k = 0;
    for(j=left; j <= right; j++)
    {
      formatFileName(i,j);
      if(method%3 == 2)
      {
        sprintf(inPutFileName,"%s//split//split//L%s_C%s_%s",tszFileName,chLine,chRow,tmpszFileName);
      }
      else
      {
        if(method == 1)
        {
          if(gray_pic == 1)
          {
            sprintf(inPutFileName,"%s//Merge//split//L%s_C%s_%s",tszFileName,chLine,chRow,tmpszFileName);
          }
          else
          {
            sprintf(inPutFileName,"%s//split//split//L%s_C%s_%s",tszFileName,chLine,chRow,tmpszFileName);
          }
        }
        if(method == 0)
        {
          if(rgb_pic == 1 || gray_pic == 1)
          {
            sprintf(inPutFileName,"%s//Merge//split//L%s_C%s_%s",tszFileName,chLine,chRow,tmpszFileName);
          }
          else
          {
            sprintf(inPutFileName,"%s//split//split//L%s_C%s_%s",tszFileName,chLine,chRow,tmpszFileName);
          }
        }
      }

      fp[k++] = fopen(inPutFileName,"rb");
      fseek(fp[k-1],offset,SEEK_SET);
    }
    //�ϲ�ͼ��
    char word[4] = {'\0'};
    int _rf_data = right - left;//  [2011/08/25 10:24 fox]����ô?
    for (ebmpWORD j = 0; j < bmih.biHeight; ++j)
    {
      for(k=0; k <= _rf_data; k++)
      {
        safeReadDataFromFile(0,rowBuf,bmih.biWidth *step,1,fp[k]);
        fwrite( (char*) (rowBuf),1,bmih.biWidth *step, fpout);
      }
      if((bmih.biWidth * step) % 4 != 0)
      {
        for(k=0; k<=_rf_data; k++)
        {
          fseek(fp[k],4 - ((bmih.biWidth * step) % 4),SEEK_CUR);
        }
      }
      if((bmihOut.biWidth * step) % 4 !=0)
      {
        fwrite( (char*) (word),1,4 - (bmihOut.biWidth * step) % 4, fpout);
      }
    }

    for(int j = 0; j <= _rf_data ; ++j)
    {
      fclose(fp[j]);
    }
  }

  delete []rowBuf;
  rowBuf = NULL;
  delete []fp;
  fclose(fpout);
  //cout << "�ϲ��ָ��ͼ�� Complete " << outPutFileName << "!" << endl;
  //cout << "--------------------------------------" << endl;
  //DisplayBitmapInfo(outPutFileName);
  return true;
}
/************************************************************************/
/* �ϲ�RGBͨ��
*/
/************************************************************************/
bool SPLIT::mergeRGB()
{
  bmfhOut.bfOffBits = bmfh.bfOffBits - 2;
  if(bmfhOut.bfSize)
    bmfhOut.bfSize = bmfhOut.bfSize - 2;
  long offset = bmfh.bfOffBits;

  //�����ļ�����
  char tszFileName[1024];
  sprintf(tszFileName,"%s",szFileName);
  returnFileName(tszFileName,'_');
  char tmpszFileName[1024];
  sprintf(tmpszFileName,"%s",szFileName);
  returnFirstFileName(tmpszFileName,'_');

  char inPutFileName_r[64];
  char inPutFileName_g[64];
  char inPutFileName_b[64];
  char outPutFileName_rgb[64];
  unsigned char r[4];
  unsigned char g[4];
  unsigned char b[4];
  // 
  //  		sprintf(inPutFileName_r,"%s//split//rgb//R_%s",tszFileName,tmpszFileName);
  //  		sprintf(inPutFileName_g,"%s//split//rgb//G_%s",tszFileName,tmpszFileName);
  //  		sprintf(inPutFileName_b,"%s//split//rgb//B_%s",tszFileName,tmpszFileName);
  if(method == 0)
  {
    if(gray_pic == 1)
    {
      sprintf(inPutFileName_r,"%s//Merge//rgb//R_%s",tszFileName,tmpszFileName);
      sprintf(inPutFileName_g,"%s//Merge//rgb//G_%s",tszFileName,tmpszFileName);
      sprintf(inPutFileName_b,"%s//Merge//rgb//B_%s",tszFileName,tmpszFileName);
    }else
    {
      sprintf(inPutFileName_r,"%s//split//rgb//R_%s",tszFileName,tmpszFileName);
      sprintf(inPutFileName_g,"%s//split//rgb//G_%s",tszFileName,tmpszFileName);
      sprintf(inPutFileName_b,"%s//split//rgb//B_%s",tszFileName,tmpszFileName);
    }
  }
  if(method == 1 || method == 2)
  {
    if(gray_pic == 1 || split_pic == 1)
    {
      sprintf(inPutFileName_r,"%s//Merge//rgb//R_%s",tszFileName,tmpszFileName);
      sprintf(inPutFileName_g,"%s//Merge//rgb//G_%s",tszFileName,tmpszFileName);
      sprintf(inPutFileName_b,"%s//Merge//rgb//B_%s",tszFileName,tmpszFileName);
    }
    else
    {
      sprintf(inPutFileName_r,"%s//split//rgb//R_%s",tszFileName,tmpszFileName);
      sprintf(inPutFileName_g,"%s//split//rgb//G_%s",tszFileName,tmpszFileName);
      sprintf(inPutFileName_b,"%s//split//rgb//B_%s",tszFileName,tmpszFileName);
    }
  }
  if(method%3 == 0)
  {
    if(split_pic == 1)
    {
      sprintf(outPutFileName_rgb,"%s//Merge//split//%s",tszFileName,tmpszFileName);
    }
    else
    {
      sprintf(outPutFileName_rgb,"%s//Merge//%s",tszFileName,tszFileName);
    }
  }
  else if(method%3 !=0)
  {
    sprintf(outPutFileName_rgb,"%s//Merge//%s",tszFileName,tszFileName);
  }
  FILE *fp_inr = fopen( inPutFileName_r,"rb");
  FILE *fp_ing = fopen( inPutFileName_g,"rb");
  FILE *fp_inb = fopen( inPutFileName_b,"rb");
  fseek(fp_inr,offset,SEEK_SET);
  fseek(fp_ing,offset,SEEK_SET);
  fseek(fp_inb,offset,SEEK_SET);
  FILE *fp_outrgb = fopen( outPutFileName_rgb,"wb");
  writeNewFileHeader(fp_outrgb);

  //Raw Data
  //int _area = bmih.biHeight * bmih.biWidth;// ѭ��ǰ�ȼ��������,����ѭ�����ظ����� [2011/08/25 10:29 fox]
  char word[4] = {'\0'};
  int height  = bmih.biHeight;
  int width = bmih.biWidth;
  for (int i = 0; i < height; ++i)
  {
    for(int j = 0; j < width; ++j)
    {
      safeReadDataFromFile(0, (char*)b, step, 1, fp_inb);
      safeReadDataFromFile(0, (char*)g, step, 1, fp_ing);
      safeReadDataFromFile(0, (char *)r, step, 1, fp_inr);
      b[1] = g[1];
      b[2] = r[2];
      fwrite((char*)(b), 1, step, fp_outrgb);
    }
    if((width * step % 4) != 0)
    {
      fseek(fp_inb,4 - ((width * step) % 4),SEEK_CUR);
      fseek(fp_ing,4 - ((width * step) % 4),SEEK_CUR);
      fseek(fp_inr,4 - ((width * step) % 4),SEEK_CUR);
    }
    if((bmihOut.biWidth * step % 4) != 0)
    {
      fwrite( (char*) (word),1,4 - ((bmihOut.biWidth * step) % 4), fp_outrgb);
    }
  }
  fclose(fp_inr);
  fclose(fp_ing);
  fclose(fp_inb);
  fclose(fp_outrgb);
  //cout << "RGB ͨ���ϲ� Complete " << outPutFileName_rgb << "!" << endl;
  //cout << "--------------------------------------" << endl;
  //DisplayBitmapInfo(outPutFileName_rgb);
  return true;
}
/************************************************************************/
/* ���ո�����ͨ���ϲ�
*/
/************************************************************************/
bool SPLIT::mergeRGB(const char* channel)
{
  bmfhOut.bfOffBits = bmfh.bfOffBits - 2;
  if(bmfhOut.bfSize)
    bmfhOut.bfSize = bmfhOut.bfSize - 2;
  long offset = bmfh.bfOffBits;

  //�����ļ�����
  char tszFileName[1024];
  sprintf(tszFileName,"%s",szFileName);
  returnFileName(tszFileName,'_');
  char tmpszFileName[1024];
  sprintf(tmpszFileName,"%s",szFileName);
  returnFirstFileName(tmpszFileName,'_');

  char inPutFileName_r[64];
  char inPutFileName_g[64];
  char inPutFileName_b[64];
  char outPutFileName_rgb[64];
  unsigned char r[4];
  unsigned char g[4];
  unsigned char b[4];
  FILE *fp_inr;
  FILE *fp_ing;
  FILE *fp_inb;
  if(!strcmp(channel,"R"))
  {
    if(method == 0)
    {
      if(gray_pic == 1)
      {
        sprintf(inPutFileName_r,"%s//Merge//rgb//R_%s",tszFileName,tmpszFileName);
      }
      else
      {
        sprintf(inPutFileName_r,"%s//split//rgb//R_%s",tszFileName,tmpszFileName);
      }
    }
    else
    {
      if(gray_pic == 1 || split_pic == 1)
      {
        sprintf(inPutFileName_r,"%s//Merge//rgb//R_%s",tszFileName,tmpszFileName);
      }
      else
      {
        sprintf(inPutFileName_r,"%s//split//rgb//R_%s",tszFileName,tmpszFileName);
      }
    }
    fp_inr = fopen( inPutFileName_r,"rb");
    fseek(fp_inr,offset,SEEK_SET);
  }
  else if(!strcmp(channel,"G"))
  {
    if(method == 0)
    {
      if(gray_pic == 1)
      {
        sprintf(inPutFileName_g,"%s//Merge//rgb//G_%s",tszFileName,tmpszFileName);
      }
      else
      {
        sprintf(inPutFileName_g,"%s//split//rgb//G_%s",tszFileName,tmpszFileName);
      }
    }
    else
    {
      if(gray_pic == 1 || split_pic == 1)
      {
        sprintf(inPutFileName_g,"%s//Merge//rgb//G_%s",tszFileName,tmpszFileName);
      }
      else
      {
        sprintf(inPutFileName_g,"%s//split//rgb//G_%s",tszFileName,tmpszFileName);
      }
    }
    fp_ing = fopen( inPutFileName_g,"rb");
    fseek(fp_ing,offset,SEEK_SET);
  }
  else if(!strcmp(channel,"B"))
  {
    if(method == 0)
    {
      if(gray_pic == 1)
      {
        sprintf(inPutFileName_b,"%s//Merge//rgb//B_%s",tszFileName,tmpszFileName);
      }
      else
      {
        sprintf(inPutFileName_b,"%s//split//rgb//B_%s",tszFileName,tmpszFileName);
      }
    }
    else
    {
      if(gray_pic == 1 || split_pic == 1)
      {
        sprintf(inPutFileName_b,"%s//Merge//rgb//B_%s",tszFileName,tmpszFileName);
      }
      else
      {
        sprintf(inPutFileName_b,"%s//split//rgb//B_%s",tszFileName,tmpszFileName);
      }
    }
    fp_inb = fopen( inPutFileName_b,"rb");
    fseek(fp_inb,offset,SEEK_SET);
  }
  else if(!strcmp(channel,"RGB"))
  {
    if(method == 0)
    {
      if(gray_pic == 1)
      {
        sprintf(inPutFileName_r,"%s//Merge//rgb//R_%s",tszFileName,tmpszFileName);
        sprintf(inPutFileName_g,"%s//Merge//rgb//G_%s",tszFileName,tmpszFileName);
        sprintf(inPutFileName_b,"%s//Merge//rgb//B_%s",tszFileName,tmpszFileName);
      }
      else
      {
        sprintf(inPutFileName_r,"%s//split//rgb//R_%s",tszFileName,tmpszFileName);
        sprintf(inPutFileName_g,"%s//split//rgb//G_%s",tszFileName,tmpszFileName);
        sprintf(inPutFileName_b,"%s//split//rgb//B_%s",tszFileName,tmpszFileName);
      }
    }
    else
    {
      if(gray_pic == 1 || split_pic == 1)
      {
        sprintf(inPutFileName_r,"%s//Merge//rgb//R_%s",tszFileName,tmpszFileName);
        sprintf(inPutFileName_g,"%s//Merge//rgb//G_%s",tszFileName,tmpszFileName);
        sprintf(inPutFileName_b,"%s//Merge//rgb//B_%s",tszFileName,tmpszFileName);
      }
      else
      {
        sprintf(inPutFileName_r,"%s//split//rgb//R_%s",tszFileName,tmpszFileName);
        sprintf(inPutFileName_g,"%s//split//rgb//G_%s",tszFileName,tmpszFileName);
        sprintf(inPutFileName_b,"%s//split//rgb//B_%s",tszFileName,tmpszFileName);
      }
    }
    fp_inr = fopen( inPutFileName_r,"rb");
    fp_ing = fopen( inPutFileName_g,"rb");
    fp_inb = fopen( inPutFileName_b,"rb");
    fseek(fp_inr,offset,SEEK_SET);
    fseek(fp_ing,offset,SEEK_SET);
    fseek(fp_inb,offset,SEEK_SET);
  }

  if(method%3 == 0)
  {
    if(split_pic == 1)
    {
      sprintf(outPutFileName_rgb,"%s//Merge//split//%s",tszFileName,tmpszFileName);
    }
    else
    {
      sprintf(outPutFileName_rgb,"%s//Merge//%s",tszFileName,tszFileName);
    }
  }
  else if(method%3 !=0)
  {
    sprintf(outPutFileName_rgb,"%s//Merge//%s",tszFileName,tszFileName);
  }

  FILE *fp_outrgb = fopen( outPutFileName_rgb,"wb");
  writeNewFileHeader(fp_outrgb);

  //Raw Data
  //int _area = bmih.biHeight * bmih.biWidth;
  char word[4] = {'\0'};
  int height = bmih.biHeight;
  int width = bmih.biWidth;
  for (int i = 0;i < height;i++)
  {
    for(int j =0;j < width; j++)
    {
      if(!strcmp(channel,"RGB"))
      {
        safeReadDataFromFile(0,(char *)b,step,1,fp_inb);
        safeReadDataFromFile(0,(char *)g,step,1,fp_ing);
        safeReadDataFromFile(0,(char *)r,step,1,fp_inr);
        b[1] = g[1];
        b[2] = r[2];
      }
      else if(!strcmp(channel,"R"))
      {
        safeReadDataFromFile(0,(char *)b,step,1,fp_inr);
      }
      else if(!strcmp(channel,"G"))
      {
        safeReadDataFromFile(0,(char *)b,step,1,fp_ing);
      }
      else if(!strcmp(channel,"B"))
      {
        safeReadDataFromFile(0,(char *)b,step,1,fp_inb);
      }
      fwrite( (char*) (&b),1,step, fp_outrgb);
    }
    if((width * step % 4) != 0)
    {
      if(!strcmp(channel,"B"))
      {
         fseek(fp_inb,4 - ((width * step) % 4),SEEK_CUR);
      }
      if(!strcmp(channel,"G"))
      {
         fseek(fp_ing,4 - ((width * step) % 4),SEEK_CUR);
      }
      if(!strcmp(channel,"R"))
      {
        fseek(fp_inr,4 - ((width * step) % 4),SEEK_CUR);
      }
      if(!strcmp(channel,"RGB"))
      {
        fseek(fp_inr,4 - ((width * step) % 4),SEEK_CUR);
        fseek(fp_ing,4 - ((width * step) % 4),SEEK_CUR);
        fseek(fp_inb,4 - ((width * step) % 4),SEEK_CUR);
      }
      fwrite( (char*) (word),1,4 - ((width * step) % 4), fp_outrgb);
    }
  }
 
  if(!strcmp(channel,"B"))
  {
    fclose(fp_inb);
  }
  else if(!strcmp(channel,"G"))
  {
    fclose(fp_ing);
  }
  else if(!strcmp(channel,"R"))
  {
    fclose(fp_inr);
  }
  else if(!strcmp(channel,"RGB"))
  {
    fclose(fp_inr);
    fclose(fp_ing);
    fclose(fp_inb);
  }

  fclose(fp_outrgb);
  //cout << "RGB ͨ���ϲ� Complete " << outPutFileName_rgb << "!" << endl;
  //cout << "--------------------------------------" << endl;
  //DisplayBitmapInfo(outPutFileName_rgb);
  return true;
}
/************************************************************************/
/* ���ҶȽ����ϲ�ͼ��
*/
/************************************************************************/
bool SPLIT::mergeGray()
{
  int len=bmfh.bfOffBits - BMP_INFO_HEADER_LEN-BMP_FILE_HEADER_LEN;
  int n = int(pNewHeaderBuf[len-1]);
  int level = IntPow(2,n);
  bmfhOut.bfOffBits = bmfh.bfOffBits - 2;
  if(bmfhOut.bfSize)
    bmfhOut.bfSize = bmfhOut.bfSize - 2;
  long offset = bmfh.bfOffBits;

  //�����ļ�����
  char tszFileName[1024];//��ȡ���ͼ����ļ���
  sprintf(tszFileName,"%s",szFileName);
  returnFileName(tszFileName,'_');
  char tmpszFileName[1024];
  sprintf(tmpszFileName,"%s",szFileName);
  returnFirstFileName(tmpszFileName,'_');

  char inPutFileName[64];
  char outPutFileName[64];
  FILE **fp;//�����ļ����
  FILE *fpout;//����ļ����
  fp = new FILE* [level];
   unsigned char rgb[4];
  unsigned char trgb[4];
  for(int i = 0; i < level; ++i)
  {
    //sprintf(inPutFileName,"%s//split//gray//%c//%d_%s",tszFileName,tmpszFileName[0],i,tmpszFileName);
    if(method%3 != 2)
    {
      sprintf(inPutFileName,"%s//split//gray//%d_%s",tszFileName,i,tmpszFileName);
    }
    else if(method%3 == 2)
    {
      if(split_pic == 1)
      {
        sprintf(inPutFileName,"%s//Merge//gray//%d_%s",tszFileName,i,tmpszFileName);
      }
      else
      {
        sprintf(inPutFileName,"%s//split//gray//%d_%s",tszFileName,i,tmpszFileName);
      }
    }
    fp[i] = fopen( inPutFileName,"rb");
    fseek(fp[i],offset,SEEK_SET);
  }
  if(method%3 != 1)
  {
    sprintf(outPutFileName,"%s//Merge//rgb//%s",tszFileName,tmpszFileName);
  }
  else if(method%3 == 1)
  {
    if(split_pic == 1)
    {
      sprintf(outPutFileName,"%s//Merge//split//%s",tszFileName,tmpszFileName);
    }
    else
    {
      sprintf(outPutFileName,"%s//Merge//rgb//%s",tszFileName,tmpszFileName);
    }

  }
  //	sprintf(outPutFileName,"%s//Merge//rgb//%s",tszFileName,tmpszFileName);
  fpout = fopen(outPutFileName,"wb");
  writeNewFileHeader(fpout);

  //Raw Data
  //int _area = bmih.biHeight * bmih.biWidth;
  char word[4] = {'\0'};
  int height = bmih.biHeight;
  int width = bmih.biWidth;
  for (int i = 0;i < height;i++)
  {
    for(int k = 0; k < width; ++k)
    {
      trgb[0] = trgb[1] = trgb[2] = trgb[3] ='\0';
      for(int j=0; j < level; j++)
      {
        safeReadDataFromFile(0,(char*)rgb,step,1,fp[j]);
        if(trgb[0] + rgb[0] >255)
        {
          trgb[0] = 255;
        }
        else
        {
          trgb[0] = trgb[0] + rgb[0];
        }

        if(trgb[1] + rgb[1] >255)
        {
          trgb[1] = 255;
        }
        else
        {
          trgb[1] = trgb[1] + rgb[1];
        }

        if(trgb[2] + rgb[2] >255)
        {
          trgb[2] = 255;
        }
        else
        {
          trgb[2] = trgb[2] + rgb[2];
        }

      }
      trgb[3] = rgb[3];
      fwrite( (char*) (trgb),1,step, fpout);
    }
    if((width * step % 4) != 0)
    {
      for(int j = 0; j < level; j++)
      {
        fseek(fp[j],4 - ((width * step) % 4),SEEK_CUR);
      }
      fwrite( (char*) (word),1,4 - ((width * step) % 4), fpout);
    }
  }
  

  for(int i = 0; i < level; i++)
  {
    fclose(fp[i]);
  }
  fclose(fpout);
  delete []fp;
  //cout << "�ҶȽ׺ϲ� Complete !" << endl;
  //cout << "--------------------------------------" << endl;
  //cout <<"�ҶȽ׺ϲ����ļ�����Ϣ:"<<endl;
  //DisplayBitmapInfo(outPutFileName);
  return true;
}
/************************************************************************/
/* ���ո����ĻҶȽ׵����޺����� �ϲ�
down���ޣ�up����
*/
/************************************************************************/
bool SPLIT::mergeGray(int down,int up)
{
  int len=bmfh.bfOffBits - BMP_INFO_HEADER_LEN-BMP_FILE_HEADER_LEN;
  int n = int(pNewHeaderBuf[len-1]);
  int level = IntPow(2,n);
  if(down >= up || down >= level)
  {
    return false;
  }
  else if(up > level)
  {
    up = level;
  }
  int levelDown = down;
  int levelUp = up;
  bmfhOut.bfOffBits = bmfh.bfOffBits - 2;
  if(bmfhOut.bfSize)
    bmfhOut.bfSize = bmfhOut.bfSize - 2;
  long offset = bmfh.bfOffBits;
  //�����ļ�����
  char tszFileName[1024];//��ȡ���ͼ����ļ���
  sprintf(tszFileName,"%s",szFileName);
  returnFileName(tszFileName,'_');
  char tmpszFileName[1024];
  sprintf(tmpszFileName,"%s",szFileName);
  returnFirstFileName(tmpszFileName,'_');

  char inPutFileName[64];
  char outPutFileName[64];
  FILE **fp;//�����ļ����
  FILE *fpout;//����ļ����
  fp = new FILE* [levelUp - levelDown];
  unsigned char rgb[4];
  unsigned char trgb[4];
  for(int i = 0; i < levelUp - levelDown; ++i)
  {
    //sprintf(inPutFileName,"%s//split//gray//%c//%d_%s",tszFileName,tmpszFileName[0],i,tmpszFileName);
    if(method%3 != 2)
    {
      sprintf(inPutFileName,"%s//split//gray//%d_%s",tszFileName,i,tmpszFileName);
    }
    else if(method%3 == 2)
    {
      if(split_pic == 1)
      {
        sprintf(inPutFileName,"%s//Merge//gray//%d_%s",tszFileName,i,tmpszFileName);
      }
      else
      {
        sprintf(inPutFileName,"%s//split//gray//%d_%s",tszFileName,i,tmpszFileName);
      }
    }
    fp[i] = fopen( inPutFileName,"rb");
    fseek(fp[i],offset,SEEK_SET);
  }
  if(method%3 != 1)
  {
    sprintf(outPutFileName,"%s//Merge//rgb//%s",tszFileName,tmpszFileName);
  }
  else if(method%3 == 1)
  {
    if(split_pic == 1)
    {
      sprintf(outPutFileName,"%s//Merge//split//%s",tszFileName,tmpszFileName);
    }
    else
    {
      sprintf(outPutFileName,"%s//Merge//rgb//%s",tszFileName,tmpszFileName);
    }
  }
  //	sprintf(outPutFileName,"%s//Merge//rgb//%s",tszFileName,tmpszFileName);
  fpout = fopen(outPutFileName,"wb");
  writeNewFileHeader(fpout);

  //Raw Data
 // int _area = bmih.biHeight * bmih.biWidth;
  char word[4] = {'\0'};
  int height = bmih.biHeight;
  int width = bmih.biWidth;
  for (int i = 0;i < height;i++)
  {
    for(int k = 0; k < width; k++)
    {
        trgb[0] = trgb[1] = trgb[2] = trgb[3] ='\0';
        for(int j=0; j < levelUp - levelDown; j++)
        {
          safeReadDataFromFile(0,(char*)rgb,step,1,fp[j]);
          if(trgb[0] + rgb[0] >255)
          {
            trgb[0] = 255;
          }
          else
          {
            trgb[0] = trgb[0] + rgb[0];
          }

          if(trgb[1] + rgb[1] >255)
          {
            trgb[1] = 255;
          }
          else
          {
            trgb[1] = trgb[1] + rgb[1];
          }

          if(trgb[2] + rgb[2] >255)
          {
            trgb[2] = 255;
          }
          else
          {
            trgb[2] = trgb[2] + rgb[2];
          }
      }
      trgb[3] = rgb[3];
      fwrite( (char*) (trgb),1,step, fpout);
   }
    if((width * step % 4) != 0)
    {
      for(int j = 0; j < levelUp - levelDown; j++)
      {
        fseek(fp[j],4 - ((width * step) % 4),SEEK_CUR);
      }
      fwrite( (char*) (word),1,4 - ((width * step) % 4), fpout);
    }
  }

  for(int i = 0; i < levelUp - levelDown; i++)
  {
    fclose(fp[i]);
  }
  fclose(fpout);
  delete []fp;
  //cout << "�ҶȽ׺ϲ� Complete !" << endl;
  //cout << "--------------------------------------" << endl;
  //cout <<"�ҶȽ׺ϲ����ļ�����Ϣ:"<<endl;
  //DisplayBitmapInfo(outPutFileName);
  return true;
}

bool SPLIT::setMethod(int m)
{
  method = m;
  return true;
}

bool SPLIT::setSplit(int m)
{
  split_pic = m;
  return true;
}

bool SPLIT::setRGB(int m)
{
  rgb_pic = m;
  return true;
}

bool SPLIT::setGray(int m)
{
  gray_pic = m;
  return true;
}

bool SPLIT::setFilePath(const char *pSzFileNameIn)
{
  sprintf(szFileNameIn,"%s",pSzFileNameIn);
  sprintf(szFileName,"%s",pSzFileNameIn);
  sprintf(szFileName,"%s",returnFileName(szFileName,'/'));
  return true;
}

bool SPLIT::validCheck()
{
  if (!strlen(szFileNameIn))
  {
    //��Ҫ���Ӷ��ļ��Ϸ���check����
    return false;
  }
  return true;
}

bool SPLIT::safeReadDataFromFile( int offset, char* buffer, int size, int number, FILE* fp )
{
  //using namespace std;
  //int ItemsRead;
  //if( feof(fp) )
  //{ return false; }
  if(offset != 0)
  {
      fseek(fp,offset,SEEK_SET);
  }
  /*ItemsRead = (int) */fread( buffer , size , number , fp );
  //if( ItemsRead < number )
  //{ return false; }
  return true;
}

BMIH SPLIT::getBMIH(const char *pSzFileNameIn)
{
  BMIH tbmih;
  tbmih = bmihOut =GetBMIH(pSzFileNameIn);
  return tbmih;
}

BMFH SPLIT::getBMFH(const char *pSzFileNameIn)
{
  BMFH tbmfh;
  tbmfh = bmfhOut =GetBMFH(pSzFileNameIn);
  return tbmfh;
}

bool SPLIT::getFileHeader()
{
  int len=bmfh.bfOffBits - BMP_INFO_HEADER_LEN-BMP_FILE_HEADER_LEN;
  pNewHeaderBuf=(char *)malloc(bmfh.bfOffBits + 2);
  //��ȡͷ��������Ϣ	
  safeReadDataFromFile(BMP_INFO_HEADER_LEN+BMP_FILE_HEADER_LEN,pNewHeaderBuf,len,1,fpIn);

  if(bmihOut.biBitCount >= 24)//�ж�ɫ��λ��
  {
    step = bmihOut.biBitCount / 8;
  }
  else
  {
    step = 1;
  }
  return true;
}

bool SPLIT::makeNewFileHeader(int _mHeight,int _mWidth)
{
  if(bmihOut.biBitCount >= 24)//�ж�ɫ��λ��
  {
    step = bmihOut.biBitCount / 8;
  }
  else
  {
    step = 1;
  }
  int len=bmfh.bfOffBits - BMP_INFO_HEADER_LEN-BMP_FILE_HEADER_LEN;
  pNewHeaderBuf=(char *)malloc(bmfh.bfOffBits + 3);
  //��ȡͷ��������Ϣ	
  safeReadDataFromFile(BMP_INFO_HEADER_LEN+BMP_FILE_HEADER_LEN,pNewHeaderBuf,len,1,fpIn);

  pNewHeaderBuf[len] = 'S';
  pNewHeaderBuf[len + 1] = (char)mLineNum;
  pNewHeaderBuf[len + 2] = (char)mRowNum;
  bmfhOut.bfOffBits = bmfh.bfOffBits + 3;
  bmihOut.biHeight=_mHeight;
  bmihOut.biWidth=_mWidth;
  int bytePad = 0;
  if((bmihOut.biWidth * step) % 4 != 0)
  {
      bytePad = (4 - (bmihOut.biWidth * step) % 4) * bmihOut.biHeight;
  }
  bmihOut.biSizeImage = bmihOut.biWidth * step * bmihOut.biHeight + bytePad;
  //�µ��ļ���Ϣ
  //bmfhOut
  printf("---->%d\n",sizeof(BMIH));

  if(bmfhOut.bfSize)
    bmfhOut.bfSize=bmihOut.biSizeImage+bmfhOut.bfOffBits;
    //bmfhOut.bfSize=(bmfhOut.bfSize - bmfh.bfOffBits)/(mLineNum*mRowNum)+bmfh.bfOffBits + 3;


  return true;
}

void SPLIT::formatFileName(int tline, int trow)//��ʽ���ļ������ֵĸ�ʽ
{
  if(tline < 10000 && tline >= 1000)
  {
    sprintf(chLine,"0%d",tline);
  }
  if(tline < 1000 && tline >= 100)
  {
    sprintf(chLine,"00%d",tline);
  }
  if(tline < 100 && tline >= 10)
  {
    sprintf(chLine,"000%d",tline);
  }
  if(tline < 10)
  {
    sprintf(chLine,"0000%d",tline);
  }

  if(trow < 10000 && trow >= 1000)
  {
    sprintf(chRow,"0%d",trow);
  }
  if(trow < 1000 && trow >= 100)
  {
    sprintf(chRow,"00%d",trow);
  }
  if(trow < 100 && trow >= 10)
  {
    sprintf(chRow,"000%d",trow);
  }
  if(trow < 10)
  {
    sprintf(chRow,"0000%d",trow);
  }
}

bool SPLIT::savePicByR_G_B()//����argbͨ���ֱ�洢
{
  int len=bmfh.bfOffBits - BMP_INFO_HEADER_LEN-BMP_FILE_HEADER_LEN;

  if(step == 1)
  {
    cout <<"bmpͼ����24λ����32λ���ͼ!"<<endl;
    return false;
  }
  else//24λͼ����
  {
    pNewHeaderBuf[len] = 'R';
    pNewHeaderBuf[len + 1] =(char)1;
    bmfhOut.bfOffBits = bmfh.bfOffBits + 2;
    if(bmfhOut.bfSize)
      bmfhOut.bfSize = bmfhOut.bfSize + 2;
    long offset = bmfh.bfOffBits;
    fseek(fpIn,offset,SEEK_SET);
    //�����ļ�����
    char tszFileName[1024];
    sprintf(tszFileName,"%s",szFileName);
    returnFileName(tszFileName,'_');
    char outPutFileName_r[64];
    char outPutFileName_g[64];
    char outPutFileName_b[64];
   
    unsigned char r[4];
    unsigned char g[4];
    unsigned char b[4]; 
    sprintf(outPutFileName_r,"%s//split//rgb//R_%s",tszFileName,szFileName);
    sprintf(outPutFileName_g,"%s//split//rgb//G_%s",tszFileName,szFileName);
    sprintf(outPutFileName_b,"%s//split//rgb//B_%s",tszFileName,szFileName);

    FILE *fp_outr = fopen( outPutFileName_r,"wb");
    FILE *fp_outg = fopen( outPutFileName_g,"wb");
    FILE *fp_outb = fopen( outPutFileName_b,"wb");

    writeNewFileHeader(fp_outr);
    writeNewFileHeader(fp_outg);
    writeNewFileHeader(fp_outb);

    clock_t start = clock();
    char word[4] = {'\0'};
    //Raw Data
  //  int _area = bmih.biHeight * bmih.biWidth;
    int height = bmih.biHeight;
    int width = bmih.biWidth;
    for(int i = 0; i < height; ++i)
    {
      for(int j = 0; j < width; ++j)
      {
        safeReadDataFromFile(0,(char *)b,step,1,fpIn);
        g[0] = r[0]  = b[0];
        g[1] = r[1]  = b[1];
        g[2] = r[2]  = b[2];
        g[3] = r[3]  = b[3];
        b[1] ='\0';
        b[2] ='\0';
        g[0] ='\0';
        g[2] ='\0';
        r[0] ='\0';
        r[1] ='\0';
        fwrite( (char*) (r),1,step, fp_outr);
        fwrite( (char*) (g),1,step, fp_outg);
        fwrite( (char*) (b),1,step, fp_outb);
      }
      if((width * step % 4) != 0)
      {
        fseek(fpIn,4 - ((width * step) % 4),SEEK_CUR);
        fwrite( (char*) (word),1,4 - ((width * step) % 4), fp_outr);
        fwrite( (char*) (word),1,4 - ((width * step) % 4), fp_outg);
        fwrite( (char*) (word),1,4 - ((width * step) % 4), fp_outb);
      }
    }
    clock_t end = clock();
    cout << "RGB ������ʱ:"<<end - start <<"ms"<<endl;

    fclose(fp_outr);
    fclose(fp_outg);
    fclose(fp_outb);
    return true;
  }
}

bool SPLIT::savePicByGray_N(int n)//����rgb�洢�󣬽��лҶȽ׽��д洢 n��ȡֵ��ΧΪ0-8
{
  int level = IntPow(2,n);
  if(level > 256)
  {
    cout <<"��������!"<<endl;
    return false;
  }
  int len=bmfh.bfOffBits - BMP_INFO_HEADER_LEN-BMP_FILE_HEADER_LEN;
  pNewHeaderBuf[len] = 'G';
  pNewHeaderBuf[len + 1] = char(n);
  bmfhOut.bfOffBits = bmfh.bfOffBits + 2;
  if(bmfhOut.bfSize)
    bmfhOut.bfSize = bmfhOut.bfSize + 2;
  int m;
  long offset = bmfh.bfOffBits;
  fseek(fpIn,offset,SEEK_SET);
  //�����ļ�����
  char tszFileName[1024];
  sprintf(tszFileName,"%s",szFileName);
  returnFileName(tszFileName,'_');
  char outPutFileName[64];
  FILE **fp;
  fp = new FILE* [level];
  char rgb[4];

  clock_t start = clock();

  for(int i = 0; i < level; ++i)
  {
    //sprintf(outPutFileName,"%s//split//gray//%c//%d_%s",tszFileName,szFileName[0],i,szFileName);
    sprintf(outPutFileName,"%s//split//gray//%d_%s",tszFileName,i,szFileName);
    fp[i] = fopen( outPutFileName,"wb");
    writeNewFileHeader(fp[i]);
  }
  //Raw Data
 // int _area = bmih.biHeight * bmih.biWidth;
  char word[4] = {'\0'};
  int height = bmih.biHeight;
  int width = bmih.biWidth;
  for (int i = 0; i < height; ++i)
  {
    for(int j = 0; j < width; ++j)
    {
      safeReadDataFromFile(0,rgb,step,1,fpIn);
      if(rgb[0] !='\0')
      {
        m = ((int)((unsigned char)rgb[0])) / (256/level);

      }else if(rgb[1] !='\0')
      {
        m = ((int)((unsigned char)rgb[1])) / (256/level);
      }else if(rgb[2] !='\0')
      {
        m = ((int)((unsigned char)rgb[2])) / (256/level);
      }else
      {
        m = 0;
      }
      fwrite( (char*) (&rgb),1,step, fp[m]);
      rgb[0] = rgb[1] = rgb[2] = '\0';
      for(int j = 0; j < level; j++)
      {
        if(m != j)
        {
          fwrite( (char*) (&rgb),1,step, fp[j]);
        }
      }
    }
    if((width * step % 4) != 0)
    {
      fseek(fpIn,4 - ((width * step) % 4),SEEK_CUR);
      for(int j = 0; j < level; j++)
      {
        fwrite( (char*) (word),1,4 - ((width * step) % 4), fp[j]);
      }
    }
  }
  clock_t end = clock();
  cout << end - start <<"ms"<<endl;
  for(int i = 0; i < level; ++i)
  {
    fclose(fp[i]);
  }
  delete []fp;
  //cout << "�ҶȽ��з� Complete !" << endl;
  //cout << "--------------------------------------" << endl;
  //cout <<"BBͨ���ļ�����Ϣ:"<<endl;
  //DisplayBitmapInfo(outPutFileName);
  return true;
}

bool SPLIT::getGridUnitByStep(int _lineIndex, int mRowIndex)
{
  clock_t start = clock();
  int bytePad = 0;
  if((bmih.biWidth * step) % 4 !=0)
  {
    bytePad = (4 - ((bmih.biWidth * step) % 4)) * _lineIndex  * mNewHeight;
  }
  long offset = _lineIndex * mNewHeight * bmih.biWidth * step + bmfh.bfOffBits + bytePad;
  fseek(fpIn,offset,SEEK_SET);

  //�����ļ�����
  char outPutFileName[64];
  char tszFileName[1024];
  FILE **fp_out;
  fp_out = new FILE*[mRowIndex];
  sprintf(tszFileName,"%s",szFileName);
  returnFileName(tszFileName,'_');
  
  
  for(int index = 0; index < mRowIndex; index++)
  {
    formatFileName(tmLineNum,index);
    sprintf(outPutFileName,"%s//split//split//L%s_C%s_%s",tszFileName,chLine,chRow,szFileName);
    fp_out[index] = fopen( outPutFileName,"wb");
    writeNewFileHeader(fp_out[index]);
  }


  //Raw Data
  clock_t end1 = clock();  
  cout << end1 - start <<"s ";
  char word[4] = {'\0'};
  int size = mNewWidth * step;
  for (int i = 0; i < mNewHeight; ++i)
  {		
    for(int j = 0; j < mRowIndex; j++)
    {
      safeReadDataFromFile(0,rowBuf,size,1,fpIn); 
      fwrite( (char*) (rowBuf),1,size, fp_out[j]);
      if((size % 4) != 0)
      {
        fwrite((char *)word,1,4 - (size%4),fp_out[j]);
      }
    }
    if((bmih.biWidth * step) % 4 != 0)
    {
      fseek(fpIn, 4-((bmih.biWidth * step) % 4),SEEK_CUR);
    }
  }
  clock_t end = clock();
  cout << end -end1 <<" s"<<endl;
  for(int index = 0; index < mRowIndex; index++)
  {
    fclose(fp_out[index]);
  }
  delete []fp_out;
  return true;
}
//bool SPLIT::getGridUnitByStep(int _lineIndex, int _rowIndex)
//{
//  long offset=_lineIndex*mNewHeight*bmih.biWidth *step+_rowIndex*mNewWidth * step+ bmfh.bfOffBits;
//
//  //�����ļ�����
//  char outPutFileName[64];
//  char tszFileName[1024];
//  sprintf(tszFileName,"%s",szFileName);
//  returnFileName(tszFileName,'_');
//  formatFileName(tmLineNum,tmRowNum);
//  //	sprintf(outPutFileName,"output//L%d_R%d_X_X.bmp",_lineIndex,_rowIndex);
//  sprintf(outPutFileName,"%s//split//split//L%s_C%s_%s",tszFileName,chLine,chRow,szFileName);
//  FILE *fp_out = fopen( outPutFileName,"wb");
//
//  writeNewFileHeader(fp_out);
//  //clock_t start = clock();
//  //int sum = 0;
//  //int count = 0;
//  //Raw Data
//  long _delta = bmih.biWidth * step;
//  for (int i = 0; i < mNewHeight; ++i, offset += _delta)
//  {		
//    safeReadDataFromFile(offset,rowBuf,mNewWidth *step,1,fpIn); 
//    int BytesWritten = (int) fwrite( (char*) (rowBuf),1,mNewWidth *step, fp_out);
//  }
//
//  fclose(fp_out);
//  return true;
//}

bool SPLIT::release()
{
  if (pNewHeaderBuf)
  {
    free(pNewHeaderBuf);
    pNewHeaderBuf = NULL;
  }
  if (rowBuf)
  {
    free(rowBuf);
    rowBuf = NULL;
  }
  if (fpIn)
  {
    fclose(fpIn);
    fpIn = NULL;
  }
  return true;
}

bool SPLIT::doSplit()
{
  int lineIndex;	
  tmLineNum = 0;
  tmRowNum = 0;
  clock_t start = clock();
  for (lineIndex=mLineNum-1;lineIndex>=0;lineIndex--)
  {
    getGridUnitByStep(lineIndex,mRowNum);
    tmLineNum++;
  }
  clock_t end = clock();
  cout << "���ηָ���ʱ:" << end - start << "ms"<<endl;
  return true;
}

bool SPLIT::setLineRowNum(int _mLineNum, int _mRowNum)
{
  mLineNum = _mLineNum;
  mRowNum	 = _mRowNum;
  return true;
}

char* SPLIT::returnFileName(char *pathname,char ch)
{
  char tpathname[1024];
  sprintf(tpathname,"%s",pathname);
  sprintf(pathname,"%s",strrchr(pathname,ch));
  if(!strcmp(pathname,"(null)"))
  {
    sprintf(pathname,"%s",tpathname);
  }else
  {
    sprintf(pathname,"%s",pathname + 1);
  }
  return pathname;
}

char* SPLIT::returnFirstFileName(char *filename,char ch)
{
  char tfilename[1024];
  sprintf(tfilename,"%s",filename);
  sprintf(filename,"%s",strchr(filename,ch));
  if(!strcmp(filename,"(null)"))
  {
    sprintf(filename,"%s",tfilename);
  }else
  {
    sprintf(filename,"%s",filename + 1);
  }
  return filename;
}

bool SPLIT::getGridUnitByLine(int /*_lineIndex*/, int /*_rowIndex*/)
{
  return true;
}

bool SPLIT::writeNewFileHeader(FILE *_fp)
{
  //дͷ
  if( IsBigEndian() )
  { 
    bmfhOut.SwitchEndianess(); 
  }
  fwrite( (char*) &(bmfhOut.bfType) , sizeof(ebmpWORD) , 1 , _fp );
  fwrite( (char*) &(bmfhOut.bfSize) , sizeof(ebmpDWORD) , 1 , _fp );
  fwrite( (char*) &(bmfhOut.bfReserved1) , sizeof(ebmpWORD) , 1 , _fp );
  fwrite( (char*) &(bmfhOut.bfReserved2) , sizeof(ebmpWORD) , 1 , _fp );
  fwrite( (char*) &(bmfhOut.bfOffBits) , sizeof(ebmpDWORD) , 1 , _fp );

  if( IsBigEndian() )
  { 
    bmihOut.SwitchEndianess(); 
  }

  fwrite( (char*) &(bmihOut.biSize) , sizeof(ebmpDWORD) , 1 , _fp );
  fwrite( (char*) &(bmihOut.biWidth) , sizeof(ebmpDWORD) , 1 , _fp );
  fwrite( (char*) &(bmihOut.biHeight) , sizeof(ebmpDWORD) , 1 , _fp );
  fwrite( (char*) &(bmihOut.biPlanes) , sizeof(ebmpWORD) , 1 , _fp );
  fwrite( (char*) &(bmihOut.biBitCount) , sizeof(ebmpWORD) , 1 , _fp );
  fwrite( (char*) &(bmihOut.biCompression) , sizeof(ebmpDWORD) , 1 , _fp );
  fwrite( (char*) &(bmihOut.biSizeImage) , sizeof(ebmpDWORD) , 1 , _fp );
  fwrite( (char*) &(bmihOut.biXPelsPerMeter) , sizeof(ebmpDWORD) , 1 , _fp );
  fwrite( (char*) &(bmihOut.biYPelsPerMeter) , sizeof(ebmpDWORD) , 1 , _fp ); 
  fwrite( (char*) &(bmihOut.biClrUsed) , sizeof(ebmpDWORD) , 1 , _fp);
  fwrite( (char*) &(bmihOut.biClrImportant) , sizeof(ebmpDWORD) , 1 , _fp);

  fwrite( (char*) pNewHeaderBuf,1,bmfhOut.bfOffBits - BMP_INFO_HEADER_LEN-BMP_FILE_HEADER_LEN, _fp );
  return true;
}