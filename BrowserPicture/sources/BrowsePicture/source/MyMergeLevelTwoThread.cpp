/**@file
*****************************************************************************
* ��Ȩ����(C) �ߵ�δ��(����)�Ƽ����޹�˾ CopyRight(2011 - ...)
* @brief ����ժҪ:
* @author  Eric 
* @date 2011/08/24
* @note  �޸ļ�¼:
********************************************************************************/
#include "stdafx.h"
#include "MyMergeLevelTwoThread.h"


MyMergeLevelTwoThread::MyMergeLevelTwoThread(void)
{
}


void MyMergeLevelTwoThread::run()
{
    for(int i=0; i < path_list.size(); i++)
    {
      if(dealFlag == 0)//���κϲ�
      {
        if(mSpliter.init(path_list[i].toLatin1().data()))
        {
          mSpliter.mergeSplit(arg.getStartRow(),arg.getStartCol(),arg.getEndRow(),arg.getEndCol());
          mSpliter.release();
        }
      }else if(dealFlag == 1)//rgbͨ���ϲ�
      {
        if(mSpliter.init(path_list[i].toLatin1().data()))
        {
          mSpliter.mergeRGB(arg.getChannel().toLatin1().data());
          mSpliter.release();
        }
      }else if(dealFlag == 2)//gray�ϲ�
      {
        if(mSpliter.init(path_list[i].toLatin1().data()))
        {
          mSpliter.mergeGray(arg.getStartGray(),arg.getEndGray());
          mSpliter.release();
        }
      }
    }
}
void MyMergeLevelTwoThread::setPicPath(const QStringList &pic_path)
{
  this->path_list = pic_path;
}

void MyMergeLevelTwoThread::setSpliter(const SPLIT &m_split)
{
  this->mSpliter = m_split;
}

void MyMergeLevelTwoThread::setDealFlag(int flag)
{
  this->dealFlag = flag;
}
void MyMergeLevelTwoThread::setMergeArg(const MergeArg &arg)
{
  this->arg = arg;
}
MyMergeLevelTwoThread::~MyMergeLevelTwoThread()
{

}