#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <io.h>
#include "showvideo.h"
#include <windows.h>
#include <dos.h>
#include <fstream>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QHBoxLayout>
#include <QLabel>
#include <QImage>
#include <QPainter>
#include <QFileDialog>
#include <QVector>
#include <QDoubleValidator>
#include <QtConcurrent>
#include <iostream>
#include <QMainWindow>
#include <QByteArray>
#include <QPixmap>
#include <QTime>
#include <opencv2/core/core.hpp>
#include <QStringList>
#include <QMediaPlaylist>
using namespace std;
class QCamera;
class QMediaPlayer;
class QLabel;
class QcameraViewfinder;
class Showvideo;
class QSqlQuery;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
public slots:
    void OnError();
    //本地视频选择
   // void on_pushButtonopen_clicked();
    //void on_pushButtonplay_clicked();
    //void on_pushButtonstop_clicked();
    //及时摄像头选择
    //void on_pushButtondetectUSB_clicked();
    //void on_pushButtonplayUSB_clicked();
    //void on_pushButtonstopUSB_clicked();
    void stopAllplay();
    void showresource();
    void showresource1();
    void initDir(string open_dir);
    void opendatabase();
    //void showtop2(QString tmppath);
   // void showtop1(QString tmppath);
    //void getlabel();
   // void getaccuracy();
    void Delay(int time);
private slots:
    void on_lineEdit_cursorPositionChanged(int arg1,int arg2);
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_lineEdit_5_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_6_clicked();

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
     QMediaPlayer* mediaplayer;
     //Showvideo *surface;

    QString resourcepath;
    Showvideo *surface ;
    QMediaPlaylist *playlist;
    cv::Mat image;//cv图片
};

#endif // MAINWINDOW_H
