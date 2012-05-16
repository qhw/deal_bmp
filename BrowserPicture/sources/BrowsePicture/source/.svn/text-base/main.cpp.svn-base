/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#include "stdafx.h"
#include "browsepicture.h"
#include <QtGui/QApplication>
#include <QTextCodec>
#include "split/split_picture.h"
#include "split/split_rgb.h"
#include "split/split_gray.h"
#include <boost/foreach.hpp>

int main(int argc, char *argv[])
{
#if 1
  split::SplitDesc _desc;
  _desc.path = "../sin.bmp";//bih.bmp";//test.bmp";//
  _desc.colum = 1;
  _desc.row = 2;
  _desc.gray = 2;
  _desc.steps.push_back(split::SS_SPLIT);
  _desc.steps.push_back(split::SS_RGB);
  _desc.steps.push_back(split::SS_GRAY);
  split::DoSplitNoThread(_desc);
  _desc.steps.pop_front();
  _desc.steps.push_back(split::SS_SPLIT);
  split::DoSplitNoThread(_desc);
#endif

  QApplication a(argc, argv);

  QApplication::addLibraryPath("plugins");//在其他机子上显示图片

  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("System"));
  QTextCodec::setCodecForLocale(QTextCodec::codecForName("System"));
  QTextCodec::setCodecForTr(QTextCodec::codecForName("System"));

  BrowsePicture w;
 // w.setObjectName("BrowsePicture");
  //ShowPicture w;
   // w.setStyleSheet(QString::fromUtf8("border-image: url(:/images/hehua.png); "));
  w.show();
  return a.exec();
}
