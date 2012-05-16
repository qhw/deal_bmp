/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  杜耀坤 (duyaokun@foxmail.com)
* @date 2011/09/01
* @note  修改记录:
********************************************************************************/
#ifndef SPLIT_GRAY_H__153B76EF_2C7E_486C_A521_9009E2982A00
#define SPLIT_GRAY_H__153B76EF_2C7E_486C_A521_9009E2982A00
#include "split/split_base.h"
/**namespace split*/
namespace split
{

#define GRAY_SPLIT_ 1///是否完全按照颜色区间来分灰度

/**
* @brief 分割灰度图
*/
class SPLIT_EXPORT SplitGray : public SplitBase
{
public:
  /**
  * @brief do nothing
  */
  explicit SplitGray(const Path& picture_path, byte n);
  /**
  * @brief do nothing
  */
  ~SplitGray();

private:
  virtual void Run();
  bool StartSplit();
#if(GRAY_SPLIT_)
  void CopyColourRed(size_t width_size, byte* const read, byte** pixel_levels, byte level_colour) 
  {
    byte* _read = read;
    byte** _pixel = pixel_levels;
    for(size_t i = 2; i < width_size ; i += 3, _read += 3)
    {
      _pixel[*read/level_colour][i] = *_read;
    }
  }
  void CopyColourGreen(size_t width_size, byte* const read, byte** pixel_levels, byte level_colour) 
  {
    byte* _read = read;
    byte** _pixel = pixel_levels;
    for(size_t i = 1; i < width_size ; i += 3, _read += 3)
    {
      _pixel[*read/level_colour][i] = *_read;
    }
  }
  void CopyColourBlue(size_t width_size, byte* const read, byte** pixel_levels, byte level_colour) 
  {
    byte* _read = read;
    byte** _pixel = pixel_levels;
    for(size_t i = 0; i < width_size ; i += 3, _read += 3)
    {
      _pixel[*read/level_colour][i] = *_read;
    }
  }
  void CopyColour(size_t width_size, byte* read, byte** pixel_levels, byte level_colour) 
  {
    byte* _read = read;
    byte** _pixel = pixel_levels;
    for(size_t i = 0; i < width_size ; ++i, ++_read)
    {
      _pixel[*read/level_colour][i] = *_read;
    }
  }
#endif//GRAY_SPLIT_
private:
  const byte levels_;  /**<@brief 灰度分阶数*/
};

}//end of namespace split
#endif//SPLIT_GRAY_H__153B76EF_2C7E_486C_A521_9009E2982A00
