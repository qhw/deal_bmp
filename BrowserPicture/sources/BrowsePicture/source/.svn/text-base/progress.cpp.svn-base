#include "StdAfx.h"
#include "progress.h"
#include "managepic.h"
#include "split/SPLIT.h"
#include "MySplitThread.h"
#include "MyMergeThread.h"
#include "MyAutoMergeThread.h"
Progress::Progress(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);

   lefttime = 0;
  ui.progress->setMinimum(0);
  ui.progress->setValue(0);
  timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(updateProgress()));
  connect(ui.cancel_btn,SIGNAL(clicked()),this,SLOT(cancelBtn()));
  timer->start(1000);
}

void Progress::updateProgress()//更新进度条
{
    lefttime += 1000;
    int size =  getPathFileSize(pathName,flag);
    ui.progress->setValue(size);
    if(size >= ui.progress->maximum())
    {
      size = ui.progress->maximum();
       ui.progress->setValue(size);
       timer->stop();
       ui.left_size->setText("");
       ui.left_time->setText("");
       //close();
    }
    //ui.left_size->setText(QString::number(size) +"/" + QString::number(allFileSize) +"" );
    int speed = size/lefttime;
    QString speedstr;
    speed = speed * 1000;
    if(speed >= 1024 * 1024)
    {
      speed /= 1024 * 1024;
      speedstr = QString::number(speed) +"M/s";
    }else if(speed >= 1024)
    {
      speed /= 1024;
      speedstr = QString::number(speed) +"KB/s";
    }else
    {
      speedstr = QString::number(speed) +"B/s";
    }
    ui.left_size->setText(speedstr);
    ui.left_time->setText(FormatTime(lefttime,size));
}

QString Progress::FormatTime(int left,int size)
{
  QString formattime ="剩余";
  int minutes = 0;
  int hours = 0;
  int days = 0;
  int speed = size / left;
  if(speed == 0) return "";
  int second = (allFileSize - size) / speed / 1000;
  if(second >= 60)
  {
    minutes = second / 60;
    second = second % 60;
    if(minutes >= 60)
    {
      hours = minutes / 60;
      minutes = minutes % 60;
      if(hours >= 24)
      {
        days = hours / 24;
        hours = hours % 24;
      }
    }
  }
     if(days != 0) 
     {
       formattime += QString::number(days) +"天";
     }
     if(hours != 0) 
     {
       formattime += QString::number(hours) +"小时";
     }
     if(minutes != 0) 
     {
       formattime += QString::number(minutes) +"分钟";
     }
     if(second != 0) 
     {
       formattime += QString::number(second) +"秒";
     }
     return formattime;
}

int Progress::getPathFileSize(QString path,int flag)//获取指定文件夹下的
{
  ManagePic pic;
  int size = 0;
  QString tmp = path;
  //QString path = "D:/MyWork/BrowserPicture/bin/Debug/biq.bmp/split";
  if(flag == 0)
  {
    path +="/split";
  }else if(flag == 1 || flag == 2)
  {
    path +="/Merge";
  }
  QStringList list_split = pic.FindFile(path +"/split");
  QStringList list_rgb = pic.FindFile(path +"/rgb");
  QStringList list_gray = pic.FindFile(path +"/gray");
  for(int i  = 1; i < list_split.size(); i++)
  {
    size += getFileSize(list_split[0] +"/" + list_split[i]);
  }
  for(int i  = 1; i < list_rgb.size(); i++)
  {
    size += getFileSize(list_rgb[0] +"/" + list_rgb[i]);
  }
  for(int i  = 1; i < list_gray.size(); i++)
  {
    size += getFileSize(list_gray[0] +"/" + list_gray[i]);
  }
  if(flag == 1 || flag == 2)
  {
    int pos = tmp.lastIndexOf("/");
    tmp = tmp.remove(0,pos+1);
    QFileInfo file(path +"/"+tmp);
    if(file.exists())
      size += getFileSize(path +"/" +tmp);
  }
  return size;
}

int Progress::getFileSize(QString pathName)//获取指定文件的大小
{
  QFileInfo file(pathName);
  return file.size();
}
void Progress::cancelBtn()//取消按钮
{
  close();
}

