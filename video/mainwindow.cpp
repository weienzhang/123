#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <QDebug>
#include <QSqlQuery>
#include <opencv2/highgui/highgui.hpp>
#include <QLabel>
#include <ATLComTime.h>
#include <QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSql>
using namespace std;
using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mediaplayer(nullptr),
    ui(new Ui::MainWindow)
{
   // ui->setupUi(this);
    ui->setupUi(this);
    Showvideo* tmpsurface = new Showvideo(this);
    tmpsurface->setvideolabel(ui->labelvedio1);
    surface = tmpsurface;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete surface;
}

void MainWindow::showresource()
{
  Showvideo* tmpsurface = new Showvideo();
  tmpsurface->setvideolabel(ui->labelvedio1);
  surface = tmpsurface;
  QString localpath = ui->lineEdit->text();
  resourcepath=localpath;
  mediaplayer = new QMediaPlayer();
  connect(mediaplayer,SIGNAL(error(QMediaPlayer::Error)), this, SLOT(OnError()));
  mediaplayer->setVideoOutput(surface);
  surface->setvediosource(Showvideo::video);
  mediaplayer->setMedia(QUrl::fromLocalFile(localpath));
  mediaplayer->play();
}
/*void MainWindow::showresource1(string path)
{
  Showvideo* tmpsurface = new Showvideo();
  tmpsurface->setvideolabel(ui->labelvedio1);
  surface = tmpsurface;
  QString localpath(path.c_str());
  resourcepath=localpath;
  mediaplayer = new QMediaPlayer();
  connect(mediaplayer,SIGNAL(error(QMediaPlayer::Error)), this, SLOT(OnError()));
  mediaplayer->setVideoOutput(surface);
  surface->setvediosource(Showvideo::video);
  mediaplayer->setMedia(QUrl::fromLocalFile(localpath));
  mediaplayer->play();
 // waitKey(0);
  //Delay(3000);

}*/
void MainWindow::showresource1()
{

    playlist->setCurrentIndex(1);
    Showvideo* tmpsurface = new Showvideo();
    tmpsurface->setvideolabel(ui->labelvedio1);
    surface = tmpsurface;
     mediaplayer = new QMediaPlayer();
     connect(mediaplayer,SIGNAL(error(QMediaPlayer::Error)), this, SLOT(OnError()));
     mediaplayer->setPlaylist(playlist);
     mediaplayer->setVideoOutput(surface);
     surface->setvediosource(Showvideo::video);
     mediaplayer->play();
}
void MainWindow::opendatabase()
{

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
       db.setHostName("localhost");
       db.setDatabaseName("mysql");
       db.setUserName("root");
       db.setPassword("hua!hua123/456");
       db.open();

//QSqlDatabase db;
       QSqlQuery query;
       query=QSqlQuery::QSqlQuery(db);
//QString name = ui->lineEdit_5->text();
       QString name = ui->lineEdit_5->text();
       //sqlquery=QObject::tr("insert into table values('%1','%2')").arg(value1,value2);
       //执行query.exec(sqlquery);就可以了
       //QSqlQuery query;
       // string current_path;
      if(db.open())
      {
          QString SQL;
       SQL=QObject::tr("select ID from criminal where Name=('%1')").arg(name);

       query.exec(SQL);

       //client::variantToQString(query.value(0));

       //string id = client::variantToQString(query.value(0));
       if(query.first())
       {
           //string current_path;

           string id = query.value(0).value<QString>().toLatin1().data();
           qDebug(id.c_str());
           playlist =new QMediaPlaylist();
           initDir("C:\\Users\\myvideo\\" + id);
           //current_path = "C:\\Users\\myvideo\\" + id + "//*";  //当前打开的目录
           showresource1();`
       }
       db.close();
      }
      else
      {
          qDebug()<<"open fail";

      }

}
void MainWindow::initDir(string open_dir)
{

    _finddata_t file_info;
//	cout << access("bin", 0) << endl;

    //返回值为-1则查找失败
    string current_path = open_dir+ "//*";  //当前打开的目录
    intptr_t handle=_findfirst(current_path.c_str(), &file_info);
    //qDebug(file_info.name);
//get handle of current file
    cout << handle << endl;
    if(handle == -1){
        cout << "Can't open dictionary" + open_dir << endl;
        return;
    }
    while(!_findnext(handle, &file_info)){
        if(file_info.attrib==_A_SUBDIR && string(file_info.name ).find(".") == -1 ){ //是目录并且没有拓展名
            initDir(open_dir + "\\" + file_info.name);
        }
        else if(string(file_info.name).find(".avi")!=-1)
        {
            playlist->addMedia(QUrl::fromLocalFile(string(open_dir+"\\"+file_info.name).c_str()))==true;
            qDebug(string(open_dir+"\\"+file_info.name).c_str());
        }
    }  //返回0则遍历完

    qDebug("mediaplayer finish!");
    _findclose(handle);
}



void MainWindow::OnError()
{
    qDebug()<<"mediaplayer error:"<<mediaplayer->error();
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,QStringLiteral("请选择视频文件"),QString());
   if (!filename.isEmpty())
   {
      ui->lineEdit->setText(filename);
   }
}

void MainWindow::on_pushButton_2_clicked()
{
    stopAllplay();
    showresource();
    Delay(1000);
   // getlabel();
}

void MainWindow::on_pushButton_3_clicked()
{
    stopAllplay();
}
void  MainWindow::Delay(int   time)//time*1000为秒数
{
   clock_t   now   =   clock();
    while(   clock()   -   now   <   time   );
}

void MainWindow::stopAllplay()
{
   /* if(camera)
     {
       camera->stop();
       camera->deleteLater();
       camera = nullptr;
     }*/
    if(mediaplayer)
    {
      mediaplayer->stop();
      mediaplayer->deleteLater();
      mediaplayer = nullptr;
    }
    /*if(mediatop1)
    {
      mediatop1->stop();
      mediatop1->deleteLater();
      mediatop1 = nullptr;
    }
    if(mediatop2)
    {
      mediatop2->stop();
      mediatop2->deleteLater();
      mediatop2 = nullptr;
    }*/
}


void MainWindow::on_lineEdit_cursorPositionChanged(int arg1,int arg2)
{

}


void MainWindow::on_pushButton_4_clicked()
{
    stopAllplay();
    opendatabase();
   // showresource1();
    //Delay(1000);
}

void MainWindow::on_pushButton_5_clicked()
{
        stopAllplay();
}


void MainWindow::on_lineEdit_5_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    qDebug()<<"filenames:"<<fileName;
    image = cv::imread(fileName.toLatin1().data());
    cv::namedWindow("Original Image");
    cv::imshow("Original Image", image);



}

void MainWindow::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{

}
