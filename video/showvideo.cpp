#include "Showvideo.h"
#include <QImage>
#include <QLabel>
#include <QPainter>
#include <QDebug>
#include <Windows.h>
#include <opencv2/imgproc.hpp>
Showvideo::Showvideo(QObject *parent ):
  labelvideo(nullptr),
    QAbstractVideoSurface(parent)
    {
      //human=new Humandetect();
    }
QList<QVideoFrame::PixelFormat>  Showvideo::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType)const
{
    Q_UNUSED(handleType);
    QList<QVideoFrame::PixelFormat> formatList;
    formatList.push_back(QVideoFrame::Format_RGB24);
    formatList.push_back(QVideoFrame::Format_RGB32);
    return formatList;
}

/*void initDir(string open_dir)
{
    string current_path = open_dir + "//*.avi";  //当前打开的目录

   // mkdir(file.c_str());
    _finddata_t file_info;
//	cout << access("bin", 0) << endl;

    //返回值为-1则查找失败
    intptr_t handle=_findfirst(current_path.c_str(), &file_info);    //get handle of current file
    cout << handle << endl;
    if(handle == -1){
        cout << "Can't open dictionary" + open_dir << endl;
        return;
    }

    while(!_findnext(handle, &file_info)){
        if(file_info.attrib==_A_SUBDIR && string(file_info.name ).find(".") == -1 ){ //是目录并且没有拓展名
            string curFile = file + "//" + string(file_info.name ) + "_test";
            mkdir(curFile.c_str());
            cout << "file = " << curFile;
            initDir(open_dir + "//" + file_info.name);
        }
        //cout << file_info.name

 << "\t" << attribute << endl;
    }  //返回0则遍历完

    _findclose(handle);
}
*/



bool Showvideo::present(const QVideoFrame &frame)
{
   // humanrect.clear();
    if(frame.isValid())
    {
        QVideoFrame cloneFrame(frame);
        if(cloneFrame.map(QAbstractVideoBuffer::ReadOnly))
        {
            if(!labelvideo)
            {
                labelvideo = new QLabel;
                labelvideo->resize(QSize(600,500));
                labelvideo->show();
            }
            QImage image(cloneFrame.bits(), cloneFrame.width(), cloneFrame.height(), QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat()));
            cv::Mat src(cloneFrame.height(), cloneFrame.width(), CV_8UC4, (void*)image.bits(), cloneFrame.bytesPerLine());
            cv::Mat dst;
            cv::cvtColor(src,dst,cv::COLOR_BGRA2BGR);
            QPainter painter(&image);
            QPen pen;
            pen.setColor(Qt::red);
            pen.setWidth(3);
            painter.setPen(pen);
            QPixmap pixmap;
            pixmap = QPixmap::fromImage(image.scaled(labelvideo->size(),Qt::KeepAspectRatio));
            labelvideo->setPixmap(pixmap);
            labelvideo->update();
            cloneFrame.unmap();
        }
        return true;
    }
    return false;
 }

void  Showvideo::setvideolabel(QLabel* label)
{
  labelvideo = label;
}

void  Showvideo::setvediosource(Showvideo::VideoSource source)
{
    videosource = source;
}
