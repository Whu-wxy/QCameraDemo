#include "camera.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
camera::camera(QCameraViewfinder *parent)
    : QCameraViewfinder(parent)
{
    showFullScreen();

    cmr=new QCamera(this);
    cmr->setViewfinder(this);



    cmr->setCaptureMode(QCamera::CaptureVideo);//如果在android系统下运行就这样设置



    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras) {
        qDebug()<<"deviceName: "<<cameraInfo.deviceName();
    }


    QCameraViewfinderSettings settings;  //QVideoFrame::Format_YUYV
    settings.setPixelFormat(QVideoFrame::Format_NV21); //设置像素格式  Android上只支持NV21格式
    settings.setResolution(QSize(640, 480)); //设置摄像头的分辨率
    cmr->setViewfinderSettings(settings);

    capture=new QCameraImageCapture(cmr);
    cmr->setCaptureMode(QCamera::CaptureViewfinder);
    imgPro=cmr->imageProcessing();
    if (imgPro->isAvailable())
    {
        imgPro->setWhiteBalanceMode(QCameraImageProcessing::WhiteBalanceAuto);
        imgPro->setDenoisingLevel(-0.3);
        imgPro->setBrightness(0.3);
    }
    cmr->start();

    capBtn=new QPushButton;
    capBtn->setMaximumSize(100,100);
    capBtn->setMinimumSize(100,100);
    capBtn->setStyleSheet("QPushButton{background:transparent;}"
                          "QPushButton{image:url(:/ICO/i.ico);}"
                          "QPushButton:pressed{image:url(:/ICO/i2.ico);}");
    capBtn->setIconSize(QSize(100, 100));

    connect(capBtn,SIGNAL(clicked(bool)),this,SLOT(Capture()));



    QHBoxLayout *hLayout=new QHBoxLayout;
    hLayout->addStretch();
    hLayout->addWidget(capBtn);
    hLayout->addStretch();

    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addLayout(hLayout);

    connect(cmr, static_cast<void(QCamera::*)(QCamera::Error)>(&QCamera::error),
          [=](QCamera::Error value){ qDebug()<<cmr->errorString(); });
}

camera::~camera()
{
    cmr->stop();
}

void camera::Capture()
{

    capture->capture();

}
