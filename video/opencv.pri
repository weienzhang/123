#opencvconfiguration
#CONFIG += opencv2.4
CONFIG += opencv3.0



opencv3.0{
    OPENCV_VERSION = 3.0.0
  #  OPENCV_PATH =  D:/opencv/opencv3.0.0/build
    OPENCV_PATH =  D:/Users/opencv/build
    OPENCV_LIB_PATH = $$OPENCV_PATH/x64/vc12/lib

    INCLUDEPATH += $$OPENCV_PATH/include
    DEPENDPATH  += $$OPENCV_PATH/include

    CONFIG(release, debug|release){
        LIBS += -L$$OPENCV_LIB_PATH -lopencv_ts300
        LIBS += -L$$OPENCV_LIB_PATH -lopencv_world300
    }else{
        LIBS += -L$$OPENCV_LIB_PATH -lopencv_ts300d
        LIBS += -L$$OPENCV_LIB_PATH -lopencv_world300d
    }
}#opencv3.0
