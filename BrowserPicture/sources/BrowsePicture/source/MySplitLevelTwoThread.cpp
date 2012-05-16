/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  Eric 
* @date 2011/08/24
* @note  修改记录:
********************************************************************************/
#include "stdafx.h"
#include "MySplitLevelTwoThread.h"
#include <QMutexLocker>

MySplitLevelTwoThread::MySplitLevelTwoThread(void)
{
  dealFlag = 0;
}


void MySplitLevelTwoThread::run()
{
  for(int i = 0; i < path_list.size(); i++)
  {
    if(dealFlag == 0)//切割
    {
        if(mSpliter.init(arg.getSplit_Row(),arg.getSplit_Col(),path_list[i].toLatin1().data()))
        {
          mSpliter.doSplit();
          mSpliter.release();
        }
    }
    else if(dealFlag == 1)//rgb分离
    {
        if(mSpliter.init(path_list[i].toLatin1().data()))
        {
          mSpliter.savePicByR_G_B();
          mSpliter.release();
        }
    }
    else if(dealFlag == 2)//灰度分离
    {
        if(mSpliter.init(path_list[i].toLatin1().data()))
        {
          mSpliter.savePicByGray_N(arg.getSplit_Gray());
          mSpliter.release();
        }
    }
  }
}
void MySplitLevelTwoThread::setPicPath(const QStringList &pic_path)
{
  this->path_list = pic_path;
}

void MySplitLevelTwoThread::setSpliter(const SPLIT &m_split)
{
  this->mSpliter = m_split;
}

void MySplitLevelTwoThread::setArg(const SPLITArg &arg)
{
  this->arg = arg;
}


void MySplitLevelTwoThread::setDealFlag(int flag)
{
  this->dealFlag = flag;
}
MySplitLevelTwoThread::~MySplitLevelTwoThread()
{

}