#ifndef BOOM_H
#define BOOM_H

#include<QVector>
#include<QPixmap>
#include"mydata.h"


class boom
{
public:
    boom();


    void updateinfo();  // 更新信息(播放图片的下标，播放间隔)

public:

    bool boom_free;   // 爆炸的状态

    QVector<QPixmap>pix_boom;  // 存放爆炸图片的容器

    // 爆炸的位置
    int m_x;
    int m_y;

    int m_recorder;  // 记录爆炸的时间

    int m_index;  // 记录图片的下标
};

#endif // BOOM_H

















