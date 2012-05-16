/**@file
*****************************************************************************
* 版权所有(C) ???公司 CopyRight(2011 - ...)
* @brief 内容摘要:
* @date 2011/08/23
* @note  修改记录: 
1.修改注释格式,将tab转换为2个空格 [2011/08/23 15:34 fox]
********************************************************************************/
#include "stdafx.h"
#include "browsepicture.h"
#include "view.h"

#include "managepic.h"
#include "splitdlg.h"
#include "PicBlock.h"
BrowsePicture::BrowsePicture(QWidget *parent, Qt::WFlags flags)
: QWidget(parent, flags)
{
  ui.setupUi(this);
  this->setObjectName("BrowsePicture");


  
  Init();
  showMaximized();//最大化显示
  this->setWindowTitle("图像处理软件");
    /*添加qss*/
  QFile qss(":/skin.qss");
  qss.open(QFile::ReadOnly);
  setStyleSheet(qss.readAll());
  qss.close();
}

BrowsePicture::~BrowsePicture(){}

void BrowsePicture::Init()
{
  viewport = new View("图片展示",this->ui.widget_view);
  item = NULL;
  scene = NULL;
  ShowThumbnail(":/images/default.bmp");
  connect(ui.open_btn,      SIGNAL(clicked()),   this, SLOT(OpenButtonClicked()));
  connect(ui.split_btn,     SIGNAL(clicked()),   this, SLOT(SplitButtonClicked()));
  connect(ui.open_dir_btn,  SIGNAL(clicked()),   this, SLOT(OpenDirButtonClicked()));
  connect(ui.show_pic_btn,  SIGNAL(clicked()),   this, SLOT(ShowPicButtonClicked()));
  connect(ui.auto_merge_btn,SIGNAL(clicked()),   this, SLOT(AutoMergeButtonClicked()));

}

void BrowsePicture::resizeEvent(QResizeEvent *event)
{
  viewport->resize(ui.widget_view->width(),ui.widget_view->height());
 ///*添加背景图片*/
 // QPixmap BackGroundImage=  QPixmap(":/images/hehua.png");
 // setAutoFillBackground(true);
 // QPalette palette(palette());
 // palette.setBrush(QPalette::Background, QBrush(BackGroundImage.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
 // setPalette(palette);

} 

QString BrowsePicture::OpenFile()
{
  QString dir = "../";
  QString filter = "BmpFiles (*.bmp)\nAllfiles(*.*)";
  QString filename = QFileDialog :: getOpenFileName (this, "打开图片文件",dir ,filter );

  if (!filename.right(4).contains(".bmp"))
  {
    return "";
  }
  ShowThumbnail(filename) ;
  return filename;
}

void BrowsePicture::OpenDir()
{
  QFileDialog *fileDialog = new QFileDialog(this); 
  fileDialog->setWindowTitle(tr("选择图片所在文件夹路径")); 
  fileDialog->setDirectory("../"); 
  fileDialog-> setFileMode( QFileDialog::DirectoryOnly ); 
  if(fileDialog->exec() == QDialog::Accepted) { 
    pic_path = fileDialog->selectedFiles()[0]; 
  }
}

bool BrowsePicture::ShowThumbnail(QString filename)
{
  QPixmap pixmap;
  SPLIT m_split;
  BMFH bmfh = m_split.getBMFH((const char *)filename.toLocal8Bit());
  BMIH bmih  =  m_split.getBMIH((const char *)filename.toLocal8Bit());
  int pic_size = bmfh.bfSize;
  //如果图像大小合适，打开filename,否则打开默认背景
  if (pic_size <= 30000000)//30M
  {
    pixmap = QPixmap(filename);
  }
  else
  {
    pixmap = QPixmap(":/images/default.bmp");
    filename = ":/images/default.bmp";
  }
  //QList<QGraphicsItem *>  qlist = scene->items();
  //for(int i = 0; i < qlist.size(); i++)
  // {	
  //	scene->removeItem(qlist[i]);
  // }
  /*解决图像位置显示不正确的问题
  以及内存泄露问题*/
  if(item != NULL)
  {
    delete item;
    item = NULL;
  }
  if(scene != NULL) 
  {
    delete scene;
    scene = NULL;
  }
  scene = new QGraphicsScene;
  viewport->view()->setScene(scene);
  //scene.clear();
  /*PicBlock *item1 = new PicBlock(filename,pixmap.width(),pixmap.height(),viewport->view());
  scene->addItem(item1);*/
  //PicBlock *item1 = new PicBlock(filename,pixmap.width(),pixmap.height(),viewport->view());

  item = new PicBlock;
  item->setValue(filename,pixmap.width(),pixmap.height(),viewport->view());
  scene->addItem(item);
  viewport->view()->centerOn(pixmap.width()/2,pixmap.height()/2);
  //viewport->view()->centerOn(&item);
  /************************************************************************/
  /*@TODO获取显示信息 
  */
  /************************************************************************/

  return true;
}

