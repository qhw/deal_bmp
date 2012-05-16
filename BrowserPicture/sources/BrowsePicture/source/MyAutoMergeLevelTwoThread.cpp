/**@file
*****************************************************************************
* ��Ȩ����(C) �ߵ�δ��(����)�Ƽ����޹�˾ CopyRight(2011 - ...)
* @brief ����ժҪ:
* @author  Eric 
* @date 2011/08/24
* @note  �޸ļ�¼:
********************************************************************************/
#include "stdafx.h"
#include "MyAutoMergeLevelTwoThread.h"


MyAutoMergeLevelTwoThread::MyAutoMergeLevelTwoThread(void)
{
}


void MyAutoMergeLevelTwoThread::run()
{
    for(int i=0; i < path_list.size(); i++)
    {
      if(dealFlag == 0)//���κϲ�
      {
        if(mSpliter.init(path_list[i].toLatin1().data()))
        {
          mSpliter.mergeSplit();
          mSpliter.release();
        }
      }else if(dealFlag == 1)//rgbͨ���ϲ�
      {
        if(mSpliter.init(path_list[i].toLatin1().data()))
        {
          mSpliter.mergeRGB();
          mSpliter.release();
        }
      }else if(dealFlag == 2)//gray�ϲ�
      {
        if(mSpliter.init(path_list[i].toLatin1().data()))
        {
          mSpliter.mergeGray();
          mSpliter.release();
        }
      }
    }
}
void MyAutoMergeLevelTwoThread::setPicPath(const QStringList &pic_path)
{
  this->path_list = pic_path;
}

void MyAutoMergeLevelTwoThread::setSpliter(const SPLIT &m_split)
{
  this->mSpliter = m_split;
}

void MyAutoMergeLevelTwoThread::setDealFlag(int flag)
{
  this->dealFlag = flag;
}
MyAutoMergeLevelTwoThread::~MyAutoMergeLevelTwoThread()
{

}