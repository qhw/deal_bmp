/**@file
*****************************************************************************
* ��Ȩ����(C) ?? CopyRight(2011 - ...)
* @brief ����ժҪ:
* @author  ��ҫ�� (duyaokun@foxmail.com)
* @date 2011/08/25
* @note  �޸ļ�¼:
********************************************************************************/
#ifndef SPLIT_PICTURE_H_5AA58A6F_3547_4CDC_82EA_CAE87EFBC42E
#define SPLIT_PICTURE_H_5AA58A6F_3547_4CDC_82EA_CAE87EFBC42E
#include "split/split_base.h"

/**namespace split*/
namespace split
{
/**
* @brief �ָ�ͼƬ
*/
class SPLIT_EXPORT SplitPicture : public SplitBase
{
public:
  /**
  * @brief do nothing
  * @param [in] file_name 
  * @param [in] row ����
  * @param [in] column ����
  * @return  
  */
  explicit SplitPicture(const Path& file_name,unsigned short row, unsigned short column);
  /**
  * @brief do nothing
  */
  virtual ~SplitPicture();
private:
  /**
  * @brief ��ͼƬ�ָ��(row * column)��ͼƬ
  * @return bool �Ƿ�ָ�ɹ�
  */
  bool StartSplit();
  /**
  * @brief ��ȡ�ָ�ͼƬ�洢��·����
  * @return const std::string �ָ�ͼƬ�洢��·����,��ʽ��"Դͼ·��/Դͼ��/split/Դͼ��"
  */
  const std::string AssignPath();

  virtual void Run();
private:
  const unsigned short row_;  /**<@brief ����*/
  const unsigned short column_;  /**<@brief ����*/
};
}//end of namespace split
#endif//SPLIT_PICTURE_H_5AA58A6F_3547_4CDC_82EA_CAE87EFBC42E
