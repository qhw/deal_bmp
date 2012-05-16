/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#include "StdAfx.h"
#include "splitdlg.h"
#include "managepic.h"

SplitDlg::SplitDlg(QWidget *parent)
: QDialog(parent),
saveinfo(false)
{
  Init();
}

void SplitDlg::Init()
{
  ui.setupUi(this);
  SetConnect();
}
void SplitDlg::ShutDown()
{

}
SplitDlg::~SplitDlg()
{

}
void SplitDlg::SetConnect()
{
  connect(ui.ok_btn,SIGNAL(clicked()),this, SLOT(ButtonClicked()));
  connect(ui.open_btn,SIGNAL(clicked()),this,SLOT(ButtonClicked()));
  connect(ui.rgb_box,SIGNAL(toggled(bool)),this,SLOT(setGreyBox(bool)));
}

void SplitDlg::setGreyBox(bool flag)//当rgb被取消时自动取消灰度的被选中状态
{
  if(flag == false)
  {
    if(ui.grey_box->isChecked())
    {
      ui.grey_box->setChecked(false);	
    }
  }
}
void SplitDlg::SpinBoxSetValue(int)
{
  QSpinBox *sbox = qobject_cast <QSpinBox*>(sender());
  if(!sbox)
    return;
  if (sbox == ui.col_spinbox)
  {
      ui.width_spinbox->setValue(fileinfo.pic_width/sbox->value());
  }
  else   if (sbox == ui.row_spinbox)
  {
      ui.height_spinbox->setValue(fileinfo.pic_height/sbox->value());
  }
  else   if (sbox == ui.width_spinbox)
  {
    ui.row_spinbox->setValue(fileinfo.pic_width/sbox->value());
  }
  else   if (sbox == ui.height_spinbox)
  {
    ui.col_spinbox->setValue(fileinfo.pic_height/sbox->value());
  }
}

void SplitDlg::ButtonClicked()
{
  QPushButton*btn = qobject_cast <QPushButton*>(sender());
  if(!btn)
    return;
  if (btn == ui.ok_btn)
  {
    if(fileinfo.pic_height%ui.row_spinbox->value() != 0 || fileinfo.pic_width%ui.col_spinbox->value() != 0)
    {
      ui.row_spinbox->setValue(1);
      ui.col_spinbox->setValue(1);
      QMessageBox msg;
      msg.setWindowTitle("不能整除");
      msg.setText("不能被文件高度或宽度整除!");
      msg.exec();
      return;
    }
    saveinfo = true;
    QDir dir;
    QString path = dir.currentPath();
    ManagePic managePic;
    int pos = fileinfo.file_name.lastIndexOf ("/",-1);
    QString filename=fileinfo.file_name;
    filename.remove(0,pos +1);//获取文件的名
    managePic.CreateDealPictureDirectory(path,filename);//创建需要的文件夹
    if(DealPicture())
    {
      WriteFile(path);
      close();
    }
  }
  else if (btn == ui.open_btn)
  {
    QString filename = OpenFile();
    ui.path_edit->setText(filename);
    //@TODO如果没能打开，则设置下面的控件不可编辑
    if (!filename.isEmpty())
    {
      GetFileInfo(filename);
    } 
  }
}
QString SplitDlg::OpenFile()
{
  QString dir = "../";
  QString filter = "bmp Files (*.bmp)\nAllfiles(*.*)";
  QString filename = QFileDialog :: getOpenFileName (this, "打开图片文件",dir ,filter );
  return filename;
}

