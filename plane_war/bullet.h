#ifndef BULLET_H
#define BULLET_H

#include"mydata.h"
#include<QPixmap>


class bullet
{
public:
    bullet();

    // 更新子弹坐标
    void updatebulletpos();


public:

    // 子弹对象
    QPixmap m_bullet;

    // 子弹坐标
    int m_bullet_x;
    int m_bullet_y;

    // 子弹移动速度
    int m_bullet_speed;

    // 子弹状态
    bool bullet_free;  // 用于约束子弹的发射

    // 子弹的矩形边框
    QRect m_rect;


};

#endif // BULLET_H




