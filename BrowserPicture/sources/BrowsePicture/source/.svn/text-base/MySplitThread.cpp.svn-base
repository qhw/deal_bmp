/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/

#include "stdafx.h"
#include "MySplitThread.h"
#include "managepic.h"
#include "MySplitLevelTwoThread.h"
#include <ctime>
MySplitThread::MySplitThread(void)
{
}

void MySplitThread::run()
{
  SplitPic();
}

void MySplitThread::SplitPic()
{
  if(arg.getMethod() == 0)
  {
    DoneByFirstMethod();
  }else if(arg.getMethod() == 1)
  {
    DoneBySecondMethod();
  }else
  {
    DoneByThirdMethod();
  }
}


void MySplitThread::DoneByFirstMethod()//split->rgb->gray
{
  SPLIT m_split;
  m_split.setMethod(arg.getMethod());
  emit showDoingPic(pic_path);
  
  if(arg.getSplit_Pic() == 1)
  {
    if(m_split.init(arg.getSplit_Row(),arg.getSplit_Col(),(const char *)pic_path.toLocal8Bit()))
    {
      m_split.doSplit();
      m_split.release();
    }
    if(arg.getRgb_Pic() == 1)
    {
      DoneByFirstMethod_RGB(m_split);
      if(arg.getGray_Pic() == 1)
      {
        DoneByGray(m_split,1);
      }
    }
    //emit showpic(pic_path);
   // emit done();
  }else
  {
    if(arg.getRgb_Pic() == 1)
    {
      if(m_split.init((const char *)pic_path.toLocal8Bit()))
      {
        m_split.savePicByR_G_B();
        m_split.release();
      }
      if(arg.getGray_Pic() == 1)
      {
        DoneByGray(m_split,1);
      }
     // emit showpic(pic_path);
      //emit done();
    }
  }
  emit done();
}
void MySplitThread::DoneByFirstMethod_RGB(const SPLIT &m_split)
{
  SPLIT split = m_split;
  ManagePic managePic;
  QString tmpstr;
  int pos = pic_path.lastIndexOf ("/",-1);
  QString filename=pic_path;
  filename.remove(0,pos +1);//获取文件的名
  QStringList list = managePic.FindFile(filename+"/split/split");
  //QList<MySplitLevelTwoThread*>thread_list;
  //MySplitLevelTwoThread *splitRgbThread;
  //QStringList path_list;
  //int fileNumber = list.size() /1  /*(THREAD_NUMBER/4)*/;//根据最大打开的文件句柄计算 最大能够同时运行的线程
  for(int i = 1; i < list.size(); i++)
  {
    tmpstr = list[0] + "/" + list[i];
    emit showDoingPic(tmpstr);
    if(split.init((const char *)tmpstr.toLocal8Bit()))
    {
     split.savePicByR_G_B();
     split.release();
    }
    /*path_list.append(tmpstr);
    if(path_list.size() > fileNumber || i + 1 >= list.size())
    {
        splitRgbThread = new MySplitLevelTwoThread;
        thread_list.append(splitRgbThread);
        splitRgbThread->setSpliter(m_split);
        splitRgbThread->setDealFlag(1);
        splitRgbThread->setPicPath(path_list);
        splitRgbThread->start();
        path_list.clear();
    }*/
  }
  //for(int i = 0; i < thread_list.size(); i++)
  //{
  //  thread_list[i]->wait();
  //}
  //for(int i = 0; i < thread_list.size(); i++)
  //{
  //  delete thread_list[i];
  //}
}

void MySplitThread::DoneByGray(const SPLIT &m_split,int method)
{
  SPLIT split = m_split;
  ManagePic managePic;
  QString tmpstr;
  int pos = pic_path.lastIndexOf ("/",-1);
  QString filename=pic_path;
  filename.remove(0,pos +1);//获取文件的名
  QStringList list;
  if(method == 1)
  {
      list = managePic.FindFile(filename+"/split/rgb");
  }else if(method == 2)
  {
     list = managePic.FindFile(filename+"/split/split");
  }
/*  QList<MySplitLevelTwoThread*>thread_list;
  MySplitLevelTwoThread *splitGrayThread;
  QStringList path_list;
  int fileNumber = list.size() / (THREAD_NUMBER/(IntPow(2,arg.getSplit_Gray()) + 1));*///根据最大打开的文件句柄计算 最大能够同时运行的线程
  for(int i = 1; i < list.size(); i++)
  {
    tmpstr = list[0] + "/" + list[i];
    emit showDoingPic(tmpstr);
    if(split.init((const char *)tmpstr.toLocal8Bit()))
    {
      split.savePicByGray_N(arg.getSplit_Gray());
      split.release();
    }
    //path_list.append(tmpstr);
    //if(path_list.size() > fileNumber  || i == list.size() - 1 )
    //{
    //  splitGrayThread = new MySplitLevelTwoThread;
    //  thread_list.append(splitGrayThread);
    //  splitGrayThread->setSpliter(m_split);
    //  splitGrayThread->setDealFlag(2);
    //  splitGrayThread->setPicPath(path_list);
    //  splitGrayThread->setArg(arg);
    //  splitGrayThread->start();
    //  path_list.clear();
    //}
  }
  //for(int i = 0; i < thread_list.size(); i++)
  //{
  //  thread_list[i]->wait();
  //}
  //for(int i = 0; i < thread_list.size(); i++)
  //{
  //  delete thread_list[i];
  //}
}