void SplitDlg::GetFileInfo(QString filename)
{
  fileinfo;
  SPLIT m_split;
  BMIH bmih = m_split.getBMIH((const char *)filename.toLocal8Bit());
  BMFH bmfh = m_split.getBMFH((const char *)filename.toLocal8Bit());
  fileinfo.pic_height = bmih.biHeight;
  fileinfo.pic_width = bmih.biWidth;
  fileinfo.file_name = filename;
  fileinfo.pic_size = bmfh.bfSize;
  /************************************************************************/
  /*@设置复选框可选 
  */
  /************************************************************************/
  ui.geometry_box->setEnabled(true);
  ui.rgb_box->setEnabled(true);
  ui.radio_method1_btn->setEnabled(true);
  ui.radio_method2_btn->setEnabled(true);
  ui.radio_method3_btn->setEnabled(true);
  ui.ok_btn->setEnabled(true);
  /************************************************************************/
  /*@设置spinbox值 
  */
  /************************************************************************/
  ui.width_spinbox->setValue(fileinfo.pic_width);
  ui.height_spinbox->setValue(fileinfo.pic_height);
  /************************************************************************/
  /*@设置行列变化和图片宽度变化之间的联系 
  */
  /************************************************************************/
  connect(ui.row_spinbox,SIGNAL(valueChanged(int)),this,SLOT(SpinBoxSetValue(int)));
  connect(ui.col_spinbox,SIGNAL(valueChanged(int)),this,SLOT(SpinBoxSetValue(int)));
  //connect(ui.width_spinbox,SIGNAL(valueChanged(int)),this,SLOT(SpinBoxSetValue(int)));
  //connect(ui.height_spinbox,SIGNAL(valueChanged(int)),this,SLOT(SpinBoxSetValue(int)));
}

bool SplitDlg::DealPicture()//处理图片
{
  if(ui.radio_method1_btn->isChecked())
  {
    arg.setMethod(0);
  }else if(ui.radio_method2_btn->isChecked())
  {
    arg.setMethod(1);
  }else if(ui.radio_method3_btn->isChecked())
  {
    arg.setMethod(2);
  }
  arg.setSplit_Row(ui.row_spinbox->value());
  arg.setSplit_Col(ui.col_spinbox->value());
  arg.setSplit_Gray(ui.grey_combox->currentText().toInt());
  int geo,rgb,gray;
  if(ui.geometry_box->isChecked())
  {
    geo = 1;
  }else
  {
    geo = 0;
  }
  if(ui.rgb_box->isChecked())
  {
    rgb  =1;
  }
  else{
    rgb =0;
  }
  if(ui.grey_box->isChecked())
  {
    gray =1;
  }
  else
  {
    gray = 0;
  }
  if(geo== 0 && rgb == 0 && gray == 0)
  {
    QMessageBox msg;
    msg.setText("没有选择要进行的操作!");
    msg.exec();
    return false;
  }
  arg.setSplit_Pic(geo);
  arg.setRgb_Pic(rgb);
  arg.setGray_Pic(gray);
  emit startSplitPic(fileinfo.file_name,arg);
  return true;
}

void SplitDlg::WriteFile(QString path)
{
  ManagePic managePic;
  int pos = fileinfo.file_name.lastIndexOf ("/",-1);
  QString filename=fileinfo.file_name;
  filename.remove(0,pos +1);//获取文件的名
  QFile file(path +"/" + filename + "/log.txt");
  QString m  = QString::number(arg.getMethod());
  QString geo =" " +QString::number(arg.getSplit_Pic());
  QString rgb =" " +QString::number(arg.getRgb_Pic());
  QString gray =" " +QString::number(arg.getGray_Pic());
  QString splitRow =" " + ui.row_spinbox->text();
  QString splitCol =" " +  ui.col_spinbox->text();
  QString splitGray =" " + ui.grey_combox->currentText();
  file.open(QIODevice::ReadWrite);
  file.write(m.toLatin1().data());
  file.write(geo.toLatin1().data());
  file.write(rgb.toLatin1().data());
  file.write(gray.toLatin1().data());
  file.write(splitRow.toLatin1().data());
  file.write(splitCol.toLatin1().data());
  file.write(splitGray.toLatin1().data());
  file.close();
}