void Progress::closeDlg()
{
    close();
}
void Progress::closeEvent ( QCloseEvent *event )
{
  timer->stop();
  if(flag == 0) 
  {
    split->terminate();
  }
  if(flag == 1) 
  {
    merge->terminate();
  }
  if(flag == 2) 
  {
    automerge->terminate();
  }
}
int Progress::getSize()
{
  int size = 0;
  if(flag == 0)
  {
    size = getSplitFileSize();
  }else if(flag == 1)
  {
    size = getAutoMergeFileSize();
  }else if(flag == 2)
  {
    size = getMergeFileSize();
  }
  return size;
}
int Progress::getAutoMergeFileSize()
{
  int size = 0;
  if(arg.getMethod() == 0)
  {
    size = getAutoMergeFirstMethodFileSize();
  }else if(arg.getMethod() == 1)
  {
    size = getAutoMergeSecondMethodFileSize();
  }else if(arg.getMethod() == 2)
  {
    size = getAutoMergeThirdMethodFileSize();
  }
  return size;
}
int Progress::getAutoMergeFirstMethodFileSize()
{
  ManagePic pic;
  int size = 0;
  int split_size = 0;
  int rgb_size = 0;
  QString path =  pathName + "/split";
  QStringList list_split = pic.FindFile(path +"/split");
  QStringList list_rgb = pic.FindFile(path +"/rgb");
  for(int i  = 1; i < list_split.size(); i++)
  {
    split_size += getFileSize(list_split[0] +"/" + list_split[i]);
  }
  for(int i  = 1; i < list_rgb.size(); i++)
  {
    rgb_size += getFileSize(list_rgb[0] +"/" + list_rgb[i]);
  }
  if(arg.getSplit_Pic())
  {
    size += split_size;
  }else
  {
    size += rgb_size / 3;
  }
  if(arg.getSplit_Pic())
  {
    if(arg.getRgb_Pic())
    {
      size += split_size;
      if(arg.getGray_Pic())
      {
        size += rgb_size;
      }
    }
  }else
  {
    if(arg.getRgb_Pic())
    {
      if(arg.getGray_Pic())
      {
        size += rgb_size;
      }
    }
  }
  return size;
}
int Progress::getAutoMergeSecondMethodFileSize()
{
  ManagePic pic;
  int size = 0;
  int split_size = 0;
  int rgb_size = 0;
  QString path =  pathName + "/split";
  QStringList list_split = pic.FindFile(path +"/split");
  QStringList list_rgb = pic.FindFile(path +"/rgb");
  for(int i  = 1; i < list_split.size(); i++)
  {
    split_size += getFileSize(list_split[0] +"/" + list_split[i]);
  }
  for(int i  = 1; i < list_rgb.size(); i++)
  {
    rgb_size += getFileSize(list_rgb[0] +"/" + list_rgb[i]);
  }
  if(arg.getRgb_Pic())
  {
    size += rgb_size / 3;
  }else if(arg.getSplit_Pic())
  {
    size += split_size;
  }
  if(arg.getRgb_Pic())
  {
    if(arg.getSplit_Pic() || arg.getGray_Pic())
    {
      size += rgb_size;
      if(arg.getSplit_Pic() &&  arg.getGray_Pic())
      {
        size +=split_size;
      }
    }
  }
  return size;
}
int Progress::getAutoMergeThirdMethodFileSize()
{
  ManagePic pic;
  int size = 0;
  int gray_size = 0;
  int rgb_size = 0;
  int split_size = 0;
  QString path =  pathName + "/split";
  QStringList list_gray = pic.FindFile(path +"/gray");
  QStringList list_rgb = pic.FindFile(path +"/rgb");
  QStringList list_split = pic.FindFile(path +"/split");
  for(int i  = 1; i < list_gray.size(); i++)
  {
    gray_size += getFileSize(list_gray[0] +"/" + list_gray[i]);
  }
  for(int i  = 1; i < list_rgb.size(); i++)
  {
    rgb_size += getFileSize(list_rgb[0] +"/" + list_rgb[i]);
  }
  for(int i  = 1; i < list_split.size(); i++)
  {
    split_size += getFileSize(list_split[0] +"/" + list_split[i]);
  }
  if(arg.getRgb_Pic())
  {
    size += rgb_size / 3;
  }else if(arg.getSplit_Pic())
  {
    size += split_size;
  }
  if(arg.getRgb_Pic())
  {
    if(arg.getSplit_Pic() || arg.getGray_Pic())
    {
      size += rgb_size;
      if(arg.getSplit_Pic() &&  arg.getGray_Pic())
      {
        size +=gray_size;
      }
    }
  }
  return size;
}
int Progress::getMergeFileSize()
{
  int size = 0;
  if(arg.getMethod() == 0)
  {
    size = getMergeFirstMethodFileSize();
  }else if(arg.getMethod() == 1)
  {
    size = getMergeSecondMethodFileSize();
  }else if(arg.getMethod() == 2)
  {
    size = getMergeThirdMethodFileSize();
  }
  return size;
}

