/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#include "stdafx.h"
#include "MyAutoMergeThread.h"
#include "managepic.h"
#include "MyAutoMergeLevelTwoThread.h"
MyAutoMergeThread::MyAutoMergeThread(void)
{
}

void MyAutoMergeThread::run()
{
  autoMergePic();
}

void MyAutoMergeThread::autoMergePic()
{
  if(arg.getMethod() == 0)//split->rgb->gray
  {
    automergePicByFirstMethod(mSpliter);
  }
  else if(arg.getMethod() == 1)//rgb->split->gray
  {	
    automergePicBySecondMethod(mSpliter);
  }else//rgb->gray->split
  {
    automergePicByThirdMethod(mSpliter);
  }
}

bool MyAutoMergeThread::automergePicByFirstMethod(const SPLIT &m_split)//split->rgb->gray
{	
  if(arg.getGray_Pic() == 1)
  {
    if(automergePicBygray(m_split))
    {
      if(arg.getRgb_Pic() == 1)
      {
        if(automergePicByrgb(m_split))
        {
          if(arg.getSplit_Pic() == 1)
          {
            if(automergePicBySplit(m_split))
            {
            }
          }
        }
      }
    }
  }else
  {
    if(arg.getRgb_Pic() == 1)
    {
      if(automergePicByrgb(m_split))
      {
        if(arg.getSplit_Pic() == 1)
        {
          if(automergePicBySplit(m_split))
          {
          }
        }
      }
    }else
    {
      if(arg.getSplit_Pic() == 1)
      {
        if(automergePicBySplit(m_split))
        {
        }
      }
    }
  }
  emit showpic(pic_path);
  emit done();
  return true;
}

bool MyAutoMergeThread::automergePicBygray(const SPLIT &m_split)
{
  SPLIT split = m_split;
  ManagePic managePic;
  QString tmpstr;
  QStringList list;
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
 /* QList<MyAutoMergeLevelTwoThread*>thread_list;
  MyAutoMergeLevelTwoThread *autoMergeGrayThread;
  QStringList path_list;
  int fileNumber = list.size() / (THREAD_NUMBER/(IntPow(2,arg.getSplit_Gray()) + 1));*///根据最大打开的文件句柄计算 最大能够同时运行的线程
  for(int i = 1; i < list.size(); i++)
  {
    if(list[i].left(1) != "0")continue;
    tmpstr = list[0] + "/" + list[i];
    emit showDoingPic(tmpstr);
    if(split.init((const char *)tmpstr.toLocal8Bit()))
    {
      split.mergeGray();
      split.release();
    }
   /* if(list[i].left(1) != "0") 
    {
      if(i != list.size() - 1)
        continue;
    }else
    {
      tmpstr = list[0] + "/" + list[i];
      path_list.append(tmpstr);
    }*/
    //if(path_list.size() > fileNumber  || i == list.size() - 1 )
    //{
    //  autoMergeGrayThread = new MyAutoMergeLevelTwoThread;
    //  thread_list.append(autoMergeGrayThread);
    //  autoMergeGrayThread->setSpliter(m_split);
    //  autoMergeGrayThread->setDealFlag(2);
    //  autoMergeGrayThread->setPicPath(path_list);
    //  autoMergeGrayThread->start();
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
  return true;
}

bool MyAutoMergeThread::automergePicByrgb(const SPLIT &m_split)
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
    if(arg.getGray_Pic() == 1 || arg.getSplit_Pic() == 1)
    {
      list = managePic.FindFile(pic_path+"/Merge/rgb");
    }else
    {
      list = managePic.FindFile(pic_path+"/split/rgb");
    }
  }
/*  QList<MyAutoMergeLevelTwoThread*>thread_list;
  MyAutoMergeLevelTwoThread *autoMergeRgbThread;
  QStringList path_list;
  int fileNumber = list.size() / (THREAD_NUMBER/4);*///根据最大打开的文件句柄计算 最大能够同时运行的线程
  for(int i = 1; i < list.size(); i++)
  {
    if(list[i].left(1) != "B") continue;
     tmpstr = list[0] + "/" + list[i];
     emit showDoingPic(tmpstr);
     if(split.init((const char *)tmpstr.toLocal8Bit()))
     {
       split.mergeRGB();
       split.release();
     }
    //if(list[i].left(1) != "B") 
    //{
    //  if(i != list.size() - 1)
    //    continue;
    //}else
    //{
    //  tmpstr = list[0] + "/" + list[i];
    //  path_list.append(tmpstr);
    //}
    //if(path_list.size() > fileNumber  || i == list.size() - 1 )
    //{
    //  autoMergeRgbThread = new MyAutoMergeLevelTwoThread;
    //  thread_list.append(autoMergeRgbThread);
    //  autoMergeRgbThread->setSpliter(m_split);
    //  autoMergeRgbThread->setDealFlag(1);
    //  autoMergeRgbThread->setPicPath(path_list);
    //  autoMergeRgbThread->start();
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
  return true;
}

