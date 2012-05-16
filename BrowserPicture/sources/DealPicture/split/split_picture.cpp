/**@file
*****************************************************************************
* ��Ȩ����(C) ??? CopyRight(2011 - ...)
* @brief ����ժҪ:
* @author  ��ҫ�� (duyaokun@foxmail.com)
* @date 2011/08/25
* @note  �޸ļ�¼:
********************************************************************************/
#include "split/split_picture.h"
#include <boost/filesystem.hpp>
#include <boost/date_time.hpp>
#include <sstream>
#include "easy/EasyBMP.h"

/**namespace split*/
namespace split
{

SplitPicture::SplitPicture(const Path& file_name,unsigned short row, unsigned short column)
: SplitBase(file_name), row_(row), column_(column)
{}

SplitPicture::~SplitPicture(){}

bool SplitPicture::StartSplit()
{
  //����ļ��б�
  save_paths_.clear();
  //��ԴͼƬ
  boost::filesystem::ifstream _src_bmp(picture_name_, std::ios_base::in | std::ios_base::binary);//ԴͼƬ
  if(!_src_bmp)
  {
    std::cout<<"open file \""<<picture_name_<<"\" failed!";
    return false;
  }
  const BMFH _file_header_ = GetBMFH(picture_name_.string().c_str());
  const BMIH _info_header_ = GetBMIH(picture_name_.string().c_str());
  if(_info_header_.biBitCount != 24)
  {
    return false;
  }
  //�ָ�ͼƬ
  const unsigned char _piexl_size = GetPixelSize(_info_header_.biBitCount);//һ�����صĴ�С
  const std::string _dest_path = AssignPath();//��ȡ�ָ�ͼƬҪ�����·����
  const size_t _src_width = _info_header_.biWidth;//Դͼ���(��λ:����)
  /*const */size_t _src_width_size = _src_width * _piexl_size;//Դͼ���(��λ:�ֽ�)
  int _BytePaddingPerRow = 4 - (_src_width_size)%4;
  if(_BytePaddingPerRow == 4)
  {  _BytePaddingPerRow = 0; } 
  _src_width_size += _BytePaddingPerRow;
  const size_t _src_height = _info_header_.biHeight;//Դͼ�߶�(��λ:����)
  //const size_t _src_height_size = _src_height * _piexl_size;//Դͼ�߶�(��λ:�ֽ�)
  const size_t _per_width = _src_width / row_;//�ָ�ͼƽ�����(��λ:����)
  const size_t _per_height = _src_height / column_;//�ָ�ͼƽ���߶�(��λ:����)
  char* _read_data = new char[std::max(_per_width, (_src_width - _per_width * (row_ - 1))) * _piexl_size];
  for(unsigned short r = 0; r < row_; ++r)
  {
    for(unsigned short c = 0; c < column_; ++c)
    {
      std::stringstream _ss;
      //�����µ�ͼ���ļ�����
      _ss << _dest_path << "_" << column_ - c << "_" << r + 1 << ".bmp";
      Path _save_path(_ss.str());
      boost::filesystem::ofstream _dest_bmp(_save_path, std::ios_base::out | std::ios_base::binary);//���ͼ���ļ�

      //const size_t _src_y = c * _per_height;
      const size_t _dest_width = r == (row_ - 1) ? (_src_width  - _per_width * r) : _per_width;
      const size_t _dest_width_size = _piexl_size * _dest_width;
      const size_t _dest_height = c == (column_ - 1) ? (_src_height  - _per_height * c) : _per_height;

      //�����ļ�ͷ��д��
      int BytePaddingPerRow = 4 - (_dest_width_size)%4;
      if(BytePaddingPerRow == 4)
      {  BytePaddingPerRow = 0; } 
      byte _zero_data[3] = {0};

      size_t dActualBytesPerRow = _dest_width_size + BytePaddingPerRow;
      size_t dTotalPixelBytes = _dest_height * dActualBytesPerRow;
      //size_t dPaletteSize = 0;
      //if( _info_header_.biBitCount == 1 || _info_header_.biBitCount == 4 || _info_header_.biBitCount == 8 )
      //{
      //  dPaletteSize = IntPow(2, _info_header_.biBitCount) * 4;
      //}

      // leave some room for 16-bit masks 
      //if( _info_header_.biBitCount == 16 )
      //{ dPaletteSize = 3*4; }

      size_t dTotalFileSize = 14 + 40 + dTotalPixelBytes;// + dPaletteSize;

      // write the file header 
      BMFH _new_file_header;
      _new_file_header.bfSize = dTotalFileSize; 
      _new_file_header.bfReserved1 = 0; 
      _new_file_header.bfReserved2 = 0; 
      _new_file_header.bfOffBits = 14 + 40;// + dPaletteSize;
      BMIH _new_info_header = _info_header_;
      _new_info_header.biSize = 40;
      _new_info_header.biWidth = _dest_width;
      _new_info_header.biHeight = _dest_height;
      _new_info_header.biSizeImage = (ebmpDWORD) dTotalPixelBytes;
      WtireBmpHeader(_dest_bmp, _new_file_header, _new_info_header);

      const size_t _read_size = _dest_width * _piexl_size;//��ͼƬÿ�еĴ�С
      const size_t _seek_data = _src_width_size - _read_size;
      const size_t _moved_data = _file_header_.bfOffBits + c * _per_height * _src_width_size + r * _per_width * _piexl_size;
      _src_bmp.seekg(_moved_data, std::ios_base::beg);
      _dest_bmp.seekp(_new_file_header.bfOffBits, std::ios_base::beg);
#if(SHOW_TIME_PASSED)
      boost::posix_time::ptime _start_time = boost::posix_time::microsec_clock::universal_time();
#endif//SHOW_TIME_PASSED
      for(size_t i = 0; i < _dest_height; ++i)
      {
        _src_bmp.read(_read_data, _read_size);
        _dest_bmp.write(_read_data, _read_size);
        _dest_bmp.write((char*)_zero_data, BytePaddingPerRow);
        _src_bmp.seekg(_seek_data, std::ios_base::cur);
      }
      //if(_zero_data) delete[] _zero_data;
      _dest_bmp.close();

      _ss.str("");
      _ss<<column_ - c << "," << r + 1;
      save_paths_.insert(FileNameMap::value_type(_ss.str(), _save_path));
#if(SHOW_TIME_PASSED)
      boost::posix_time::ptime _end_time = boost::posix_time::microsec_clock::universal_time();
      boost::posix_time::time_duration _elp_time = _end_time - _start_time;
      std::cout<<_elp_time.total_milliseconds()<<"ms\n";
#endif//SHOW_TIME_PASSED
    }
  }
  delete[] _read_data;
  return true;
}

const std::string SplitPicture::AssignPath()
{
  ///�����洢�ָ�ͼƬ�Ĵ洢�ļ���
  Path _src_path(picture_name_);//ԴͼƬ·��
  Path _dest_path(_src_path.parent_path());//Ŀ��·��
  ///���Ŵ����ָ�ͼƬ�洢���ļ���
  _dest_path /= _src_path.stem();
  _dest_path = _dest_path.string() + "_split";
  ///ɾ��ԭ�е�ͼƬ
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
  return _dest_path.string();
}

void SplitPicture::Run()
{
  Completed_schedule(0.0f);
  StartSplit();
  Completed_schedule(1.0f);
  running_ = false;
}
}//end of namespace split