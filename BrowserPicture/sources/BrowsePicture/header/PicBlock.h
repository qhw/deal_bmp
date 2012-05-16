/**@file
*****************************************************************************
* ��Ȩ����(C) ???��˾ CopyRight(2011 - ...)
* @brief ����ժҪ:
* @date 2011/08/23
* @note  �޸ļ�¼: 
1.�޸�ע�͸�ʽ,��tabת��Ϊ2���ո� [2011/08/23 15:34 fox]
********************************************************************************/
#ifndef PICITEM_H
#define PICITEM_H

#include <QtGui/QColor>
#include <QtGui/QGraphicsItem>

/**
* @brief PicBlock�࣬�̳��� QGraphicsItem��������ʾͼƬ
* @author Hero
* @date 2011��8��4��
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
