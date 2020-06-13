#include "fly_map.h"
#include"mydata.h"
#include<QPixmapCache>


Fly_map::Fly_map()
{
    // 初始化地图
    m_pix1.load(Fly_background);
    m_pix2.load(Fly_background);
    m_pix3.load(Fly_background);

//    if(this->ishell == false)
//    {
//        //QPixmapCache::clear();
//        m_pix1.load(Fly_background);
//        m_pix2.load(Fly_background);
//        m_pix3.load(Fly_background);
//    }
//    else
//    {
//        m_pix4.load(":/Fly_photo/img_bg_level_5.jpg");
//        m_pix5.load(":/Fly_photo/img_bg_level_5.jpg");
//        m_pix6.load(":/Fly_photo/img_bg_level_5.jpg");
//    }



    // 初始化Y轴坐标
    map1_y = -768;  // 第一张在窗口的正上方    512*768  为图片尺寸
    map2_y = 0;  // 第二张与窗口重叠
    map3_y = 768; // 第三张铺满窗口


    // 地图滚动速度
    roll_speed = Map_roll_speed;   
}


void Fly_map::map_roll_pos()
{
    // 第一张图片滚动
    map1_y += Map_roll_speed;
    if(map1_y >= 0)  // 当第一张图片踏入窗口时
    {
        map1_y = -768;  // 回初始位置
    }

    // 第二张图片滚动
    map2_y += Map_roll_speed;
    if(map2_y >= 768)  // 当第二张图片超出窗口时
    {
        map2_y = 0;   // 回初始位置
    }

    // 第三张图片滚动
    map3_y += Map_roll_speed;
    if(map3_y >= 1536)  // 第三张图片超出map3的尺寸时
    {
        map3_y = 768 ;
    }
}