int Progress::getMergeFirstMethodFileSize()
{
  ManagePic pic;
  int size = 0;
  int split_size = 0;
  int rgb_size = 0;
  QString path =  pathName + "/split";
  QStringList list_split = pic.FindFile(path +"/split");
  QStringList list_rgb = pic.FindFile(path +"/rgb");
  for(int i  = 1; i < list_split.size(); i++)
  {
    split_size += getFileSize(list_split[0] +"/" + list_split[i]);
  }
  for(int i  = 1; i < list_rgb.size(); i++)
  {
    rgb_size += getFileSize(list_rgb[0] +"/" + list_rgb[i]);
  }

  if(arg.getSplit_Pic())
  {
    size += split_size /(arg.getSplit_Col() * arg.getSplit_Row()) * 
      (mergeArg.getEndRow() - mergeArg.getStartRow() + 1) *
      (mergeArg.getEndCol() - mergeArg.getStartCol() + 1);
  }else
  {
    size += rgb_size / 3;
  }
  if(arg.getSplit_Pic())
  {
    if(arg.getRgb_Pic())
    {
      size += size;
      if(arg.getGray_Pic())
      {
        size += rgb_size;
      }
    }
  }else
  {
    if(arg.getRgb_Pic())
    {
      if(arg.getGray_Pic())
      {
        size += rgb_size;
      }
    }
  }
  return size;
}

void Progress::checkMergeArg()
{
  if(mergeArg.getStartRow() < 0) mergeArg.setStart_Row_Col(0,mergeArg.getStartCol());
  if(mergeArg.getStartRow() > arg.getSplit_Row() - 1) mergeArg.setStart_Row_Col(arg.getSplit_Row() - 1,mergeArg.getStartCol());
  if(mergeArg.getStartCol() < 0) mergeArg.setStart_Row_Col(mergeArg.getStartRow(),0);
  if(mergeArg.getStartCol() > arg.getSplit_Col() - 1) mergeArg.setStart_Row_Col(mergeArg.getStartRow(),arg.getSplit_Col() - 1);

  if(mergeArg.getEndRow() > arg.getSplit_Row() - 1) mergeArg.setStart_Row_Col(arg.getSplit_Row() - 1,mergeArg.getStartCol());
  if(mergeArg.getEndCol() > arg.getSplit_Col() - 1) mergeArg.setStart_Row_Col(mergeArg.getStartRow(),arg.getSplit_Col() - 1);

  if(mergeArg.getStartRow() > arg.getSplit_Row()) mergeArg.setStart_Row_Col(arg.getSplit_Row(),mergeArg.getStartCol());
  if(mergeArg.getStartCol() > arg.getSplit_Col()) mergeArg.setStart_Row_Col(mergeArg.getStartRow(),arg.getSplit_Col());
  if(mergeArg.getEndRow() > arg.getSplit_Row()) mergeArg.setEnd_Row_Col(arg.getSplit_Row(),mergeArg.getEndCol());
  if(mergeArg.getEndCol() > arg.getSplit_Col()) mergeArg.setEnd_Row_Col(mergeArg.getEndRow(),arg.getSplit_Col());
}
int Progress::getMergeSecondMethodFileSize()
{
  ManagePic pic;
  int size = 0;
  int split_size = 0;
  int rgb_size = 0;
  QString path =  pathName + "/split";
  QStringList list_split = pic.FindFile(path +"/split");
  QStringList list_rgb = pic.FindFile(path +"/rgb");
  for(int i  = 1; i < list_split.size(); i++)
  {
    split_size += getFileSize(list_split[0] +"/" + list_split[i]);
  }
  for(int i  = 1; i < list_rgb.size(); i++)
  {
    rgb_size += getFileSize(list_rgb[0] +"/" + list_rgb[i]);
  }
  int block = (arg.getSplit_Col() * arg.getSplit_Row()) /
    (mergeArg.getEndRow() - mergeArg.getStartRow() + 1) /
    (mergeArg.getEndCol() - mergeArg.getStartCol() + 1) ;
  if(arg.getRgb_Pic())
  {
    size += rgb_size / block / 3;
  }else if(arg.getSplit_Pic())
  {
    size += split_size / block;
  }
  if(arg.getRgb_Pic())
  {
    if(arg.getSplit_Pic() || arg.getGray_Pic())
    {
      size += rgb_size / block;
      if(arg.getSplit_Pic() &&  arg.getGray_Pic())
      {
        size +=split_size;
      }
    }
  }
  return size;
}

