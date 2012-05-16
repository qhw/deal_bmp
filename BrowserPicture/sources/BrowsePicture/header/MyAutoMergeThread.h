/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#ifndef  MYAUTOMERGETHREAD_H_
#define  MYAUTOMERGETHREAD_H_

#include "gaodi.h"
/**
* 线程操作图像自动合并的
* @author Eric
* @date 2011-8-18
*/
class MyAutoMergeThread:public QThread
{
  Q_OBJECT
public:
  MyAutoMergeThread(void);
  ~MyAutoMergeThread(void);
  void run();
  void setPath(QString);
    /**
  * 设置图像分割时记录的信息
  * @author Eric
  * @date 2011-8-25
  */
  void setArg(SPLITArg arg);

signals:
  void done();
  void showpic(QString);//显示处理完毕的图片
  void showDoingPic(QString);//显示正在处理的图片
public slots:
  void autoMergePic();
private:
  /**
  * @brief split->rgb->gray 合并
  * @param [in] m_split 
  * @return bool 
  */
  bool automergePicByFirstMethod(const SPLIT &m_split);
  bool automergePicBySplit(SPLIT m_split);
  bool automergePicByrgb(const SPLIT &m_split);
  bool automergePicBygray(const SPLIT &m_split);
  /**
  * @brief rgb->split->gray合并
  * @param [in] m_split 
  * @return bool 
  */
  bool automergePicBySecondMethod(const SPLIT &m_split);
  bool automergePicBySecondMethod_Split(const SPLIT &m_split);
  /**
  * @brief rgb->gray->split 合并
  * @param [in] m_split 
  * @return bool 
  */
  bool automergePicByThirdMethod(const SPLIT &m_split);
private:
  SPLIT mSpliter;
  QString pic_path;

  SPLITArg arg;
};
#endif