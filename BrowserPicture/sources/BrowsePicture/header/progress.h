#ifndef PROGRESS_H
#define PROGRESS_H

#include <QWidget>
#include "ui_progress.h"
#include "Argument.h"
#include <QTimer>
class MySplitThread;
class MyMergeThread;
class MyAutoMergeThread;
class Progress : public QWidget
{
    Q_OBJECT

public:
    Progress(QWidget *parent = 0);
    void setArg(const SPLITArg &arg);
    void setMergeArg(const MergeArg &arg);
    void setFlag(int value);//设置正在处理的类型
    void setPathName(QString filename);//设置处理的文件名和路径
    void setProgressMax();//设置进度条最大值
  
    void setSplitThread(MySplitThread *split);
    void setMergeThread(MyMergeThread *merge);
    void setAutoMergeThread(MyAutoMergeThread *automerge);

    QString FormatTime(int left, int size);//格式化剩余的时间
    int getSize();//获取一共需要操作的字节数

    int getSplitFileSize();//获取图像分割以及通道分离时一共要操作的字节数
    int getFirstMethodSplitFileSize();
    int getSecondMethodSplitFileSize();
    int getThirdMethodSplitFileSize();

    int getAutoMergeFileSize();//获取自动合并的文件大小
    int getAutoMergeFirstMethodFileSize();
    int getAutoMergeSecondMethodFileSize();
    int getAutoMergeThirdMethodFileSize();

    int getMergeFileSize();//获取手动合并的文件大小
    int getMergeFirstMethodFileSize();
    int getMergeSecondMethodFileSize();
    int getMergeThirdMethodFileSize();

    int getPathFileSize(QString path,int flag);//获取指定文件夹下所有文件的大小
    int getFileSize(QString filename);//获取指定文件的大小

    void checkMergeArg();//检查手动合并时设置的参数是否有效
    ~Progress();
    public slots:
      void updateProgress();//更新进度条
      void cancelBtn();//响应取消事件
      void closeEvent ( QCloseEvent *event );//关闭时  终止线程并释放线程开辟的空间
      void closeDlg();

public:
  Ui::Progress ui;
private:
    
    SPLITArg arg;  /**<@brief  处理的选项*/
    MergeArg mergeArg;  /**<@brief  手动合并时的选项*/
    QString pathName;  /**<@brief  操作的文件路径*/
    QString fileName;  /**<@brief  几何分割时的文件名*/
    QTimer *timer;  /**<@brief  定时器*/
    int allFileSize;  /**<@brief  需要处理的总文件大小*/

    int lefttime;  /**<@brief  已经用的时间*/
    int flag;  /**<@brief  当前正在处理的类型  0：几何分割   1：rgb分离  2：灰度分离*/

     MySplitThread *split;
     MyMergeThread *merge;
     MyAutoMergeThread *automerge;
};

#endif // PROGRESS_H
