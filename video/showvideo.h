#ifndef Showvideo_H
#define Showvideo_H
#include <QAbstractVideoSurface>
#include <QPixmap>
#include <QLabel>
#include <vector>
#include <opencv2/core/core.hpp>
#include "mainwindow.h"
/*class Showvideo
{
public:
    Showvideo();
};
#endif // Showvideo_H*/
class Showvideo:public QAbstractVideoSurface
{
    Q_OBJECT
 public:
    enum VideoSource{
        camera = 0,
        video = 1,
    };
    explicit Showvideo(QObject *parent = 0);
  // QAbstractVideoSurface interface
public:
    virtual QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const override;
    virtual bool present(const QVideoFrame &frame) override;
public:
   void setvideolabel(QLabel* label);
   void setvediosource(VideoSource source);
private:
       QLabel *labelvideo;
       VideoSource videosource;
       //Humandetect *human;
      // std::vector<cv::Rect> humanrect;
};

#endif // Showvideo_H
