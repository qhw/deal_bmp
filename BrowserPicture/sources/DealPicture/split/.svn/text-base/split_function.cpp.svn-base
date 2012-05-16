/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  杜耀坤 (duyaokun@foxmail.com)
* @date 2011/0desc_.gray/29
* @note  修改记录:
********************************************************************************/
#include <boost/foreach.hpp>
#include "split/split_picture.h"
#include "split/split_rgb.h"
#include "split/split_gray.h"
#include "easy/EasyBMP.h"

/**namespace split*/
namespace split
{
std::string BLANK_STRING = "";

/**
* @brief 
*/
class _split_common
{
protected:
  typedef std::vector<SplitBase*> split_vector;
  typedef std::vector<Path> path_vector;
public:
  _split_common(const SplitDesc& desc) : desc_(desc), last_step_(SS_NONE){}
  virtual ~_split_common(){}
  virtual void run()
  {
    while(desc_.steps.size())
    {
      path_vector _paths;
      get_paths(_paths);
      destroy_split();
      SplitStep _step = desc_.steps.front();
      BOOST_FOREACH(Path& _path, _paths)
      {
        switch(_step)
        {
        case SS_SPLIT:
          splits_.push_back(new SplitPicture(_path, desc_.row, desc_.colum));
          break;
        case SS_RGB:
          splits_.push_back(new SplitRGB(_path));
          break;
        case SS_GRAY:
          splits_.push_back(new SplitGray(_path, desc_.gray));
          break;
        default:
          assert(false);
          break;
        }
        splits_.back()->Start(false);
      }
      desc_.steps.pop_front();
      last_step_ = _step;
    }
    destroy_split();
  }
protected:
  virtual void destroy_split()
  {
    split_vector::iterator _first = splits_.begin();
    split_vector::iterator _end = splits_.end();
    while(_first != _end)
    {
      delete *_first;
      ++_first;
    }
    splits_.clear();
  }
  virtual void get_paths(path_vector& pv)
  {
    assert(pv.size() < 1);
    switch(last_step_)
    {
    case SS_NONE:
      pv.push_back(desc_.path);
      break;
    case SS_SPLIT:
      BOOST_FOREACH(SplitBase* _sb, splits_)
      {
        for(unsigned short i = 0; i < desc_.colum; ++i)
        {
          for(unsigned short j = 0; j < desc_.row; ++j)
          {
            std::stringstream _ss;
            _ss<<i + 1<<","<<1 + j;
            pv.push_back(_sb->GetPath(_ss.str()));
          }
        }
      }
      break;
    case SS_RGB:
      BOOST_FOREACH(SplitBase* _sb, splits_)
      {
        pv.push_back(_sb->GetPath("R"));
        pv.push_back(_sb->GetPath("G"));
        pv.push_back(_sb->GetPath("B"));
      }
      break;
    case SS_GRAY:
      BOOST_FOREACH(SplitBase* _sb, splits_)
      {
        for(byte i = 0; i < desc_.gray; ++i)
        {
          std::stringstream _ss;
          _ss<<(i+1);
          pv.push_back(_sb->GetPath(_ss.str()));
        }
      }
      break;
    default:
      assert(false);
      break;
    }
  }
protected:
  SplitDesc desc_;
  split_vector splits_;
  SplitStep last_step_;
};

class _split_waiting_thread : public _split_common
{
public:
  _split_waiting_thread(const SplitDesc& desc) : _split_common(desc){}
private:
  /*
  virtual void split_first()
  {
    assert(!has_rgb_ && !has_split_ && "图片分割不是第一步了");
    split_ = new SplitPicture(desc_.path, desc_.row, desc_.colum);
    split_->Start(true);
    split_->WaitForEnd();
  }
  virtual void split_after_rgb()
  {
    assert(!has_split_ && "图片已经切割");
    assert(has_rgb_ && rgb_ && "还没有rgb分离");
    split::SplitPicture _sp_r(rgb_->GetPath("R"), desc_.row, desc_.colum);
    _sp_r.Start(true);
    split::SplitPicture _sp_g(rgb_->GetPath("G"), desc_.row, desc_.colum);
    _sp_g.Start(true);
    split::SplitPicture _sp_b(rgb_->GetPath("B"), desc_.row, desc_.colum);
    _sp_b.Start(true);
    _sp_r.WaitForEnd();
    _sp_g.WaitForEnd();
    _sp_b.WaitForEnd();
  }
  virtual void rgb_first()
  {
    assert(!has_rgb_ && !has_split_ && "rgb分离不是第一步了");
    rgb_ = new SplitRGB(desc_.path);
    rgb_->Start(true);
    rgb_->WaitForEnd();
  }
  virtual void rgb_after_split()
  {
    assert(!has_rgb_ && "图片已经rgb分离");
    assert(has_split_ && split_ && "还没有切割");
    std::stringstream _ss;
    for(unsigned short i = 0; i < desc_.colum; ++i)
    {
      for(unsigned short j = 0; j < desc_.row; ++j)
      {
        _ss.str("");
        _ss<<i + 1<<","<<1 + j;
        split::SplitRGB _srgb(split_->GetPath(_ss.str()));
        _srgb.Start(true);
        _srgb.WaitForEnd();
      }
    }
  }
  //*/
};

SPLIT_EXPORT_BEGIN
SPLIT_EXPORT void _stdcall DoSplitNoThread(const SplitDesc& desc)
{
  _split_common _split(desc);
  _split.run();
}
SPLIT_EXPORT void _stdcall DoSplitWithWaitingThread(const SplitDesc& desc)
{
  _split_waiting_thread _split(desc);
  _split.run();
}
SPLIT_EXPORT_END

byte GetPixelSize(size_t size)
{
  switch(size)
  {
  case 1:
  case 4:
    return 1;
  case 8:
  case 16:
    return 2;
  case 24:
    return 3;
  case 32:
    return 4;
  default:
    assert(false && "不正常的位数");
  }
  return 0;
}

void WtireBmpHeader(boost::filesystem::ofstream& dest_bmp, BMFH& file_header, BMIH& info_header)
{
  dest_bmp.seekp(0, std::ios_base::beg);
  if(IsBigEndian()) file_header.SwitchEndianess();
  dest_bmp.write((char*)&(file_header.bfType) , sizeof(ebmpWORD));
  dest_bmp.write((char*)&(file_header.bfSize) , sizeof(ebmpDWORD));
  dest_bmp.write((char*)&(file_header.bfReserved1) , sizeof(ebmpWORD));
  dest_bmp.write((char*)&(file_header.bfReserved2) , sizeof(ebmpWORD));
  dest_bmp.write((char*)&(file_header.bfOffBits) , sizeof(ebmpDWORD));

  if(IsBigEndian()) info_header.SwitchEndianess();
  dest_bmp.write((char*)&(info_header.biSize) , sizeof(ebmpDWORD));
  dest_bmp.write((char*)&(info_header.biWidth) , sizeof(ebmpDWORD));
  dest_bmp.write((char*)&(info_header.biHeight) , sizeof(ebmpDWORD));
  dest_bmp.write((char*)&(info_header.biPlanes) , sizeof(ebmpWORD));
  dest_bmp.write((char*)&(info_header.biBitCount) , sizeof(ebmpWORD));
  dest_bmp.write((char*)&(info_header.biCompression) , sizeof(ebmpDWORD));
  dest_bmp.write((char*)&(info_header.biSizeImage) , sizeof(ebmpDWORD));
  dest_bmp.write((char*)&(info_header.biXPelsPerMeter) , sizeof(ebmpDWORD));
  dest_bmp.write((char*)&(info_header.biYPelsPerMeter) , sizeof(ebmpDWORD));
  dest_bmp.write((char*)&(info_header.biClrUsed) , sizeof(ebmpDWORD));
  dest_bmp.write((char*)&(info_header.biClrImportant) , sizeof(ebmpDWORD));
}

}//end of namespace split