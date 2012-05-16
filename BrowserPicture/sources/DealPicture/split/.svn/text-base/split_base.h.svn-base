/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  杜耀坤 (duyaokun@foxmail.com)
* @date 2011/08/31
* @note  修改记录:
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
  * @brief 开始处理图像
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
  * @brief 等待处理完毕
  * @return void 
  */
  void WaitForEnd()
  {
    main_thread_.join();
  }
  /**
  * @brief 获取完成进度
  * @return float 完成进度
  */
  float Completed_schedule() const 
  { 
    boost::mutex::scoped_lock lock(completed_schedule_mutex_);
    return completed_schedule_; 
  }
  /**
  * @brief 获取处理后图片的路径
  * @param [in] key 需要获取的图片路径的对应关键字
  * @return Path 图片路径,不存在则会返回"".
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
  * @brief 更新完成进度
  * @param [in] val 完成进度
  * @return void 
  */
  void Completed_schedule(float val) 
  { 
    boost::mutex::scoped_lock lock(completed_schedule_mutex_);
    completed_schedule_ = ceil(val * 1000) * 0.001f;
  }
protected:
  const Path picture_name_;  /**<@brief 要操作的图片名称*/
  FileNameMap save_paths_;  /**<@brief 经过操作后生成文件名称列表*/
  bool running_;
private:
  float completed_schedule_;  /**<@brief 完成进度[0,1]*/
  boost::thread main_thread_;  /**<@brief 处理图像的主线程.*/
  mutable boost::mutex completed_schedule_mutex_;  /**<@brief 线程锁.*/
};

}//end of namespace split
#endif//SPLIT_BASE_H__33AACBFC_33AB_4829_B9CF_585167D0C167
