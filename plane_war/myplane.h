#ifndef MYPLANE_H
#define MYPLANE_H

#include<QPixmap>
#include"mydata.h"
#include<QPainter>
#include"bullet.h"

class myplane
{
public:
    myplane();

    // 发射子弹
    void shoot();

    // 设置飞机位置
    void setplanepos(int x,int y);


public:
    // 飞机对象
    QPixmap m_plane;

    // 飞机坐标
    int m_plane_x;
    int m_plane_y;

    // 飞机的坐标矩形  以此检测飞机的位置
    QRect m_Rect;

    // 弹匣
    bullet m_bullet[Bullet_num];

    // 发射时间记录
    int m_recorder;
};

#endif // MYPLANE_H