bool MyAutoMergeThread::automergePicBySplit(SPLIT m_split)
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
    emit	showDoingPic(tmpstr);
    if(m_split.init((const char *)tmpstr.toLocal8Bit()))
    {
      m_split.mergeSplit();
      m_split.release();
    }
  }
  return true;
}

bool MyAutoMergeThread::automergePicBySecondMethod(const SPLIT &m_split)//rgb->split->gray
{
  if(arg.getGray_Pic() == 1)
  {
    if(automergePicBygray(m_split))
    {
      if(arg.getSplit_Pic() == 1)
      {
        if(automergePicBySecondMethod_Split(m_split))
        {
          if(arg.getRgb_Pic() == 1)
          {
            if(automergePicByrgb(m_split))
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
          if(automergePicByrgb(m_split))
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
      if(automergePicBySecondMethod_Split(m_split))
      {
        if(arg.getRgb_Pic() == 1)
        {
          if(automergePicByrgb(m_split))
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
        if(automergePicByrgb(m_split))
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

bool MyAutoMergeThread::automergePicBySecondMethod_Split(const SPLIT &m_split)
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
  }
  if(arg.getMethod() == 2)
  {
    list = managePic.FindFile(pic_path+"/split/split");
  }
/*  QList<MyAutoMergeLevelTwoThread*>thread_list;
  MyAutoMergeLevelTwoThread *autoMergeSplitThread;
  QStringList path_list;
  int fileNumber = list.size() / (THREAD_NUMBER/(1 + arg.getSplit_Col()));*///根据最大打开的文件句柄计算 最大能够同时运行的线程
  for(int i = 1; i < list.size(); i++)
  {
     if(list[i].left(13) != "L00000_C00000")  continue;
     tmpstr = list[0] + "/" + list[i];
     emit showDoingPic(tmpstr);
     if(split.init((const char *)tmpstr.toLocal8Bit()))
     {
       split.mergeSplit();
       split.release();
     }
   /* if(list[i].left(13) != "L00000_C00000")   
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
      autoMergeSplitThread = new MyAutoMergeLevelTwoThread;
      thread_list.append(autoMergeSplitThread);
      autoMergeSplitThread->setSpliter(m_split);
      autoMergeSplitThread->setDealFlag(0);
      autoMergeSplitThread->setPicPath(path_list);
      autoMergeSplitThread->start();
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

bool MyAutoMergeThread::automergePicByThirdMethod(const SPLIT &m_split)//rgb->gray->split
{
  if(arg.getSplit_Pic() == 1)
  {
    if(automergePicBySecondMethod_Split(m_split))
    {
      if(arg.getGray_Pic() == 1)
      {
        if(automergePicBygray(m_split))
        {
          if(arg.getRgb_Pic() == 1)
          {
            if(automergePicByrgb(m_split))
            {
              //emit showpic(pic_path);
              //emit done();
            }
          }
        }
      }else if(arg.getRgb_Pic() == 1)
      {
        if(automergePicByrgb(m_split))
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
      if(automergePicBygray(m_split))
      {
        if(arg.getRgb_Pic() == 1)
        {
          if(automergePicByrgb(m_split))
          {
            //emit showpic(pic_path);
            //emit done();
          }
        }

      }
    }else if(arg.getRgb_Pic() == 1)
    {
      if(automergePicByrgb(m_split))
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

void MyAutoMergeThread::setArg(SPLITArg arg)
{
  mSpliter.setMethod(arg.getMethod());
  mSpliter.setSplit(arg.getSplit_Pic());
  mSpliter.setRGB(arg.getRgb_Pic());
  mSpliter.setGray(arg.getGray_Pic());
  this->arg = arg;
}
void MyAutoMergeThread::setPath(QString path)
{
  this->pic_path = path;
}

MyAutoMergeThread::~MyAutoMergeThread(void)
{
}
