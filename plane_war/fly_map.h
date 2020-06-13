#ifndef FLY_MAP_H
#define FLY_MAP_H

#include<QPixmap>
#include"mydata.h"
#include<QSound>

class Fly_map
{
public:
    Fly_map();


    void map_roll_pos();  // 地图滚动坐标


public:
    // 图片对象     地图滚动基于三张重叠的图片
    QPixmap m_pix1;
    QPixmap m_pix2;
    QPixmap m_pix3;


    // 地图Y坐标
    int map1_y;
    int map2_y;
    int map3_y;

    int roll_speed;  // 地图滚动速度

    bool ishell;
};

#endif // FLY_MAP_H










