/**@file
*****************************************************************************
* 版权所有(C) ?? CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  杜耀坤 (duyaokun@foxmail.com)
* @date 2011/08/25
* @note  修改记录:
********************************************************************************/
#ifndef SPLIT_PICTURE_H_5AA58A6F_3547_4CDC_82EA_CAE87EFBC42E
#define SPLIT_PICTURE_H_5AA58A6F_3547_4CDC_82EA_CAE87EFBC42E
#include "split/split_base.h"

/**namespace split*/
namespace split
{
/**
* @brief 分割图片
*/
class SPLIT_EXPORT SplitPicture : public SplitBase
{
public:
  /**
  * @brief do nothing
  * @param [in] file_name 
  * @param [in] row 行数
  * @param [in] column 列数
  * @return  
  */
  explicit SplitPicture(const Path& file_name,unsigned short row, unsigned short column);
  /**
  * @brief do nothing
  */
  virtual ~SplitPicture();
private:
  /**
  * @brief 将图片分割成(row * column)个图片
  * @return bool 是否分割成功
  */
  bool StartSplit();
  /**
  * @brief 获取分割图片存储的路径名
  * @return const std::string 分割图片存储的路径名,格式是"源图路径/源图名/split/源图名"
  */
  const std::string AssignPath();

  virtual void Run();
private:
  const unsigned short row_;  /**<@brief 行数*/
  const unsigned short column_;  /**<@brief 列数*/
};
}//end of namespace split
#endif//SPLIT_PICTURE_H_5AA58A6F_3547_4CDC_82EA_CAE87EFBC42E
