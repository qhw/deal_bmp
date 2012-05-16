/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#ifndef VIEW_H
#define VIEW_H

#include <QFrame>

QT_FORWARD_DECLARE_CLASS(QGraphicsView)
QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)
QT_FORWARD_DECLARE_CLASS(QToolButton)

/**
* @brieg 视图窗口类，显示item
* @author Hero
* @date 2011年8月4日
*/
class View : public QFrame
{
  Q_OBJECT
public:
  View(const QString &name, QWidget *parent = 0);

  QGraphicsView *view() const;

  private slots:
    void resetView();
    void setResetButtonEnabled();
    void setupMatrix();

    void zoomIn();
    void zoomOut();
    void rotateLeft();
    void rotateRight();

private:
  QGraphicsView *graphicsView;
  //QLabel *label;
  QToolButton *resetButton;
  QSlider *zoomSlider;
  QSlider *rotateSlider;
};

#endif
