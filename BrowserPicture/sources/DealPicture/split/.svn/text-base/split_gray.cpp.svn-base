/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  杜耀坤 (duyaokun@foxmail.com)
* @date 2011/09/01
* @note  修改记录:
********************************************************************************/
#include "split/split_gray.h"
#include "easy/EasyBMP.h"
/**namespace split*/
namespace split
{
#define GRAY_SHOW_PERCENT 0

SplitGray::SplitGray(const Path& picture_path, byte n) : SplitBase(picture_path), levels_(n)
{
  assert(levels_ > 1 && levels_ <= 8);
}

SplitGray::~SplitGray(){}

void SplitGray::Run()
{
  Completed_schedule(0.0f);
  StartSplit();
  Completed_schedule(1.0f);
  running_ = false;
}
#if(GRAY_SPLIT_)
bool SplitGray::StartSplit()
{
#if(SHOW_TIME_PASSED)
  boost::posix_time::ptime _start_time = boost::posix_time::microsec_clock::universal_time();
#endif//SHOW_TIME_PASSED
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

  const size_t _width = src_info_header_.biWidth;
  const size_t _height = src_info_header_.biHeight;
  const byte _pixel_size = GetPixelSize(src_info_header_.biBitCount);

  Path _src_path(picture_name_);
  Path _dest_path(_src_path.parent_path());
  _dest_path /= _src_path.stem();
  _dest_path = _dest_path.string() + "_Gray";
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

  byte BytePaddingPerRow = 4 - (_width * _pixel_size)%4;
  if(BytePaddingPerRow == 4)
  {  
    BytePaddingPerRow = 0;
  }
  const size_t _width_size = _width * _pixel_size + BytePaddingPerRow;

  Path* _paths = new Path[levels_];
  byte* _pixel_read = new byte[_width_size];
  byte** _pixel_levels = new byte*[levels_];
  boost::filesystem::ofstream* _save_streams = new boost::filesystem::ofstream[levels_];
  std::stringstream _ss;
  for(int i = 0; i < levels_ ; ++i)
  {
    _ss.str("");
    _ss<<_dest_path.string()<<"_"<<(i+1)<<".bmp";
    _paths[i] = _ss.str();
    _save_streams[i].open(_ss.str(), std::ios_base::out | std::ios_base::binary);
    _pixel_levels[i] = new byte[_width_size];
  }

  src_info_header_.biSizeImage = _width_size * _height;
  for(int i = 0; i < levels_ ; ++i)
  {
    WtireBmpHeader(_save_streams[i], src_file_header_, src_info_header_);
    _save_streams[i].seekp(src_file_header_.bfOffBits, std::ios_base::beg);
  }
  _base_picture.seekg(src_file_header_.bfOffBits, std::ios_base::beg);
#if(GRAY_SHOW_PERCENT)
  float _percent = 0.0f;
#endif//GRAY_SHOW_PERCENT

  const byte _level_colour = (byte)(256/levels_);//1 + (255 >> (levels_ - 1));
  for(size_t i = 0; i < _height; ++i)
  {
    //读取一行颜色的数据
    _base_picture.read((char*)_pixel_read, _width_size);
    for(int l = 0; l < levels_ ; ++l)
    {
      memset(_pixel_levels[l], 0, _width_size);
    }
    CopyColour(_width_size, _pixel_read, _pixel_levels, _level_colour);
    for(int l = 0; l < levels_ ; ++l)
    {
      _save_streams[l].write((char*)_pixel_levels[l], _width_size);
    }
    Completed_schedule((float)i/(float)_height);
#if(GRAY_SHOW_PERCENT)
    float _complated = Completed_schedule();
    if(_complated < _percent + 0.01f) continue;
    _percent = _complated;
    boost::posix_time::ptime _end_time = boost::posix_time::microsec_clock::universal_time();
    boost::posix_time::time_duration _elp_time = _end_time - _start_time;
    std::cout<<"[Time]: "<<_elp_time.total_milliseconds()<<"ms\n";
    std::cout<<"[Data]"<<_percent<<std::endl;
#endif//GRAY_SHOW_PERCENT
  }
  delete[] _pixel_read;
  _base_picture.close();
  for(int i = 0; i < levels_ ; ++i)
  {
    _ss.str("");
    _ss<<i+1;
    _save_streams[i].close();
    save_paths_.insert(FileNameMap::value_type(_ss.str(), _paths[i]));
    delete[] _pixel_levels[i];
  }
  delete[] _pixel_levels;
  delete[] _save_streams;
  delete[] _paths;
#if(SHOW_TIME_PASSED)
  boost::posix_time::ptime _end_time = boost::posix_time::microsec_clock::universal_time();
  boost::posix_time::time_duration _elp_time = _end_time - _start_time;
  std::cout<<"[SplitRGB]: "<<_elp_time.total_milliseconds()<<"ms\n";
#endif//SHOW_TIME_PASSED
  return true;
}
#else//GRAY_SPLIT_
bool SplitGray::StartSplit()
{
#if(SHOW_TIME_PASSED)
  boost::posix_time::ptime _start_time = boost::posix_time::microsec_clock::universal_time();
#endif//SHOW_TIME_PASSED
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

  const size_t _width = src_info_header_.biWidth;
  const size_t _height = src_info_header_.biHeight;
  const byte _pixel_size = GetPixelSize(src_info_header_.biBitCount);

  Path _src_path(picture_name_);
  Path _dest_path(_src_path.parent_path());
  _dest_path /= _src_path.stem();
  _dest_path = _dest_path.string() + "_Gray";
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

  byte BytePaddingPerRow = 4 - (_width * _pixel_size)%4;
  if(BytePaddingPerRow == 4)
  {  
    BytePaddingPerRow = 0;
  }
  const size_t _width_size = _width * _pixel_size + BytePaddingPerRow;

  Path* _paths = new Path[levels_];
  byte* _pixel_read = new byte[_width_size];
  boost::filesystem::ofstream* _save_streams = new boost::filesystem::ofstream[levels_];
  std::stringstream _ss;
  for(int i = 0; i < levels_ ; ++i)
  {
    _ss.str("");
    _ss<<_dest_path.string()<<"_"<<(i+1)<<".bmp";
    _paths[i] = _ss.str();
    _save_streams[i].open(_ss.str(), std::ios_base::out | std::ios_base::binary);
  }

  src_info_header_.biSizeImage = _width_size * _height;
  for(int i = 0; i < levels_ ; ++i)
  {
    WtireBmpHeader(_save_streams[i], src_file_header_, src_info_header_);
    _save_streams[i].seekp(src_file_header_.bfOffBits, std::ios_base::beg);
  }
  _base_picture.seekg(src_file_header_.bfOffBits, std::ios_base::beg);
#if(GRAY_SHOW_PERCENT)
  float _percent = 0.0f;
#endif//GRAY_SHOW_PERCENT

  for(size_t i = 0; i < _height; ++i)
  {
    //读取一行颜色的数据
    _base_picture.read((char*)_pixel_read, _width_size);
    byte* _tmp = _pixel_read;
    for(size_t j = 0; j < _width; ++j, _tmp += 3)
    {
      _tmp[0] = _tmp[1] = _tmp[2] = (_tmp[2]*30 + _tmp[1]*59 + _tmp[0]*11 + 50) / 100;
    }
    for(int l = 1; l <= levels_ ; ++l)
    {
      _tmp = _pixel_read;
      for(size_t p = 0; p < _width_size; ++p, ++_tmp)
      {
        *_tmp /= 2;
      }
      _save_streams[l - 1].write((char*)_pixel_read, _width_size);
    }
    Completed_schedule((float)i/(float)_height);
#if(GRAY_SHOW_PERCENT)
    float _complated = Completed_schedule();
    if(_complated < _percent + 0.01f) continue;
    _percent = _complated;
    boost::posix_time::ptime _end_time = boost::posix_time::microsec_clock::universal_time();
    boost::posix_time::time_duration _elp_time = _end_time - _start_time;
    std::cout<<"[Time]: "<<_elp_time.total_milliseconds()<<"ms\n";
    std::cout<<"[Data]"<<_percent<<std::endl;
#endif//GRAY_SHOW_PERCENT
  }
  delete[] _pixel_read;
  _base_picture.close();
  for(int i = 0; i < levels_ ; ++i)
  {
    _ss.str("");
    _ss<<i+1;
    _save_streams[i].close();
    save_paths_.insert(FileNameMap::value_type(_ss.str(), _paths[i]));
  }
  delete[] _save_streams;
  delete[] _paths;
#if(SHOW_TIME_PASSED)
  boost::posix_time::ptime _end_time = boost::posix_time::microsec_clock::universal_time();
  boost::posix_time::time_duration _elp_time = _end_time - _start_time;
  std::cout<<"[SplitRGB]: "<<_elp_time.total_milliseconds()<<"ms\n";
#endif//SHOW_TIME_PASSED
  return true;
}
#endif//GRAY_SPLIT_
}//end of namespace split