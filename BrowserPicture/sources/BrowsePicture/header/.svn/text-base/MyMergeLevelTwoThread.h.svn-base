/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  Eric 
* @date 2011/08/24
* @note  修改记录:
********************************************************************************/

#ifndef  MYMERGELEVELTWOTHREAD_H_
#define  MYMERGELEVELTWOTHREAD_H_

#include "gaodi.h"
/** 
* @brief 线程操作图像RGB分离的
* @author Eric
* @date 2011-8-24
*/
class MyMergeLevelTwoThread:public QThread
{
  Q_OBJECT
public:
  MyMergeLevelTwoThread(void);
  void run();
  void setSpliter(const SPLIT &m_split);
  void setPicPath(const QStringList &pic_path);
  void setDealFlag(int flag);
  void setMergeArg(const MergeArg &arg);
  ~MyMergeLevelTwoThread(void);
signals:
  void done();
  void fail();
  void showpic(QString);//显示处理完毕的图片
  void showDoingPic(QString);//显示正在处理的图片
 
private:
  QStringList path_list;  /**<@brief  线程合并的图片的路径的列表*/
  SPLIT  mSpliter;
  int dealFlag;  /**<@brief  当前线程合并类别*/

  MergeArg arg;

};
#endif