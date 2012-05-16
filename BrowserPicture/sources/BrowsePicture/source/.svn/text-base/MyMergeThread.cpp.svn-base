/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#include "stdafx.h"
#include "MyMergeThread.h"
#include "MyMergeLevelTwoThread.h"
#include "managepic.h"
MyMergeThread::MyMergeThread(void)
{
}

void MyMergeThread::run()
{
  MergePic();
}

void MyMergeThread::MergePic()
{
  if(arg.getMethod() == 0)
  {
    mergePicByCondition_FirstMethod(mSpliter);
  }else if(arg.getMethod() == 1)
  {
    mergePicByCondition_SecondMethod(mSpliter);
  }else if(arg.getMethod() == 2)
  {
    mergePicByCondition_ThirdMethod(mSpliter);
  }
}


bool MyMergeThread::mergePicByCondition_FirstMethod(const SPLIT &m_split)
{
  if(arg.getGray_Pic() == 1)
  {
    if(mergePicByCondition_gray(m_split))
    {
      if(arg.getRgb_Pic() == 1)
      {
        if(mergePicByCondition_rgb(m_split))
        {
          if(arg.getSplit_Pic() == 1)
          {
            if(mergePicByCondition_FirstSplit(m_split))
            {
              //emit showpic(pic_path);
              //emit done();
            }
          }
        }
      }
    }
  }else
  {
    if(arg.getRgb_Pic() == 1)
    {
      if(mergePicByCondition_rgb(m_split))
      {
        if(arg.getSplit_Pic() == 1)
        {
          if(mergePicByCondition_FirstSplit(m_split))
          {
            //emit showpic(pic_path);
            //emit done();
          }
        }
      }
    }else
    {
      if(arg.getSplit_Pic() == 1)
      {
        if(mergePicByCondition_FirstSplit(m_split))
        {
          //emit showpic(pic_path);
          //emit done();
        }
      }
    }
  }
  emit showpic(pic_path);
  emit done();
  return true;
}

bool MyMergeThread::mergePicByCondition_SecondMethod(const SPLIT &m_split)
{
  if(arg.getGray_Pic() == 1)
  {
    if(mergePicByCondition_gray(m_split))
    {
      if(arg.getSplit_Pic() == 1)
      {
        if(mergePicByCondition_Split(m_split))
        {
          if(arg.getRgb_Pic() == 1)
          {
            if(mergePicByCondition_rgb(m_split))
            {
              //emit showpic(pic_path);
              //emit done();
            }
          }
        }
      }else
      {
        if(arg.getRgb_Pic() == 1)
        {
          if(mergePicByCondition_rgb(m_split))
          {
            //emit showpic(pic_path);
            //emit done();
          }
        }
      }
    }
  }else
  {
    if(arg.getSplit_Pic() == 1)
    {
      if(mergePicByCondition_Split(m_split))
      {
        if(arg.getRgb_Pic() == 1)
        {
          if(mergePicByCondition_rgb(m_split))
          {
            //emit showpic(pic_path);
            //emit done();
          }
        }
      }
    }else
    {
      if(arg.getRgb_Pic() == 1)
      {
        if(mergePicByCondition_rgb(m_split))
        {
          //emit showpic(pic_path);
          //emit done();
        }
      }
    }
  }
  emit showpic(pic_path);
  emit done();
  return true;
}

bool MyMergeThread::mergePicByCondition_ThirdMethod(const SPLIT &m_split)
{
  if(arg.getSplit_Pic() == 1)
  {
    if(mergePicByCondition_Split(m_split))
    {
      if(arg.getGray_Pic() == 1)
      {
        if(mergePicByCondition_gray(m_split))
        {
          if(arg.getRgb_Pic() == 1)
          {
            if(mergePicByCondition_rgb(m_split))
            {
              //emit showpic(pic_path);
              //emit done();
            }
          }
        }
      }else if(arg.getRgb_Pic() == 1)
      {
        if(mergePicByCondition_rgb(m_split))
        {
          //emit showpic(pic_path);
          //emit done();
        }
      }
    }
  }else
  {
    if(arg.getGray_Pic() == 1)
    {
      if(mergePicByCondition_gray(m_split))
      {
        if(arg.getRgb_Pic() == 1)
        {
          if(mergePicByCondition_rgb(m_split))
          {
            //emit showpic(pic_path);
            //emit done();
          }
        }
      }
    }else if(arg.getRgb_Pic() == 1)
    {
      if(mergePicByCondition_rgb(m_split))
      {
        //emit showpic(pic_path);
        //emit done();
      }
    }
  }
  emit showpic(pic_path);
  emit done();
  return true;
}

