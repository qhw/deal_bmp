/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#include "StdAfx.h"
#include "managepic.h"

ManagePic::ManagePic(QObject *parent)
: QObject(parent)
{

}

ManagePic::~ManagePic()
{

}

QString ManagePic::FindDir(const QString& folder_path,const QString & folder_name)
{
  QDir dir(folder_path);

  dir.setFilter(QDir::Dirs);
  QFileInfoList list = dir.entryInfoList();
  if (list.size() == 0)
  {
    return 0;
  }
  int i = 0;
  do{
    QFileInfo fileInfo = list.at(i);
    QString str = fileInfo.fileName();
    if(str.contains(folder_name))
    {
      return fileInfo.filePath();
    } 
    else if(str != "." && str != "..")
    {
      QString str_path = FindDir(fileInfo.filePath(), folder_name);
      if (str_path != 0)
      {
        return str_path;
      }
    }
    i++;
  }while(i<list.size());

  return 0;
}
QStringList ManagePic::FindFile(const QString &folder_name)
{
  QStringList name_list;

  QDir dir(folder_name);
  if (!dir.exists())
  {
    dir.setPath(FindDir("../",folder_name));
  } 
  dir.setFilter(QDir::Files);
  dir.setSorting(QDir::DirsFirst);

  name_list << dir.path();
  QFileInfoList list = dir.entryInfoList();
  if (list.size() == 0)
  {
    return name_list;
  }
  int i = 0;
  do{

    QFileInfo fileInfo = list.at(i);

    if(fileInfo.fileName() == "." | fileInfo.fileName() == ".." 
      || fileInfo.fileName().contains(".db"))
    {
      i++;
      continue;
    }
    //name_list<<fileInfo.absoluteFilePath();
    //name_list<< fileInfo.filePath();
    name_list<< fileInfo.fileName();
    i++;
  }while(i<list.size());
  return name_list;
}


bool ManagePic::CreateDiretory(QString path,QString dirname)
{
  QDir dir(path + "/" + dirname);
  if(!dir.exists())
  {
    if(dir.mkdir(path +"/" +dirname))
    {
      return true;
    }else
    {
      return false;
    }
  }
  return true;
}

bool ManagePic::removeFile(QString pathName)
{
  QStringList fileList = FindFile(pathName);
  QDir dir(pathName);
  for(int i = 1; i < fileList.size(); i++)
  {
      if(!dir.remove(fileList[0] +"/" +fileList[i]))
        return false;
  }
  return true;
}
bool ManagePic::CreateDealPictureDirectory(QString path,QString filename)
{
  if(CreateDiretory(path,filename))
  {
    if(CreateDiretory(path,filename +"/split"))
    {
      if(!CreateDiretory(path,filename +"/split/split"))
      {
        QMessageBox msg;
        msg.setText("创建文件夹失败!");
        msg.exec();
        return false;
      }else
      {
        removeFile(path + "/" + filename + "/split/split");
      }
      if(!CreateDiretory(path,filename +"/split/rgb"))
      {
        QMessageBox msg;
        msg.setText("创建文件夹失败!");
        msg.exec();
        return false;
      }else
      {
        removeFile(path + "/" + filename + "/split/rgb");
      }
      if(!CreateDiretory(path,filename +"/split/gray"))
      {
        QMessageBox msg;
        msg.setText("创建文件夹失败!");
        msg.exec();
        return false;
      }else
      {
        removeFile(path + "/" + filename + "/split/gray");
      }
    }
    if(CreateDiretory(path,filename +"/Merge"))
    {
      if(!CreateDiretory(path,filename +"/Merge/split"))
      {
        QMessageBox msg;
        msg.setText("创建文件夹失败!");
        msg.exec();
        return false;
      }else
      {
        removeFile(path + "/" + filename + "/Merge/split");
      }
      if(!CreateDiretory(path,filename +"/Merge/rgb"))
      {
        QMessageBox msg;
        msg.setText("创建文件夹失败!");
        msg.exec();
        return false;
      }else
      {
        removeFile(path + "/" + filename + "/Merge/rgb");
      }
      if(!CreateDiretory(path,filename +"/Merge/gray"))
      {
        QMessageBox msg;
        msg.setText("创建文件夹失败!");
        msg.exec();
        return false;
      }else
      {
        removeFile(path + "/" + filename + "/Merge/gray");
      }

      QDir dir(path +"/" + filename);
      dir.remove(path + "/" + filename + "/Merge/" + filename);
      dir.remove(path + "/" + filename +"/log.txt");
    }
  }
  return true;
}