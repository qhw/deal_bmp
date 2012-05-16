/**@file
*****************************************************************************
* ��Ȩ����(C) ???��˾ CopyRight(2011 - ...)
* @brief ����ժҪ:
* @date 2011/08/23
* @note  �޸ļ�¼: 
1.�޸�ע�͸�ʽ,��tabת��Ϊ2���ո� [2011/08/23 15:34 fox]
********************************************************************************/
#ifndef  MYAUTOMERGETHREAD_H_
#define  MYAUTOMERGETHREAD_H_

#include "gaodi.h"
/**
* �̲߳���ͼ���Զ��ϲ���
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
  * ����ͼ��ָ�ʱ��¼����Ϣ
  * @author Eric
  * @date 2011-8-25
  */
  void setArg(SPLITArg arg);

signals:
  void done();
  void showpic(QString);//��ʾ������ϵ�ͼƬ
  void showDoingPic(QString);//��ʾ���ڴ����ͼƬ
public slots:
  void autoMergePic();
private:
  /**
  * @brief split->rgb->gray �ϲ�
  * @param [in] m_split 
  * @return bool 
  */
  bool automergePicByFirstMethod(const SPLIT &m_split);
  bool automergePicBySplit(SPLIT m_split);
  bool automergePicByrgb(const SPLIT &m_split);
  bool automergePicBygray(const SPLIT &m_split);
  /**
  * @brief rgb->split->gray�ϲ�
  * @param [in] m_split 
  * @return bool 
  */
  bool automergePicBySecondMethod(const SPLIT &m_split);
  bool automergePicBySecondMethod_Split(const SPLIT &m_split);
  /**
  * @brief rgb->gray->split �ϲ�
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