void BrowsePicture::OpenSplitDialog()
{
  SplitDlg dlg;
  connect(&dlg,SIGNAL(startSplitPic(QString,const SPLITArg&)),this,SLOT(splitPic(QString,const SPLITArg&)));
  dlg.exec();
}

void BrowsePicture::splitPic(QString filename,const SPLITArg &arg)
{
  MySplitThread *split = new MySplitThread;

  connect(split,SIGNAL(done()),this,SLOT(doneSuccess()));
  connect(split,SIGNAL(fail()),this,SLOT(doneFail()));
  connect(split,SIGNAL(showpic(QString)),this,SLOT(ShowDonePicture(QString)));
  connect(split,SIGNAL(showDoingPic(QString)),this,SLOT(ShowThumbnail(QString)));
  split->setPath(filename);
  split->setArg(arg);
  Progress *dlg = new Progress;
  dlg->setFlag(0);
   dlg->setPathName(filename);
   dlg->setArg(arg);
   dlg->setProgressMax();//设置进度条最大值
   dlg->setSplitThread(split);//为了在进度条取消或关闭时终止线程 并释放空间
   dlg->show();
   connect(split,SIGNAL(done()),dlg,SLOT(closeDlg()));
   split->start();
   splitthread_list.append(split);
   splitprogress_list.append(dlg);
}


void BrowsePicture::ShowImage()
{
 MyMergeThread *merge = new MyMergeThread;
 merge->setArg(arg);
 merge->setPath(pic_path);
 setMergeThread(merge);
  Progress *dlg = new Progress;
  dlg->setFlag(2);
  dlg->setPathName(pic_path);
  dlg->setMergeArg(merge->getMergeArg());
  dlg->setArg(arg);
  dlg->setProgressMax();
  dlg->setMergeThread(merge);//为了在进度条取消或关闭时终止线程 并释放空间
  dlg->show();
  connect(merge,SIGNAL(done()),this,SLOT(doneSuccess()));
  connect(merge,SIGNAL(fail()),this,SLOT(doneFail()));
  connect(merge,SIGNAL(showpic(QString)),this,SLOT(ShowDonePicture(QString)));
  connect(merge,SIGNAL(showDoingPic(QString)),this,SLOT(ShowThumbnail(QString)));
  connect(merge,SIGNAL(done()),dlg,SLOT(closeDlg()));
  merge->start();
  mergethread_list.append(merge);
  mergeprogress_list.append(dlg);
}

bool BrowsePicture::ReadFile(const QString &path)
{
  QFile file(path +"/" + "/log.txt");
  if(!file.open(QIODevice::ReadWrite))
  {
    QMessageBox msg;
    msg.setText("没有找到配置文件");
    msg.exec();
    return false;
  }
  QString line  = file.readLine();
  QStringList list = line.split(" ");
  arg.setMethod(list[0].toInt());
  arg.setSplit_Pic(list[1].toInt());
  arg.setRgb_Pic(list[2].toInt());
  arg.setGray_Pic(list[3].toInt());
  arg.setSplit_Row(list[4].toInt());
  arg.setSplit_Col(list[5].toInt());
  arg.setSplit_Gray(list[6].toInt());
  return true;
}

void BrowsePicture::ShowDonePicture(QString path)
{
  QString filename = path;
  int pos = path.lastIndexOf("/",-1);
  filename.remove(0,pos + 1);
  ShowThumbnail(path +"/Merge/" + filename);
}

