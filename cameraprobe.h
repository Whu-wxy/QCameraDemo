#ifndef CAMERAPROBE_H
#define CAMERAPROBE_H

#include <QObject>

#include <QWidget>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QFile>
#include <QUrlQuery>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QBuffer>
#include <QFileDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QTimer>
#include <QAbstractVideoSurface>
#include <QVideoProbe>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class CameraProbe : public QLabel
{
    Q_OBJECT
public:
    CameraProbe(QWidget *parent=nullptr);

    QLabel*      label_ImageDisplay;
    QPushButton* pushButton_open_camera;
    QPushButton* pushButton_stop;
    QPushButton* pushButton_Camear_up;
    QComboBox*   comboBox;

    QCamera * camera;
    QCameraViewfinder* viewfinder;
    QTimer *timer;
    QCameraViewfinder * view_finder; //取景器
    QList<QCameraInfo> cameras;      //存放系统支持的摄像头列表
    QCameraImageCapture* camera_image_capture;
    QImageEncoderSettings iamge_setting;
    QVideoProbe *m_pProbe;
    void YUV420P_to_RGB24(unsigned char *data, unsigned char *rgb, int width, int height);
    void NV21_TO_RGB24(unsigned char *data, unsigned char *rgb, int width, int height);
    void YUV420P_TO_RGB24(unsigned char *yuv420p, unsigned char *rgb24, int width, int height);
    void yuyv_to_rgb(unsigned char *yuv_buffer,unsigned char *rgb_buffer,int iWidth,int iHeight);
private slots:
    void slotOnProbeFrame(const QVideoFrame &frame);
    void on_pushButton_open_camera_clicked(bool);
    void on_pushButton_Camear_up_clicked(bool);
    void on_pushButton_stop_clicked(bool);


};

#endif // CAMERAPROBE_H
