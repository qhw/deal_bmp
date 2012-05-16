/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  杜耀坤 (duyaokun@foxmail.com)
* @date 2011/08/25
* @note  修改记录:
********************************************************************************/
#ifndef SPLIT_DEFINE_H__FA0A8988_2BCD_402C_AFC7_96EA2CF76F3D
#define SPLIT_DEFINE_H__FA0A8988_2BCD_402C_AFC7_96EA2CF76F3D

#ifndef DEALPICTURE_EXPORTS
#define SPLIT_EXPORT _declspec(dllimport)
#else
#define SPLIT_EXPORT _declspec(dllexport)
#endif//DEALPICTURE_EXPORTS

#ifdef __cplusplus
#define SPLIT_EXPORT_BEGIN extern "C" {  /*!< extern "C" */
#define SPLIT_EXPORT_END }  /*!< 空 */
#else
#define SPLIT_EXPORT_BEGIN  /*!< 空 */
#define SPLIT_EXPORT_END  /*!< 空 */
#endif //__cplusplus

#define BOOST_FILESYSTEM_VERSION 2
#include <string>
#include <vector>
#include <map>
#include <list>
#include <boost/noncopyable.hpp>
#include <boost/filesystem/fstream.hpp>
class BMP;
class BMFH;
class BMIH;

#define SHOW_TIME_PASSED 1

/**namespace split*/
namespace split
{

#pragma warning(push)
#pragma warning(disable : 4275)//disable warning C4275: 非dll接口 class“boost::noncopyable_::noncopyable”用作dll接口"...”的基类
/**
* @brief 只是继承与boost的noncopyable,限制类不可被复制
*/
class SPLIT_EXPORT SplitNoncopyable : public boost::noncopyable{};
#pragma warning(pop)//4275

#pragma warning(disable : 4251)//disable warning C4251: class“...”需要有dll接口由class“...”的客户端使用

typedef boost::filesystem::path Path;  /**<@brief 定义文件路径类型*/
typedef std::map<std::string, Path> FileNameMap;  /**<@brief 定义存储文件名称的列表*/
typedef unsigned char byte;

typedef enum
{
  SS_SPLIT,
  SS_RGB,
  SS_GRAY,
  SS_NONE = 999,
}SplitStep;

typedef std::list<SplitStep> StepList;

typedef struct
{
  StepList steps;
  Path path;
  unsigned short row;
  unsigned short colum;
  byte gray;
}SplitDesc;

SPLIT_EXPORT_BEGIN
SPLIT_EXPORT void _stdcall DoSplitNoThread(const SplitDesc& desc);
SPLIT_EXPORT void _stdcall DoSplitWithWaitingThread(const SplitDesc& desc);
SPLIT_EXPORT_END

/**
* @brief 
* @param [in] size 
* @return byte 
*/
byte GetPixelSize(size_t size);
/**
* @brief 
* @param [in] _dest_bmp 
* @param [in] _new_file_header 
* @param [in] _new_info_header 
* @return void 
*/
//void WtireBmpHeader(boost::filesystem::ofstream* dest_bmp, BMFH& file_header, BMIH& info_header);
void WtireBmpHeader(boost::filesystem::ofstream& dest_bmp, BMFH& file_header, BMIH& info_header);
}//end of namespace split

#endif//SPLIT_DEFINE_H__FA0A8988_2BCD_402C_AFC7_96EA2CF76F3D
