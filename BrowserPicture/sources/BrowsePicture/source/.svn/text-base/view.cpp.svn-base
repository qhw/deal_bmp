/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#include "stdafx.h"
#include "view.h"

#ifndef QT_NO_OPENGL
#include <QtOpenGL>
#endif

#include <qmath.h>


View::View(const QString &name, QWidget *parent)
: QFrame(parent)
{
  setFrameStyle(Sunken | StyledPanel);
  graphicsView = new QGraphicsView;
graphicsView->setObjectName("graphicsView");
  // graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  // graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  graphicsView->setRenderHint(QPainter::Antialiasing, false);
  graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
  graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);
  graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

  int size = style()->pixelMetric(QStyle::PM_ToolBarIconSize);
  QSize iconSize(size, size);

  QToolButton *zoomInIcon = new QToolButton;//放大
  zoomInIcon->setAutoRepeat(true);
  zoomInIcon->setAutoRepeatInterval(33);
  zoomInIcon->setAutoRepeatDelay(0);
  zoomInIcon->setIcon(QPixmap(":/icon/zoomin.png"));
  zoomInIcon->setIconSize(iconSize);
  QToolButton *zoomOutIcon = new QToolButton;//缩小
  zoomOutIcon->setAutoRepeat(true);
  zoomOutIcon->setAutoRepeatInterval(33);
  zoomOutIcon->setAutoRepeatDelay(0);
  zoomOutIcon->setIcon(QPixmap(":/icon/zoomout.png"));
  zoomOutIcon->setIconSize(iconSize);
  zoomSlider = new QSlider;
  zoomSlider->setMinimum(0);
  zoomSlider->setMaximum(500);
  zoomSlider->setValue(250);
  zoomSlider->setTickPosition(QSlider::TicksRight);
zoomSlider->hide();

  // Zoom slider layout


  QToolButton *rotateLeftIcon = new QToolButton;
  rotateLeftIcon->setIcon(QPixmap(":/icon/rotateleft.png"));
  rotateLeftIcon->setIconSize(iconSize);
  QToolButton *rotateRightIcon = new QToolButton;
  rotateRightIcon->setIcon(QPixmap(":/icon/rotateright.png"));
  rotateRightIcon->setIconSize(iconSize);
  rotateSlider = new QSlider;
  rotateSlider->setOrientation(Qt::Horizontal);
  rotateSlider->setMinimum(-360);
  rotateSlider->setMaximum(360);
  rotateSlider->setValue(0);
  rotateSlider->setTickPosition(QSlider::TicksBelow);
rotateSlider->hide();



  // Rotate slider layout
  //QHBoxLayout *rotateSliderLayout = new QHBoxLayout;
  //rotateSliderLayout->addWidget(rotateLeftIcon);
  //rotateSliderLayout->addWidget(rotateSlider);
  //rotateSliderLayout->addWidget(rotateRightIcon);

  resetButton = new QToolButton;
resetButton->setObjectName("resetButton");
  resetButton->setText(tr("复位"));
  resetButton->setMinimumSize(50,30);
  resetButton->setMaximumSize(50,30);
  resetButton->setEnabled(false);

  QWidget* spacer = new QWidget( this );
  spacer->setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Minimum );



  QHBoxLayout *buttonLayout = new QHBoxLayout;
 buttonLayout->addWidget(spacer);
  buttonLayout->addWidget(zoomInIcon);
  buttonLayout->addWidget(zoomOutIcon);
  buttonLayout->addWidget(rotateLeftIcon);
  buttonLayout->addWidget(rotateRightIcon);
  buttonLayout->addWidget(resetButton);


  // Label layout
  //QHBoxLayout *labelLayout = new QHBoxLayout;
  //label = new QLabel(name);

  //labelLayout->addWidget(label);
  //labelLayout->addStretch();

  QVBoxLayout *Layout = new QVBoxLayout;
  

  Layout->addLayout(buttonLayout);
  Layout->addWidget(graphicsView);
  setLayout(Layout);

  //QGridLayout *topLayout = new QGridLayout;
  //topLayout->addLayout(labelLayout, 0, 0);
  //topLayout->addWidget(graphicsView, 1, 0);
  //topLayout->addLayout(zoomSliderLayout, 1, 1);
  //topLayout->addLayout(rotateSliderLayout, 2, 0);
  //topLayout->addWidget(resetButton, 2, 1);
  //setLayout(topLayout);

  connect(resetButton, SIGNAL(clicked()), this, SLOT(resetView()));
  connect(zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
  connect(rotateSlider, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
  connect(graphicsView->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(setResetButtonEnabled()));
  connect(graphicsView->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(setResetButtonEnabled()));
  connect(rotateLeftIcon, SIGNAL(clicked()), this, SLOT(rotateLeft()));
  connect(rotateRightIcon, SIGNAL(clicked()), this, SLOT(rotateRight()));
  connect(zoomInIcon, SIGNAL(clicked()), this, SLOT(zoomIn()));
  connect(zoomOutIcon, SIGNAL(clicked()), this, SLOT(zoomOut()));


  setupMatrix();
  graphicsView->setRenderHint(QPainter::Antialiasing);
}

QGraphicsView *View::view() const
{
  return graphicsView;
}

void View::resetView()
{
  zoomSlider->setValue(250);
  rotateSlider->setValue(0);
  setupMatrix();
  graphicsView->ensureVisible(QRectF(0, 0, 0, 0));

  resetButton->setEnabled(false);
}

void View::setResetButtonEnabled()
{
  resetButton->setEnabled(true);
}

void View::setupMatrix()
{
  qreal scale = qPow(qreal(2), (zoomSlider->value() - 250) / qreal(50));

  QMatrix matrix;
  matrix.scale(scale, scale);
  matrix.rotate(rotateSlider->value());

  graphicsView->setMatrix(matrix);
  setResetButtonEnabled();
}

void View::zoomIn()
{
  zoomSlider->setValue(zoomSlider->value() + 1);
}

void View::zoomOut()
{
  zoomSlider->setValue(zoomSlider->value() - 1);
}

void View::rotateLeft()
{
  rotateSlider->setValue(rotateSlider->value() - 10);
}

void View::rotateRight()
{
  rotateSlider->setValue(rotateSlider->value() + 10);
}

