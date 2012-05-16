/**@file
*****************************************************************************
* 版权所有(C) 高迪公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#ifndef BROWSEPICTURE_H
#define BROWSEPICTURE_H

#include <QtGui/QMainWindow>
#include "ui_browsepicture.h"
#include "MyAutoMergeThread.h"
#include "MyMergeThread.h"
#include "MySplitThread.h"
#include "Argument.h"
#include "progress.h"
class View;
class PicBlock;
class SplitDlg;
/**
* @brief 图片浏览程序，此类为主界面，显示布局
* @author Hero
* @date 2011年8月4日
*/
class BrowsePicture : public QWidget
{
  Q_OBJECT

public:
  BrowsePicture(QWidget *parent = 0, Qt::WFlags flags = 0);
  ~BrowsePicture();
  /**
  * @brief 清除Merge目录下的文件
  * @return void 
  */
  void clearDir(QString path);
public slots:
  /**
  * @brief 响应打开触发
  * @return void 
  */
  void OpenActTriggered();
  /**
  * @brief 响应关闭触发
  * @return void 
  */
  void ExitActTriggered();
  /**
  * @brief 
  * @return void 
  */
  void OpenButtonClicked();
  /**
  * @brief 
  * @return void 
  */
  void SplitButtonClicked();
  /**
  * @brief 
  * @return void 
  */
  void OpenDirButtonClicked();
  /**
  * @brief 
  * @return void 
  */
  void ShowPicButtonClicked();
  /**
  * @brief 
  * @return void 
  */
  void AutoMergeButtonClicked();
  void splitPic(QString filename,const SPLITArg &arg);
  /*显示处理合并完得图像*/
  void ShowDonePicture(QString);
  void doneSuccess();
  void doneFail();
  bool ShowThumbnail(QString filename);
private:
  /**
  * @brief 初始化设置
  */
  void Init();
  /**
  * @brief 系统事件
  * @param [in] event
  */
  void resizeEvent(QResizeEvent *event);
  /**
  * @brief 打开文件
  */
  void OpenDir();
  QString OpenFile();
  /**
  * @brief 打开分割图片对话框
  * @return void 
  */
  void OpenSplitDialog();
  /**
  * @brief 显示设定好的图片
  * @return void 
  */
  void ShowImage();
  /**
  * @brief 读取信息文件
  * @param [in] path 
  * @return bool 
  */
  bool ReadFile(const QString &path);
  /**
  * @brief 给手动合并传参数
  * @param [in] thead 
  * @return void 
  */
  void setMergeThread(MyMergeThread *thead);
private:
  QString pic_path;
  Ui::BrowsePictureClass ui;
  SPLIT mSpliter;
  View *viewport;
  QGraphicsScene *scene;
  PicBlock *item;
  //PicBlock *item;
  //QGraphicsItem *item;
  SPLITArg arg; 
  
    /**<@brief  因为线程是动态生成的  开辟空间后加入到队列中  在执行结束时释放掉   doSuccess中做的*/
  QList<MySplitThread *> splitthread_list;
  QList<Progress*>splitprogress_list;//进度条的队列
  QList<MyMergeThread*>mergethread_list;
  QList<Progress*>mergeprogress_list;
  QList<MyAutoMergeThread*>automergethread_list;
  QList<Progress*>automergeprogress_list;
};

#endif // BROWSEPICTURE_H
