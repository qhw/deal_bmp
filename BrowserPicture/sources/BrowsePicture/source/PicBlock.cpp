/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#include "stdafx.h"
#include "PicBlock.h"
#include <iostream>

PicBlock::PicBlock(const QString& path , int width ,int height,QGraphicsView *view)
:color(QColor(100,100,100))
{
  path_of_pic = path;

  this->view = view;
  this->width = width;
  this->height = height;
  //  this->pixmap = pixmap.scaled(width,height);

  Init();
}
PicBlock::PicBlock()
:color(QColor(100,100,100))
{
  Init();
}
void PicBlock::setValue(const QString& path , int width ,int height,QGraphicsView *view)
{
  path_of_pic = path;

  this->view = view;
  this->width = width;
  this->height = height;
}
void PicBlock::Init()
{
  setFlags(ItemIsSelectable /*| ItemIsMovable*/);
  setAcceptsHoverEvents(true);
  setBoundingRegionGranularity(0);
  setZValue((width + height) % 2);//设置位置，是否在上面
}
PicBlock::~PicBlock()
{

}
/************************************************************************/
/*@确定哪些图片需要加载，以减少内存中的图片所占据的空间
**@TODO：目前还没找到合适的方法进行筛选
*/
/************************************************************************/
void PicBlock::LoadPixmap(float n)
{
  //   int  width1 = width * n;
  //   int  height1 = height * n;
  //   QPointF poslt,posrb;//左上角位置对应的view坐标
  //   poslt = mapToScene(0,0);
  //   poslt = view->mapFromScene(poslt);
  // 
  //   posrb = mapToScene(width,height);
  //   posrb = view->mapFromScene(posrb);
  // 
  //   //在范围之外，不去加载图片；进入范围后加载
  //   if ( posrb.x() < 10
  //     || poslt.x() > view->width()-10
  //     || poslt.y() > view->height()-10
  //     || posrb.y() < 10)
  //   {
  //     if (!pixmap.isNull())
  //     {
  //       pixmap = QPixmap("").scaled(width1,height1);
  //     }
  //   }
  //   else if (pixmap.isNull())
  //   {
  //     pixmap = QPixmap(path_of_pic);
  //   }
  //   pixmap.save("mytest0.bmp");
  //   pixmap = pixmap.scaled(width1,height1);
  //   pixmap.save("mytest1.bmp");
  //   pixmap = pixmap.scaled(width,height);
  //   pixmap.save("mytest2.bmp");
  //   update();
}
QRectF PicBlock::boundingRect() const
{
  return QRectF(0, 0, width, height);
}

QPainterPath PicBlock::shape() const
{
  QPainterPath path;
  path.addRect(boundingRect());
  return path;
}

void PicBlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  Q_UNUSED(widget);
  Q_UNUSED(option);

  const qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());
  float n = lod;
  QPixmap pixmap;
  pixmap = QPixmap(path_of_pic);
  painter->drawPixmap(0,0,width,height,pixmap);
}
void PicBlock::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsItem::mousePressEvent(event);
  /************************************************************************/
  /* 切换视图方位
  */
  /************************************************************************/
  m_last_pos = mapToScene(event->pos());
  update();
}

void PicBlock::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  if (event->buttons() & Qt::LeftButton)
  {
    setCursor(Qt::ClosedHandCursor);
    /************************************************************************/
    /* 切换视图方位
    */
    /************************************************************************/
    QPointF newpos = mapToScene(event->pos());
    QPointF offset = newpos - m_last_pos;
    m_last_center_pos = view->mapToScene(QPoint(view->width()/2,view->height()/2));
    if (m_center_pos == m_last_center_pos - offset)
    {
      return;
    }
    else
    {
      m_center_pos = m_last_center_pos - offset;
    }
    std::cout<< m_center_pos.x()<< ","<<m_center_pos.y()<<std::endl;
    view->centerOn(m_center_pos);
  }else 
    setCursor(Qt::OpenHandCursor);

  if (event->modifiers() & Qt::ShiftModifier) 
  {
    stuff << event->pos();
    update();
    return;
  }
  QGraphicsItem::mouseMoveEvent(event);
}

void PicBlock::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsItem::mouseReleaseEvent(event);
  setCursor(Qt::OpenHandCursor);
  update();
}
