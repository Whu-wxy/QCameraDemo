#ifndef CAMERA_H
#define CAMERA_H

#include <QDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include<QCameraImageCapture>
#include <QPushButton>
#include <QCameraImageProcessing>
#include <QCameraInfo>
#include <QDebug>

class camera : public QCameraViewfinder
{
    Q_OBJECT

public:
    camera(QCameraViewfinder *parent = 0);
    ~camera();

private:
    QCamera *cmr;
    QCameraImageCapture *capture;
    QPushButton *capBtn;
    QCameraImageProcessing *imgPro;

private slots:
    void Capture();


};

#endif // CAMERA_H
