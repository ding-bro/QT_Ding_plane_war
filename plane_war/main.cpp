#include "fly_war.h"
#include <QApplication>

#include<QResource>  // 配置二进制文件
#include"mydata.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 文件过大，配置二进制文件缩小空间
    QResource::registerResource(Binary_path);  // rcc文件在Debug下生成

    // 注册rcc文件放在show之前
    fly_war w;
    w.show();


    return a.exec();
}
