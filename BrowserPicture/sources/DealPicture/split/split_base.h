/**@file
*****************************************************************************
* ��Ȩ����(C) �ߵ�δ��(����)�Ƽ����޹�˾ CopyRight(2011 - ...)
* @brief ����ժҪ:
* @author  ��ҫ�� (duyaokun@foxmail.com)
* @date 2011/08/31
* @note  �޸ļ�¼:
********************************************************************************/
#ifndef SPLIT_BASE_H__33AACBFC_33AB_4829_B9CF_585167D0C167
#define SPLIT_BASE_H__33AACBFC_33AB_4829_B9CF_585167D0C167
#include <boost/thread.hpp>
#include "split/split_define.h"

/**namespace split*/
namespace split
{
extern std::string BLANK_STRING;
/**
* @brief 
*/
class SPLIT_EXPORT SplitBase : public SplitNoncopyable
{
public:
  /**
  * @brief 
  */
  virtual ~SplitBase()
  {
    if(running_)
    {
      throw("running_");
    }
  }
  /**
  * @brief ��ʼ����ͼ��
  * @return void 
  */
  virtual void Start(bool thread = false)
  {
    running_ = true;
    if(thread) main_thread_ = boost::thread(boost::BOOST_BIND(&SplitBase::Run, this));
    else Run();
  }
  /**
  * @brief 
  * @return bool 
  */
  bool IsEnd()const{ return !running_;}
  /**
  * @brief �ȴ��������
  * @return void 
  */
  void WaitForEnd()
  {
    main_thread_.join();
  }
  /**
  * @brief ��ȡ��ɽ���
  * @return float ��ɽ���
  */
  float Completed_schedule() const 
  { 
    boost::mutex::scoped_lock lock(completed_schedule_mutex_);
    return completed_schedule_; 
  }
  /**
  * @brief ��ȡ�����ͼƬ��·��
  * @param [in] key ��Ҫ��ȡ��ͼƬ·���Ķ�Ӧ�ؼ���
  * @return Path ͼƬ·��,��������᷵��"".
  */
  Path GetPath(const std::string& key)
  {
    const FileNameMap::iterator _result = save_paths_.find(key);
    return _result == save_paths_.end() ? BLANK_STRING : _result->second;
  }
protected:
  /**
  * @brief 
  */
  explicit SplitBase(const Path& file_name) : SplitNoncopyable(), completed_schedule_(0.0f), picture_name_(file_name), running_(false)
  {}
  /**
  * @brief 
  * @return void 
  */
  virtual void Run(){};// = 0;
  /**
  * @brief ������ɽ���
  * @param [in] val ��ɽ���
  * @return void 
  */
  void Completed_schedule(float val) 
  { 
    boost::mutex::scoped_lock lock(completed_schedule_mutex_);
    completed_schedule_ = ceil(val * 1000) * 0.001f;
  }
protected:
  const Path picture_name_;  /**<@brief Ҫ������ͼƬ����*/
  FileNameMap save_paths_;  /**<@brief ���������������ļ������б�*/
  bool running_;
private:
  float completed_schedule_;  /**<@brief ��ɽ���[0,1]*/
  boost::thread main_thread_;  /**<@brief ����ͼ������߳�.*/
  mutable boost::mutex completed_schedule_mutex_;  /**<@brief �߳���.*/
};

}//end of namespace split
#endif//SPLIT_BASE_H__33AACBFC_33AB_4829_B9CF_585167D0C167
