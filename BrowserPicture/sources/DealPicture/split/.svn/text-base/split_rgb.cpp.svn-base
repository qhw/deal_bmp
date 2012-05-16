/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  杜耀坤 (duyaokun@foxmail.com)
* @date 2011/08/26
* @note  修改记录:
********************************************************************************/
#include "split/split_rgb.h"
#include <boost/filesystem.hpp>
#include <boost/thread.hpp>
#include "easy/EasyBMP.h"
//#include "split/bmp_stream.h"

#define RGB_SHOW_PERCENT 0

/**namespace split*/
namespace split
{

SplitRGB::SplitRGB(const Path& file_name) : SplitBase(file_name)
{}

SplitRGB::~SplitRGB()
{}

bool SplitRGB::StartSplit()
{
  boost::filesystem::ifstream _base_picture(picture_name_, std::ios_base::in | std::ios_base::binary);
  if(!_base_picture)
  {
    std::cout<<"open file \""<<picture_name_<<"\" failed!";
    return false;
  }
  BMFH src_file_header_ = GetBMFH(picture_name_.string().c_str());
  BMIH src_info_header_ = GetBMIH(picture_name_.string().c_str());
  if(src_info_header_.biBitCount != 24)
  {
    return false;
  }
  Path _src_path(picture_name_);
  Path _dest_path(_src_path.parent_path());
  _dest_path /= _src_path.stem();
  _dest_path = _dest_path.string() + "_RGB";
  try
  {
    boost::filesystem::remove_all(_dest_path);
    boost::filesystem::create_directory(_dest_path);
  }
  catch(boost::filesystem::filesystem_error& error)
  {
    std::cout<<error.what();
  }
  _dest_path /= _src_path.stem();
  Path _path_r = _dest_path.string() + "_R.bmp";
  Path _path_g = _dest_path.string() + "_G.bmp";
  Path _path_b = _dest_path.string() + "_B.bmp";

#if(SHOW_TIME_PASSED)
  boost::posix_time::ptime _start_time = boost::posix_time::microsec_clock::universal_time();
#endif//SHOW_TIME_PASSED
  //打开3个通道图片
  boost::filesystem::ofstream _bmp_r(_path_r, std::ios_base::out | std::ios_base::binary);
  boost::filesystem::ofstream _bmp_g(_path_g, std::ios_base::out | std::ios_base::binary);
  boost::filesystem::ofstream _bmp_b(_path_b, std::ios_base::out | std::ios_base::binary);

  const size_t _width = src_info_header_.biWidth;
  const size_t _height = src_info_header_.biHeight;
  const byte _pixel_size = GetPixelSize(src_info_header_.biBitCount);

  byte BytePaddingPerRow = 4 - (_width * _pixel_size)%4;
  if(BytePaddingPerRow == 4)
  {  
    BytePaddingPerRow = 0;
  }
  const size_t _width_size = _width * _pixel_size + BytePaddingPerRow;
  byte* _pixel_read = new byte[_width_size];
  byte* _pixel_r = new byte[_width_size];
  byte* _pixel_g = new byte[_width_size];
  byte* _pixel_b = new byte[_width_size];
  memset(_pixel_r, 0, _width_size);
  memset(_pixel_g, 0, _width_size);
  memset(_pixel_b, 0, _width_size);

  src_info_header_.biSizeImage = _width_size * _height;
  WtireBmpHeader(_bmp_r, src_file_header_, src_info_header_);
  WtireBmpHeader(_bmp_g, src_file_header_, src_info_header_);
  WtireBmpHeader(_bmp_b, src_file_header_, src_info_header_);

  _base_picture.seekg(src_file_header_.bfOffBits, std::ios_base::beg);
  _bmp_r.seekp(src_file_header_.bfOffBits, std::ios_base::beg);
  _bmp_g.seekp(src_file_header_.bfOffBits, std::ios_base::beg);
  _bmp_b.seekp(src_file_header_.bfOffBits, std::ios_base::beg);
#if(RGB_SHOW_PERCENT)
  float _percent = 0.0f;
#endif//RGB_SHOW_PERCENT

  for(size_t i = 0; i < _height; ++i)
  {
    byte* _r = _pixel_r + 2;
    byte* _g = _pixel_g + 1;
    byte* _b = _pixel_b;
    //读取一行颜色的数据
    _base_picture.read((char*)_pixel_read, _width_size);
    byte* _read = _pixel_read;
    for(size_t j = 0; j < _width; ++j, _r += 3, _g += 3, _b += 3, _read += 3)
    {
      *_b = *_read;
      *_g = *(_read + 1);
      *_r = *(_read + 2);
    }
    _bmp_r.write((char*)_pixel_r, _width_size);
    _bmp_g.write((char*)_pixel_g, _width_size);
    _bmp_b.write((char*)_pixel_b, _width_size);
    Completed_schedule((float)i/(float)_height);
#if(RGB_SHOW_PERCENT)
    float _complated = Completed_schedule();
    if(_complated < _percent + 0.01f) continue;
    _percent = _complated;
    boost::posix_time::ptime _end_time = boost::posix_time::microsec_clock::universal_time();
    boost::posix_time::time_duration _elp_time = _end_time - _start_time;
    std::cout<<"[Time]: "<<_elp_time.total_milliseconds()<<"ms\n";
    std::cout<<"[Data]"<<_percent<<std::endl;
#endif//RGB_SHOW_PERCENT
  }
  delete[] _pixel_read;
  delete[] _pixel_r;
  delete[] _pixel_g;
  delete[] _pixel_b;
  _base_picture.close();
  _bmp_r.close();
  save_paths_.insert(FileNameMap::value_type("R", _path_r));
  _bmp_g.close();
  save_paths_.insert(FileNameMap::value_type("G", _path_g));
  _bmp_b.close();
  save_paths_.insert(FileNameMap::value_type("B", _path_b));
#if(SHOW_TIME_PASSED)
  boost::posix_time::ptime _end_time = boost::posix_time::microsec_clock::universal_time();
  boost::posix_time::time_duration _elp_time = _end_time - _start_time;
  std::cout<<"[SplitRGB]: "<<_elp_time.total_milliseconds()<<"ms\n";
#endif//SHOW_TIME_PASSED
  return true;
}

void SplitRGB::Run()
{
  Completed_schedule(0.0f);
  StartSplit();
  Completed_schedule(1.0f);
  running_ = false;
}

}//end of namespace split