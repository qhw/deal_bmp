/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#ifndef MANAGEPIC_H
#define MANAGEPIC_H

#include <QObject>

/**图片管理类，用于管理图片，读取、保存等操作*/
class ManagePic : public QObject
{
  Q_OBJECT
public:
  ManagePic(QObject *parent = 0);
  ~ManagePic();
  /**
  * @brief 查找某一文件夹下所有的图片，获得其路径列表
  * @param [in] folder_name 
  * @return QStringList list[0]，储存路径。余下储存该路径下的图片名字
  */
  QStringList FindFile(const QString &folder_name);
  /**
  * @brief 在默认目录下查找某一文件夹，返回文件夹路径
  * @param [in] folder_path 
  * @param [in] folder_name 
  * @return QString 
  */
  QString FindDir(const QString& folder_path,const QString & folder_name);
  /**
  * @brief 生成指定的文件夹
  * @param [in] path 传入路径 最后不带'/'
  * @param [in] dirname 要创建的文件夹名称
  * @return bool 
  */
  bool CreateDiretory(QString path,QString dirname);
  /**
  * @brief 对处理的图片生成所需要的文件夹
  * @param [in] path 
  * @param [in] filename 
  * @return bool 
  */
  bool CreateDealPictureDirectory(QString path,QString filename);
  /**
  * @brief 移除文件夹里的内容
  * @param [in] pathName 
  * @return bool 
  */
  bool removeFile(QString pathName);
};

#endif // MANAGEPIC_H
