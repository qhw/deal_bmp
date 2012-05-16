/**@file
*****************************************************************************
* ��Ȩ����(C) ???��˾ CopyRight(2011 - ...)
* @brief ����ժҪ:
* @date 2011/08/23
* @note  �޸ļ�¼: 
1.�޸�ע�͸�ʽ,��tabת��Ϊ2���ո� [2011/08/23 15:34 fox]
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

  QApplication::addLibraryPath("plugins");//��������������ʾͼƬ

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
