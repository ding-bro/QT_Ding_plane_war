#include "boom.h"

boom::boom()
{
    for(int i = 1; i <= Boom_max; i++)  // 从bomb-1开始
    {
        QString str = QString(Boom_img).arg(i);  // 将路径转为bomb-1 ~ bomb-7
        this->pix_boom.push_back(QPixmap(str));    // 插入容器中
    }

    //this->boom_free = false; // 默认不爆炸

    // 默认位置置为0
    this->m_x = 0;
    this->m_y = 0;

    this->m_recorder = 0;  // 爆炸时间累积置为0

    this->m_index = 0 ; // 图片下标置为0

    this->boom_free = false; // 默认不爆炸
}


void boom::updateinfo()
{
    if(this->boom_free == false)  // 如果不是爆炸状态，return
    {
        return;
    }

    this->m_recorder ++;  // 爆炸时间开始累积

    if(this->m_recorder < Boom_time)  // 没有到爆炸时间不爆炸,return
    {
        return;
    }

    this->m_recorder = 0;  // 重置爆炸时间的记录

    this->m_index ++; // 图片下标开始累积

    if(this->m_index > Boom_max - 1 )  // 如果图片下标累积大于了7次，重置图片下标，置为不爆炸状态
    {
        this->m_index = 0;
        this->boom_free = false;
    }
}