void MySplitThread::DoneBySecondMethod()//rgb->split->gray
{
  SPLIT m_split;
  m_split.setMethod(arg.getMethod());
  emit showDoingPic(pic_path);
  if(arg.getRgb_Pic() == 1)
  {
    if(m_split.init((const char *)pic_path.toLocal8Bit()))
    {
      m_split.savePicByR_G_B();
      m_split.release();
    }
    if(arg.getSplit_Pic() == 1)
    {
      DoneBySplit(m_split,1,arg.getSplit_Row(),arg.getSplit_Col());
      if(arg.getGray_Pic() == 1)
      {
        DoneByGray(m_split,2);
      }
    }else if(arg.getGray_Pic() == 1)
    {
      DoneByGray(m_split,1);
    }
   // emit showpic(pic_path);
    //emit done();
  }else if(arg.getSplit_Pic() == 1)
  {
    if(m_split.init(arg.getSplit_Row(),arg.getSplit_Col(),(const char *)pic_path.toLocal8Bit()))
    {
      m_split.doSplit();
      m_split.release();
    }
    //emit showpic(pic_path);
    //emit done();
  }
  emit done();
}

void MySplitThread::DoneBySplit(const SPLIT &m_split,int method, int row,int col)
{
  SPLIT split = m_split;
  ManagePic managePic;
  QString tmpstr;
  int pos = pic_path.lastIndexOf ("/",-1);
  QString filename=pic_path;
  filename.remove(0,pos +1);//获取文件的名
  QStringList list;
  if(method == 1)
  {
      list = managePic.FindFile(filename+"/split/rgb");
  }else if(method == 2)
  {
      list = managePic.FindFile(filename+"/split/gray");
  }
  //QList<MySplitLevelTwoThread*>thread_list;
  //MySplitLevelTwoThread *splitThread;
  //QStringList path_list;
  //int fileNumber = list.size() / (THREAD_NUMBER/(arg.getSplit_Col() + 1));
  for(int i = 1; i < list.size(); i++)
  {
    tmpstr = list[0] + "/" + list[i];
    emit showDoingPic(tmpstr);
    if(split.init(arg.getSplit_Row(),arg.getSplit_Col(),(const char *)tmpstr.toLocal8Bit()))
    {
      split.doSplit();
      split.release();
    }
    //path_list.append(tmpstr);
    //if(path_list.size() > fileNumber || i + 1 >= list.size())
    //{
    //  splitThread = new MySplitLevelTwoThread;
    //  thread_list.append(splitThread);
    //  splitThread->setSpliter(m_split);
    //  splitThread->setDealFlag(0);
    //  splitThread->setPicPath(path_list);
    //  splitThread->setArg(arg);
    //  splitThread->start();
    //  path_list.clear();
    //}
  }
  //for(int i = 0; i < thread_list.size(); i++)
  //{
  //  thread_list[i]->wait();
  //}
  //for(int i = 0; i < thread_list.size(); i++)
  //{
  //  delete thread_list[i];
  //}
}

void MySplitThread::DoneByThirdMethod()//rgb->gray->split
{
  SPLIT m_split;
  m_split.setMethod(arg.getMethod());
  emit showDoingPic(pic_path);
  if(arg.getRgb_Pic() == 1)
  {
    if(m_split.init((const char *)pic_path.toLocal8Bit()))
    {
      m_split.savePicByR_G_B();
      m_split.release();
    }
    if(arg.getGray_Pic() == 1)
    {
      DoneByGray(m_split,1);
      if(arg.getSplit_Pic() == 1)
      {
        DoneBySplit(m_split,2,arg.getSplit_Row(),arg.getSplit_Col());
      }
    }else if(arg.getSplit_Pic() == 1)
    {
      DoneBySplit(m_split,1,arg.getSplit_Row(),arg.getSplit_Col());	
    }
   // emit showpic(pic_path);
    //emit done();
  }else if(arg.getSplit_Pic() == 1)
  {
    if(m_split.init(arg.getSplit_Row(),arg.getSplit_Col(),(const char *)pic_path.toLocal8Bit()))
    {
      m_split.doSplit();
      m_split.release();
    }
    //emit showpic(pic_path);
    //emit done();
  }
  emit done();
}

void MySplitThread::setPath(QString path)
{
  this->pic_path = path;
}

void MySplitThread::setArg(const SPLITArg &arg)
{
  this->arg = arg;
}

MySplitThread::~MySplitThread(void)
{
}