int Progress::getMergeThirdMethodFileSize()
{
  ManagePic pic;
  int size = 0;
  int gray_size = 0;
  int rgb_size = 0;
  int split_size = 0;
  QString path =  pathName + "/split";
  QStringList list_gray = pic.FindFile(path +"/gray");
  QStringList list_rgb = pic.FindFile(path +"/rgb");
  QStringList list_split = pic.FindFile(path +"/split");
  for(int i  = 1; i < list_gray.size(); i++)
  {
    gray_size += getFileSize(list_gray[0] +"/" + list_gray[i]);
  }
  for(int i  = 1; i < list_rgb.size(); i++)
  {
    rgb_size += getFileSize(list_rgb[0] +"/" + list_rgb[i]);
  }
  for(int i  = 1; i < list_split.size(); i++)
  {
    split_size += getFileSize(list_split[0] +"/" + list_split[i]);
  }
  int block = (arg.getSplit_Col() * arg.getSplit_Row()) /
    (mergeArg.getEndRow() - mergeArg.getStartRow() + 1) /
    (mergeArg.getEndCol() - mergeArg.getStartCol() + 1) ;
  if(arg.getRgb_Pic())
  {
    size += rgb_size / block / 3;
  }else if(arg.getSplit_Pic())
  {
    size += split_size / block;
  }
  if(arg.getRgb_Pic())
  {
    if(arg.getSplit_Pic() || arg.getGray_Pic())
    {
      size += rgb_size / block;
      if(arg.getSplit_Pic() &&  arg.getGray_Pic())
      {
        size +=gray_size / block;
      }
    }
  }
  return size;
}

int Progress::getSplitFileSize()
{
  int size = 0;
  if(arg.getMethod() == 0)
  {
      size = getFirstMethodSplitFileSize();
  }
  else if(arg.getMethod() == 1)
  {
    size = getSecondMethodSplitFileSize();
  }else if(arg.getMethod() == 2)
  {
    size = getThirdMethodSplitFileSize();
  }
  return size;
}
int Progress::getFirstMethodSplitFileSize()
{
  int size = 0;
  QFileInfo file(fileName);
  if(arg.getSplit_Pic())
  {
    size = file.size();
  }
  if(arg.getRgb_Pic())
  {
    size += file.size() * 3;
  }
  if(arg.getGray_Pic())
  {
    size +=file.size() * 3 * IntPow(2,arg.getSplit_Gray());
  }
  return size;
}

int Progress::getSecondMethodSplitFileSize()
{
  int size = 0;
  QFileInfo file(fileName);
  if(arg.getRgb_Pic())
  {
    size = file.size() * 3;
    if(arg.getSplit_Pic())
    {
      size = size * 2;
    }
    if(arg.getGray_Pic())
    {
      size += file.size() * 3 * IntPow(2,arg.getSplit_Gray());
    }
  }else
  {
    if(arg.getSplit_Pic())
    {
      size = file.size();
    }
  }
  return size;
}

int Progress::getThirdMethodSplitFileSize()
{
  int size = 0;
  QFileInfo file(fileName);
  if(arg.getRgb_Pic())
  {
    size = file.size() * 3;
    if(arg.getGray_Pic())
    {
      size += file.size() * 3 * IntPow(2,arg.getSplit_Gray());
      if(arg.getSplit_Pic())
      {
        size +=file.size() * 3 * IntPow(2,arg.getSplit_Gray());
      }
    }else
    {
      if(arg.getSplit_Pic())
      {
        size = size * 2;
      }
    }
  }else
  {
    if(arg.getSplit_Pic())
    {
      size = file.size();
    }
  }
  return size;
}

void Progress::setPathName(QString filename)
{
  ui.lbFileName->setText(filename);
  if(flag == 0)
  {
    QDir dir;
    QString path = dir.currentPath();
    this->fileName = filename;
    int pos = filename.lastIndexOf("/");
    filename.remove(0,pos + 1);
    this->pathName =path +"/" + filename;
  }else
  {
      this->pathName = filename;
  }
}
void Progress::setFlag(int value)
{
  this->flag = value;
}

void Progress::setArg(const SPLITArg &arg)
{
  this->arg = arg;
}

void Progress::setMergeArg(const MergeArg &arg)
{
  this->mergeArg = arg;
  checkMergeArg();
}

void Progress::setProgressMax()
{
  allFileSize = getSize() ;//获取此次操作的总文件大小
  ui.progress->setMaximum(allFileSize);
}

void Progress::setSplitThread(MySplitThread *split)
{
      this->split = split;
}

void Progress::setMergeThread(MyMergeThread *merge)
{
    this->merge = merge;
}

void Progress::setAutoMergeThread(MyAutoMergeThread *automerge)
{
     this->automerge = automerge;
}

Progress::~Progress()
{
    if(timer) delete timer;
}
