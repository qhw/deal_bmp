/**@file
*****************************************************************************
* 版权所有(C) 高迪公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
2.修改多线程，类基本重写[2010/08/24 14:13 eric]
********************************************************************************/
#ifndef  MYSPLITTHREAD_H_
#define  MYSPLITTHREAD_H_

#include "gaodi.h"
/** 
* @brief 线程操作图像自动合并的
* @author Eric
* @date 2011-8-18
*/
class MySplitThread:public QThread
{
  Q_OBJECT
public:
  MySplitThread(void);
  void run();
  ~MySplitThread(void);
  void setArg(const SPLITArg &arg);
  void setPath(QString);

signals:
  void done();
  void fail();
  void showpic(QString);//显示处理完毕的图片
  void showDoingPic(QString);//显示正在处理的图片
public slots:
  void SplitPic();
private:
  /**
  * @brief split->rgb->gray 顺序的操作  第一种方式
  * @return void 
  */
  void DoneByFirstMethod();
  /**
  * @brief 第一种方式分割后 rgb通道分离
  * @param [in] m_split 
  * @return void 
  */
  void DoneByFirstMethod_RGB(const SPLIT &m_split);
  /**
  * @brief 第一种方式分割后rgb通道分离后 gray操作
  * @param [in] m_split 
  * @param [in] method
  * @return void 
  */
  void DoneByGray(const SPLIT &m_split,int method);
  /**
  * @brief rgb->split->gray 顺序的操作   第二种方式
  * @return void 
  */
  void DoneBySecondMethod();
  /**
  * @brief 第二种方式 rgb分离后 分割操作
  * @param [in] m_split 
  * @param [in] method
  * @param [in] row 
  * @param [in] col 
  * @return void 
  */
  void DoneBySplit(const SPLIT &m_split, int method, int row, int col);
  /**
  * @brief 第二种方式 rgb分离分割操作后的 灰度阶操作
  * @param [in] m_split 
  * @param [in] n 
  * @return void 
  */
 // void DoneBySecondMethod_Gray(SPLIT m_split, int n);
  /**
  * @brief rgb->gray->split 顺序的操作 第三种方式
  * @return void 
  */
  void DoneByThirdMethod();
private:
  QString pic_path;
  SPLITArg arg;

};
#endif