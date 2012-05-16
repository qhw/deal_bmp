/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#ifndef  MYMERGETHREAD_H_
#define  MYMERGETHREAD_H_

#include "gaodi.h"
/**
* 线程操作图像自动合并的
* @author Eric
* @date 2011-8-18
*/
class MyMergeThread:public QThread
{
  Q_OBJECT
public:
  MyMergeThread(void);
  void run();
  ~MyMergeThread(void);
  void setPath(QString);

  /**
  * 设置手动合并图像设置的参数
  * @author Eric
  * @date 2011-8-26
  */
 void setMergeArg(const MergeArg &mergeArg);
 MergeArg getMergeArg();
    /**
  * 设置分割图像时记录的参数
  * @author Eric
  * @date 2011-8-26
  */
  void setArg(SPLITArg arg);
signals:
  void done();
  void showpic(QString);//显示处理完毕的图片
  void showDoingPic(QString);//显示正在处理的图片
  public slots:
    void MergePic();
private:
  /************************************************************************/
  /* split->rgb->gray方式分割后按照给定方式显示
  */
  /************************************************************************/
  bool mergePicByCondition_FirstMethod(const SPLIT &m_split);
  bool mergePicByCondition_FirstSplit(SPLIT m_split);
  bool mergePicByCondition_rgb(const SPLIT &m_split);
  bool mergePicByCondition_gray(const SPLIT &m_split);
  bool mergePicByCondition_Split(const SPLIT &m_split);
  /************************************************************************/
  /* rgb->split->gray方式分割后按照给定方式显示
  */
  /************************************************************************/
  bool mergePicByCondition_SecondMethod(const SPLIT &m_split);
  /************************************************************************/
  /* rgb->gray->split方式分割后按照给定方式显示
  */
  /************************************************************************/
  bool mergePicByCondition_ThirdMethod(const SPLIT &m_split);
private:
  SPLIT mSpliter;
  
  QString pic_path;

  MergeArg mergeArg;  /**<@brief  手动合并图像时 设置的参数*/

  SPLITArg arg;  /**<@brief  分割时记录的参数*/

};
#endif