void BrowsePicture::doneSuccess()
{
  for(int i = 0; i < splitthread_list.size(); ++i)
  {
    if(splitthread_list[i]->isFinished())
    {
      MySplitThread *tmp = splitthread_list[i];
      splitthread_list.removeAt(i);
      delete tmp;
      Progress *progress = splitprogress_list[i];
      splitprogress_list.removeAt(i);
      delete progress;
    }
  }

  for(int i = 0; i < mergethread_list.size(); ++i)
  {
    if(mergethread_list[i]->isFinished())
    {
      MyMergeThread *tmp = mergethread_list[i];
      mergethread_list.removeAt(i);
      delete tmp;
      Progress *progress = mergeprogress_list[i];
      mergeprogress_list.removeAt(i);
      delete progress;
    }
  }

  for(int i = 0; i < automergethread_list.size(); ++i)
  {
    if(automergethread_list[i]->isFinished())
    {
      MyAutoMergeThread *tmp = automergethread_list[i];
      automergethread_list.removeAt(i);
      delete tmp;
      Progress *progress = automergeprogress_list[i];
      automergeprogress_list.removeAt(i);
      delete progress;
    }
  }

  QMessageBox msg;
  msg.setWindowTitle("处理成功");
  msg.setText("处理完毕!");
  msg.exec();
}

void BrowsePicture::doneFail()
{
  QMessageBox msg;
  msg.setWindowTitle("错误提示");
  msg.setText("程序异常!");
  msg.exec();
}

void BrowsePicture::setMergeThread(MyMergeThread *thread)
{
  MergeArg mergeArg;
  //设定选择条件
  int start_row = ui.row_spinbox->value();
  int start_col = ui.col_spinbox->value();
  int end_row = ui.row_spinbox_2->value();
  int end_col = ui.col_spinbox_2->value();

  QString channel = ui.channel_cbox->currentText();

  int grey_start = ui.grey_start_spinbox->value();
  int grey_end = ui.grey_end_spinbox->value();
  mergeArg.setChannel(channel);
  mergeArg.setStart_Row_Col(start_row,start_col);
  mergeArg.setEnd_Row_Col(end_row,end_col);
  mergeArg.setGray_Range(grey_start,grey_end);
  thread->setMergeArg(mergeArg);
}

void BrowsePicture::OpenActTriggered()
{
  OpenFile();
}

void BrowsePicture::ExitActTriggered()
{
  close();
}

void BrowsePicture::OpenButtonClicked()
{
  OpenFile();
}

void BrowsePicture::SplitButtonClicked()
{
  OpenSplitDialog();
}

void BrowsePicture::OpenDirButtonClicked()
{
  OpenDir();
  ui.dir_edit->setText(pic_path);
}

void BrowsePicture::clearDir(QString path)
{
  ManagePic pic;
  QStringList splitList = pic.FindFile(path +"/Merge/split");
  QStringList rgbList = pic.FindFile(path +"/Merge/rgb");
  QStringList grayList = pic.FindFile(path +"/Merge/gray");
  QDir dir(path +"/Merge");
  for(int i = 1; i < splitList.size(); i++)
  {
    dir.remove(splitList[0] +"/" +splitList[i]);
  }

  for(int i = 1; i < rgbList.size(); i++)
  {
    dir.remove(rgbList[0] +"/" +rgbList[i]);
  }

  for(int i = 1; i < grayList.size(); i++)
  {
    dir.remove(grayList[0] +"/" +grayList[i]);
  }
  QString tmp = path;
  int pos = path.lastIndexOf("/");
  tmp.remove(0,pos + 1);
  dir.remove(path +"/Merge/" +tmp );
}
void BrowsePicture::ShowPicButtonClicked()
{
  pic_path = ui.dir_edit->text();
  if(!ReadFile(pic_path))
  {
    return;
  }
  clearDir(pic_path);
  ShowImage();
}

void BrowsePicture::AutoMergeButtonClicked()
{
  pic_path = ui.dir_edit->text();
  if(!ReadFile(pic_path))
  {
    return;
  }
  clearDir(pic_path);
  MyAutoMergeThread *automerge = new MyAutoMergeThread;
  automerge->setArg(arg);
  automerge->setPath(pic_path);
  connect(automerge,SIGNAL(done()),this,SLOT(doneSuccess()));
  connect(automerge,SIGNAL(fail()),this,SLOT(doneFail()));
  connect(automerge,SIGNAL(showpic(QString)),this,SLOT(ShowDonePicture(QString)));
  connect(automerge,SIGNAL(showDoingPic(QString)),this,SLOT(ShowThumbnail(QString)));

  Progress *dlg = new Progress;
  dlg->setFlag(1);
  dlg->setPathName(pic_path);
  dlg->setArg(arg);
  dlg->setProgressMax();
  dlg->setAutoMergeThread(automerge);
  dlg->show();
  connect(automerge,SIGNAL(done()),dlg,SLOT(closeDlg()));
  automergethread_list.append(automerge);
  automergeprogress_list.append(dlg);
  automerge->start();
}