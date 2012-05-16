/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  Eric 
* @date 2011/08/24
* @note  修改记录:
********************************************************************************/

#ifndef  MYAUTOMERGELEVELTWOTHREAD_H_
#define  MYAUTOMERGELEVELTWOTHREAD_H_

#include "gaodi.h"
/** 
* @brief 线程操作图像RGB分离的
* @author Eric
* @date 2011-8-24
*/
class MyAutoMergeLevelTwoThread:public QThread
{
  Q_OBJECT
public:
  MyAutoMergeLevelTwoThread(void);
  void run();
  void setSpliter(const SPLIT &m_split);
  /** 
  * @brief 线程操作图像路径的列表
  * @author Eric
  * @date 2011-8-24
  */
  void setPicPath(const QStringList &pic_path);
  /** 
  * @brief 线程操作图像的合并的类别
  * @author Eric
  * @date 2011-8-24
  */
  void setDealFlag(int flag);
  ~MyAutoMergeLevelTwoThread(void);
signals:
  void done();
  void fail();
  void showpic(QString);//显示处理完毕的图片
  void showDoingPic(QString);//显示正在处理的图片
 
private:
  QStringList path_list;  /**<@brief  图像合并的图像路径列表*/
  SPLIT  mSpliter;
  int dealFlag;  /**<@brief  图像合并的类别*/

};
#endif