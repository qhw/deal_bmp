/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  杜耀坤 (duyaokun@foxmail.com)
* @date 2011/08/26
* @note  修改记录:
********************************************************************************/
#ifndef SPLIT_RGB_H__8A374134_F20A_4D28_A0B5_F33DE65BD0E4
#define SPLIT_RGB_H__8A374134_F20A_4D28_A0B5_F33DE65BD0E4

#include "split/split_base.h"
class BMFH;
class BMIH;

/**namespace split*/
namespace split
{
/**
* @brief 实现对源图的rgb分割.
*
* 存储分割后的图片文件路径.key分别是"R","G","B".
*/
class SPLIT_EXPORT SplitRGB : public SplitBase
{
public:
  /**
  * @brief do nothing
  * @param [in] file_name 
  * @return  
  */
  explicit SplitRGB(const Path& file_name);
  /**
  * @brief do nothing
  */
  virtual ~SplitRGB();
private:
  void Run();
  /**
  * @brief 对源图开始RGB分割
  * @return bool 是否成功
  */
  bool StartSplit();
};

}//end of namespace split
#endif//SPLIT_RGB_H__8A374134_F20A_4D28_A0B5_F33DE65BD0E4
