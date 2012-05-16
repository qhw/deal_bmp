/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  Eric 
* @date 2011/08/24
* @note  修改记录:
********************************************************************************/

#ifndef  MYSPLITLEVELTWOTHREAD_H_
#define  MYSPLITLEVELTWOTHREAD_H_

#include "gaodi.h"
/** 
* @brief 线程操作图像灰度分离的
* @author Eric
* @date 2011-8-24
*/
class MySplitLevelTwoThread:public QThread
{
  Q_OBJECT
public:
  MySplitLevelTwoThread(void);
  void run();
  void setSpliter(const SPLIT &m_split);
  /** 
  * @brief 设置线程操作的图片的列表
  * @author Eric
  * @date 2011-8-24
  */
  void setPicPath(const QStringList &pic_path);
  /** 
  * @brief 设置线程操作图像参数
  * @author Eric
  * @date 2011-8-24
  */
  void setArg(const SPLITArg &arg);
  /** 
  * @brief 设置线程操作图像的类别
  * @author Eric
  * @date 2011-8-24
  */
  void setDealFlag(int flag); 
  ~MySplitLevelTwoThread(void);
signals:
  void done();
  void fail();
  void showpic(QString);//显示处理完毕的图片
  void showDoingPic(QString);//显示正在处理的图片
 
private:
  QStringList path_list;  /**<@brief  处理图片的路径列表*/
  SPLIT  mSpliter;

    SPLITArg arg;  /**<@brief  图像处理的参数*/
    /**<@brief  为0时进行的是分割 ，为1时进行的是rgb分离， 为2时进行的是灰度分离*/
  int dealFlag;  /**<@brief  处理类型  */

};
#endif