bool MyMergeThread::mergePicByCondition_Split(const SPLIT &m_split)
{
  ManagePic managePic;
  QString tmpstr;
  QStringList list;
  SPLIT split = m_split;
  if(arg.getMethod() == 1)
  {
    if(arg.getGray_Pic() == 1)
    {
      list = managePic.FindFile(pic_path+"/Merge/split");
    }else
    {
      list = managePic.FindFile(pic_path+"/split/split");
    }
  }else if(arg.getMethod() == 2)
  {
    list = managePic.FindFile(pic_path+"/split/split");
  }
/*  QList<MyMergeLevelTwoThread*>thread_list;
  MyMergeLevelTwoThread *mergeSplitThread;
  QStringList path_list;
  int fileNumber = list.size() / (THREAD_NUMBER/(1 + arg.getSplit_Col()));*///根据最大打开的文件句柄计算 最大能够同时运行的线程
  for(int i = 1; i < list.size(); i++)
  {
    if(list[i].left(13) != "L00000_C00000")continue;
    tmpstr = list[0] + "/" + list[i];
    emit showDoingPic(tmpstr);
    if(split.init((const char *)tmpstr.toLocal8Bit()))
    {
      split.mergeSplit(mergeArg.getStartRow(),mergeArg.getStartCol(),mergeArg.getEndRow(),mergeArg.getEndCol());
      split.release();
    }
    /*if(list[i].left(13) != "L00000_C00000")   
    {
      if(i != list.size() - 1)
        continue;
    }else
    {
      tmpstr = list[0] + "/" + list[i];
      path_list.append(tmpstr);
    }
    if(path_list.size() > fileNumber  || i == list.size() - 1 )
    {
      mergeSplitThread = new MyMergeLevelTwoThread;
      thread_list.append(mergeSplitThread);
      mergeSplitThread->setSpliter(m_split);
      mergeSplitThread->setDealFlag(0);
      mergeSplitThread->setMergeArg(mergeArg);
      mergeSplitThread->setPicPath(path_list);
      mergeSplitThread->start();
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
  return true;
}

bool MyMergeThread::mergePicByCondition_FirstSplit(SPLIT m_split)
{	
  ManagePic managePic;
  QString tmpstr;
  QStringList list;
  if(arg.getMethod() == 0)
  {
    if(arg.getGray_Pic() == 1 || arg.getRgb_Pic() == 1)
    {
      list = managePic.FindFile(pic_path+"/Merge/split");
    }else
    {
      list = managePic.FindFile(pic_path+"/split/split");
    }
  }
  if(list.size() > 1)
  {
    tmpstr = list[0] + "/" + list[1];
    emit showDoingPic(tmpstr);
    if(m_split.init((const char *)tmpstr.toLocal8Bit()))
    {
      m_split.mergeSplit(mergeArg.getStartRow(),mergeArg.getStartCol(),mergeArg.getEndRow(),mergeArg.getEndCol());
      m_split.release();
    }
  }
  return true;
}

bool MyMergeThread::mergePicByCondition_rgb(const SPLIT &m_split)
{
  ManagePic managePic;
  QString tmpstr;
  SPLIT split = m_split;
  QStringList list;
  if(arg.getMethod() == 0)
  {
    if(arg.getGray_Pic() == 1)
    {
      list = managePic.FindFile(pic_path+"/Merge/rgb");
    }else
    {
      list = managePic.FindFile(pic_path+"/split/rgb");
    }
  }
  if(arg.getMethod() == 1 || arg.getMethod() == 2)
  {
    if(arg.getSplit_Pic() == 1 || arg.getGray_Pic() == 1)
    {
      list = managePic.FindFile(pic_path+"/Merge/rgb");
    }else
    {
      list = managePic.FindFile(pic_path+"/split/rgb");
    }
  }

  if (mergeArg.getChannel().contains("R",Qt::CaseInsensitive))
  {
    mergeArg.setChannel("R");
  }
  else  if (mergeArg.getChannel().contains("G",Qt::CaseInsensitive))
  {
    mergeArg.setChannel("G");
  }
  else  if (mergeArg.getChannel().contains("B",Qt::CaseInsensitive))
  {
    mergeArg.setChannel("B");
  }
  else  if (mergeArg.getChannel().contains("混合",Qt::CaseInsensitive))
  {
    mergeArg.setChannel("RGB");
  }
/*  QList<MyMergeLevelTwoThread*>thread_list;
  MyMergeLevelTwoThread *mergeRgbThread;
  QStringList path_list;
  int fileNumber = list.size() / (THREAD_NUMBER/4);*///根据最大打开的文件句柄计算 最大能够同时运行的线程
  for(int i = 1; i < list.size(); i++)
  {
    if(list[i].left(1) != "B") continue;
    tmpstr = list[0] + "/" + list[i];
    emit showDoingPic(tmpstr);
    if(split.init((const char *)tmpstr.toLocal8Bit()))
    {
      split.mergeRGB((const char *)mergeArg.getChannel().toLocal8Bit());
      split.release();
    }
   /* if(list[i].left(1) != "B") 
    {
      if(i != list.size() - 1)
        continue;
    }else
    {
      tmpstr = list[0] + "/" + list[i];
      path_list.append(tmpstr);
    }
    if(path_list.size() > fileNumber  || i == list.size() - 1 )
    {
      mergeRgbThread = new MyMergeLevelTwoThread;
      thread_list.append(mergeRgbThread);
      mergeRgbThread->setSpliter(m_split);
      mergeRgbThread->setDealFlag(1);
      mergeRgbThread->setMergeArg(mergeArg);
      mergeRgbThread->setPicPath(path_list);
      mergeRgbThread->start();
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
  return true;
}
bool MyMergeThread::mergePicByCondition_gray(const SPLIT &m_split)
{
  ManagePic managePic;
  QString tmpstr;
  QStringList list;
  SPLIT split = m_split;
  if(arg.getMethod() != 2)
  {
    list = managePic.FindFile(pic_path+"/split/gray");
  }else if(arg.getMethod() == 2)
  {
    if(arg.getSplit_Pic() == 1)
    {
      list = managePic.FindFile(pic_path+"/Merge/gray");
    }else
    {
      list = managePic.FindFile(pic_path+"/split/gray");
    }
  }
 /* QList<MyMergeLevelTwoThread*>thread_list;
  MyMergeLevelTwoThread *mergeGrayThread;
  QStringList path_list;
  int fileNumber = list.size() / (THREAD_NUMBER/(IntPow(2,arg.getSplit_Gray()) + 1));*///根据最大打开的文件句柄计算 最大能够同时运行的线程
  for(int i = 1; i < list.size(); i++)
  {
    if(list[i].left(1) != "0")continue;
    tmpstr = list[0] + "/" + list[i];
    emit showDoingPic(tmpstr);
    if(split.init((const char *)tmpstr.toLocal8Bit()))
    {
      split.mergeGray(mergeArg.getStartGray(),mergeArg.getEndGray());
      split.release();
    }
    /*if(list[i].left(1) != "0") 
    {
      if(i != list.size() - 1)
        continue;
    }else
    {
      tmpstr = list[0] + "/" + list[i];
      path_list.append(tmpstr);
    }
    if(path_list.size() > fileNumber  || i == list.size() - 1 )
    {
      mergeGrayThread = new MyMergeLevelTwoThread;
      thread_list.append(mergeGrayThread);
      mergeGrayThread->setSpliter(m_split);
      mergeGrayThread->setDealFlag(2);
      mergeGrayThread->setMergeArg(mergeArg);
      mergeGrayThread->setPicPath(path_list);
      mergeGrayThread->start();
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
  return true;
}

void MyMergeThread::setArg(SPLITArg arg)
{
  mSpliter.setMethod(arg.getMethod());
  mSpliter.setSplit(arg.getSplit_Pic());
   mSpliter.setRGB(arg.getRgb_Pic());
   mSpliter.setGray(arg.getGray_Pic());
  this->arg = arg;
}

void MyMergeThread::setPath(QString path)
{
  this->pic_path = path;
}

void MyMergeThread::setMergeArg(const MergeArg &mergeArg)
{
  this->mergeArg = mergeArg;
}

MergeArg MyMergeThread::getMergeArg()
{
  return mergeArg;
}

MyMergeThread::~MyMergeThread(void)
{
}
