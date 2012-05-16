/**@file
*****************************************************************************
* ��Ȩ����(C) ???��˾ CopyRight(2011 - ...)
* @brief ����ժҪ:
* @date 2011/08/23
* @note  �޸ļ�¼: 
1.�޸�ע�͸�ʽ,��tabת��Ϊ2���ո� [2011/08/23 15:34 fox]
********************************************************************************/
#ifndef  MYMERGETHREAD_H_
#define  MYMERGETHREAD_H_

#include "gaodi.h"
/**
* �̲߳���ͼ���Զ��ϲ���
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
  * �����ֶ��ϲ�ͼ�����õĲ���
  * @author Eric
  * @date 2011-8-26
  */
 void setMergeArg(const MergeArg &mergeArg);
 MergeArg getMergeArg();
    /**
  * ���÷ָ�ͼ��ʱ��¼�Ĳ���
  * @author Eric
  * @date 2011-8-26
  */
  void setArg(SPLITArg arg);
signals:
  void done();
  void showpic(QString);//��ʾ������ϵ�ͼƬ
  void showDoingPic(QString);//��ʾ���ڴ����ͼƬ
  public slots:
    void MergePic();
private:
  /************************************************************************/
  /* split->rgb->gray��ʽ�ָ���ո�����ʽ��ʾ
  */
  /************************************************************************/
  bool mergePicByCondition_FirstMethod(const SPLIT &m_split);
  bool mergePicByCondition_FirstSplit(SPLIT m_split);
  bool mergePicByCondition_rgb(const SPLIT &m_split);
  bool mergePicByCondition_gray(const SPLIT &m_split);
  bool mergePicByCondition_Split(const SPLIT &m_split);
  /************************************************************************/
  /* rgb->split->gray��ʽ�ָ���ո�����ʽ��ʾ
  */
  /************************************************************************/
  bool mergePicByCondition_SecondMethod(const SPLIT &m_split);
  /************************************************************************/
  /* rgb->gray->split��ʽ�ָ���ո�����ʽ��ʾ
  */
  /************************************************************************/
  bool mergePicByCondition_ThirdMethod(const SPLIT &m_split);
private:
  SPLIT mSpliter;
  
  QString pic_path;

  MergeArg mergeArg;  /**<@brief  �ֶ��ϲ�ͼ��ʱ ���õĲ���*/

  SPLITArg arg;  /**<@brief  �ָ�ʱ��¼�Ĳ���*/

};
#endif