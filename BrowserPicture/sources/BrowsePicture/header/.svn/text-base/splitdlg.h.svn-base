/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#ifndef SPLIT_H
#define SPLIT_H

#include<QFile>
#include <QDialog>
#include "ui_SplitDialog.h"
#include "split/SPLIT.h"
#include "Argument.h"
struct FileInfo
{
  QString  file_name;
  int pic_width;
  int pic_height;
  long pic_size;//3M大小
};

/**
* @brief 分割图片的对话框
* @author hero
* @date 2011年8月8日
*/
class SplitDlg : public QDialog
{
  Q_OBJECT

public:
  SplitDlg(QWidget *parent=0);
  ~SplitDlg();

  Ui::UiSplitDialog ui;
signals:
  void startSplitPic(QString filename,const SPLITArg &arg);
private slots:
  void ButtonClicked();
  void SpinBoxSetValue(int);
  void setGreyBox(bool);
  /**
  * @brief 图像操作函数
  * @return bool
  */
  bool DealPicture();
  /**
  * @brief 初始化设置
  * @return void 
  */
  void Init();
  /**
  * @brief 清理设置
  * @return void 
  */
  void ShutDown();
  /**
  * @brief 设置信号和槽的连接
  * @return void 
  */
  void SetConnect();
  /**
  * @brief 打开文件对话框，找到图片，返回路径
  * @return QString 返回路径
  */
  QString OpenFile();
  /**
  * @brief 根据打开图片后的信息设置对话框的控件的可选范围，比如根据分割的块数,计算每块的长宽
  * @param [in] filename 
  * @return void 
  */
  void GetFileInfo(QString filename);
  /**
  * @brief 记录分割的信息
  * @param [in] path 
  * @return void 
  */
  void WriteFile(QString path);
private:
  bool saveinfo;//确认是否保存信息  
  FileInfo fileinfo;
  SPLITArg arg;
};

#endif // SPLIT_H
