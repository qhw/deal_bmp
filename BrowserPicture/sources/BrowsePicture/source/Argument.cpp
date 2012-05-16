/**@file
*****************************************************************************
* 版权所有(C) 高迪未来(北京)科技有限公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @author  Eric 
* @date 2011/08/25
* @note  修改记录:
********************************************************************************/
#include "StdAfx.h"
#include "Argument.h"

SPLITArg::SPLITArg()
:_method(0),_split_pic(0),_rgb_pic(0),_gray_pic(0),_split_row(0),_split_col(0),_split_gray(0)
{

}

void SPLITArg::setMethod(int method)
{
  this->_method = method;
}

void SPLITArg::setSplit_Pic(int split_pic)
{
  this->_split_pic = split_pic;
}

void SPLITArg::setRgb_Pic(int rgb_pic)
{
  this->_rgb_pic = rgb_pic;
}

void SPLITArg::setGray_Pic(int gray_pic)
{
  this->_gray_pic = gray_pic;
}

void SPLITArg::setSplit_Row(int split_row)
{
  this->_split_row = split_row;
}

void SPLITArg::setSplit_Col(int split_col)
{
  this->_split_col = split_col;
}

void SPLITArg::setSplit_Gray(int split_gray)
{
  this->_split_gray = split_gray;
}

int SPLITArg::getMethod(void)
{
  return _method;
}

int SPLITArg::getSplit_Pic(void)
{
  return _split_pic;
}

int SPLITArg::getRgb_Pic(void)
{
  return _rgb_pic;
}

int SPLITArg::getGray_Pic(void)
{
  return _gray_pic;
}

int SPLITArg::getSplit_Row(void)
{
  return _split_row;
}

int SPLITArg::getSplit_Col(void)
{
  return _split_col;
}

int SPLITArg::getSplit_Gray(void)
{
  return _split_gray;
}

SPLITArg::~SPLITArg()
{

}



MergeArg::MergeArg()
:start_row(0),start_col(0),end_row(0),end_col(0),channel(""),grey_start(0),grey_end(0)
{

}

MergeArg::~MergeArg()
{

}

void MergeArg::setStart_Row_Col(int row, int col)
{
  this->start_row = row;
  this->start_col = col;
}

void MergeArg::setEnd_Row_Col(int row, int col)
{
  this->end_row = row;
  this->end_col = col;
}

void MergeArg::setChannel(QString channel)
{
  this->channel = channel;
}

void MergeArg::setGray_Range(int start, int end)
{
  this->grey_start = start;
  this->grey_end = end;
}

int MergeArg::getStartRow()
{
  return start_row;
}

int MergeArg::getStartCol()
{
  return start_col;
}

int MergeArg::getEndRow()
{
  return end_row;
}

int MergeArg::getEndCol()
{
  return end_col;
}

QString MergeArg::getChannel()
{
  return channel;
}

int MergeArg::getStartGray()
{
  return grey_start;
}

int MergeArg::getEndGray()
{
  return grey_end;
}