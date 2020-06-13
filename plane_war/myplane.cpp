#include "myplane.h"

myplane::myplane()
{
    this->m_plane.load(M_plane);

    this->m_plane_x = (Fly_width - m_plane.width()) / 2; // 中间
    this->m_plane_y = Fly_height - m_plane.height();

    this->m_Rect.setWidth(m_plane.width());
    this->m_Rect.setHeight(m_plane.height());
    this->m_Rect.moveTo(m_plane_x,m_plane_y); // 设置矩形框位置,与飞机位置相同
}

void myplane::setplanepos(int x, int y)
{
    this->m_plane_x = x;
    this->m_plane_y = y;
    this->m_Rect.moveTo(this->m_plane_x,this->m_plane_y);
}

void myplane::shoot()
{
    // 累计发射时间
    this->m_recorder++;

    // 没有到发射时间时，return
    if(this->m_recorder < Bullet_time)
    {
        return;
    }

    // 达到发射时间之后,重置时间
    this->m_recorder = 0;

    for(int i = 0;i < Bullet_num; i++)
    {
        if(this->m_bullet[i].bullet_free==false)  // 如果不是发射状态，置为发射
        {
            this->m_bullet[i].bullet_free = true;

            this->m_bullet[i].m_bullet_x = this->m_plane_x + this->m_plane_x/4;  // 进行微调
            this->m_bullet[i].m_bullet_y = this->m_plane_y; // 子弹从飞机的上方发射
            break;
        }
    }
}








