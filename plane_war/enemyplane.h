#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include"mydata.h"
#include<QPixmap>


class enemyplane
{
public:
    enemyplane();

    // 更新敌机坐标
    void updateenemypos();


public:
    // 敌机对象
    QPixmap m_enemy;

    // 敌机坐标
    int m_enemy_x;
    int m_enemy_y;

    // 矩形框
    QRect m_rect;

    // 敌机状态
    bool m_free;


};

#endif // ENEMYPLANE_H









