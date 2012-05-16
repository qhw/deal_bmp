/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  Eric 
* @date 2011/08/24
* @note  修改记录:
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
      if(dealFlag == 0)//几何合并
      {
        if(mSpliter.init(path_list[i].toLatin1().data()))
        {
          mSpliter.mergeSplit(arg.getStartRow(),arg.getStartCol(),arg.getEndRow(),arg.getEndCol());
          mSpliter.release();
        }
      }else if(dealFlag == 1)//rgb通道合并
      {
        if(mSpliter.init(path_list[i].toLatin1().data()))
        {
          mSpliter.mergeRGB(arg.getChannel().toLatin1().data());
          mSpliter.release();
        }
      }else if(dealFlag == 2)//gray合并
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