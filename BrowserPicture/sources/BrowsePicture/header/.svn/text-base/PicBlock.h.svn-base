/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#ifndef PICITEM_H
#define PICITEM_H

#include <QtGui/QColor>
#include <QtGui/QGraphicsItem>

/**
* @brief PicBlock类，继承于 QGraphicsItem，用于显示图片
* @author Hero
* @date 2011年8月4日
*/
class PicBlock : public QGraphicsItem
{
public:
  PicBlock(const QString &path, int width ,int height, QGraphicsView *view);
  PicBlock();
  ~PicBlock();

  void setValue(const QString &path, int width, int height, QGraphicsView *view );
  //  PicBlock(QPixmap &pixmap,QGraphicsView *view);
  QRectF boundingRect() const;
  QPainterPath shape() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);
  void LoadPixmap(float n);
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
  void Init();
private:
  // QPixmap pixmap;
  QString path_of_pic;
  QColor color;
  QList<QPointF> stuff;
  QPointF m_last_pos;
  QPointF m_last_center_pos;
  QPointF m_center_pos;
  QGraphicsView *view;
  int width, height;
};

#endif
