/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:建立程序中建立的数据结构
* @author  Eric 
* @date 2011/08/25
* @note  修改记录:
********************************************************************************/
#ifndef  ARGUMENT_H_
#define  ARGUMENT_H_

class SPLITArg
{
public:
  SPLITArg();
  ~SPLITArg();
    /**<@brief 设置变量
    *@author Eric
    *@date 2011-8-25
    */
  void setMethod(int method);
  void setSplit_Pic(int split_pic);
  void setRgb_Pic(int rgb_pic);
  void setGray_Pic(int gray_pic);

  void setSplit_Row(int split_row);
  void setSplit_Col(int split_col);
  void setSplit_Gray(int split_gray);
/**<@brief 获取变量
    *@author Eric
    *@date 2011-8-25
    */
  int getMethod(void);
  int getSplit_Pic(void);
  int getRgb_Pic(void);
  int getGray_Pic(void);

  int getSplit_Row(void);
  int getSplit_Col(void);
  int getSplit_Gray(void);
private:
  int  _method;  /**<@brief  图像处理时的三种顺序 0: 对应 split->rgb->gray  1: 对应 rgb->split->gray 2:对应rgb->gray->split*/
  int  _split_pic;  /**<@brief 图像处理时是否被几何分割 0：未几何分割   1：几何分割*/
  int  _rgb_pic;  /**<@brief  图像处理时是否进行rgb通道分离 0：未进行rgb通道分离   1：进行了rgb通道的分离*/
  int  _gray_pic;  /**<@brief  图像处理时是否进行灰度分离  0：未灰度分离   1：灰度分离*/

  int  _split_row;  /**<@brief  设置分割时的分割的行数*/
  int  _split_col;  /**<@brief  设置分割时的分割的列数*/
  int  _split_gray;  /**<@brief  设置灰度分离时的值*/
};

class MergeArg
{
public:
  MergeArg();
  ~MergeArg();
/**<@brief 设置变量
    *@author Eric
    *@date 2011-8-25
    */
  void setStart_Row_Col(int row, int col);
  void setEnd_Row_Col(int row, int col);
  void setChannel(QString channel);
  void setGray_Range(int start, int end);

    /**<@brief 设置变量
    *@author Eric
    *@date 2011-8-25
    */
  int getStartRow();
  int getStartCol();
  int getEndRow();
  int getEndCol();
  QString getChannel();
  int getStartGray();
  int getEndGray();
private:
  int start_row;/**<@brief  几何分割下限行*/
  int start_col;/**<@brief  几何分割下限列*/
  int end_row;  /**<@brief  几何分割上限行*/
  int end_col;  /**<@brief  几何分割上限列*/
  QString channel;  /**<@brief  合并后的通道*/
  int grey_start;  /**<@brief  灰度阶下限*/
  int grey_end;  /**<@brief  灰度阶上限*/
};
#endif