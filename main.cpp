#include "camera.h"
#include <QApplication>
#include "cameraprobe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    camera w;
//    w.show();

    CameraProbe w;
    w.show();

    return a.exec();
}
