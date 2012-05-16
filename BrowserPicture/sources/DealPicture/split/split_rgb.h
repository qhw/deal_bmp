/**@file
*****************************************************************************
* ��Ȩ����(C) �ߵ�δ��(����)�Ƽ����޹�˾ CopyRight(2011 - ...)
* @brief ����ժҪ:
* @author  ��ҫ�� (duyaokun@foxmail.com)
* @date 2011/08/26
* @note  �޸ļ�¼:
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
* @brief ʵ�ֶ�Դͼ��rgb�ָ�.
*
* �洢�ָ���ͼƬ�ļ�·��.key�ֱ���"R","G","B".
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
  * @brief ��Դͼ��ʼRGB�ָ�
  * @return bool �Ƿ�ɹ�
  */
  bool StartSplit();
};

}//end of namespace split
#endif//SPLIT_RGB_H__8A374134_F20A_4D28_A0B5_F33DE65BD0E4
