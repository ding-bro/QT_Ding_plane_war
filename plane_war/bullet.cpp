#include "bullet.h"

bullet::bullet()
{
    this->m_bullet.load(M_bullet);

    this->m_bullet_x = Fly_width * 0.5 - this->m_bullet.width();  // X在窗口中间
    this->m_bullet_y = Fly_height;  // Y在窗口底部

    this->bullet_free = false; // 默认子弹不发射

    this->m_rect.setWidth(this->m_bullet.width());
    this->m_rect.setHeight(this->m_bullet.height());
    this->m_rect.moveTo(this->m_bullet_x,this->m_bullet_y);  // 设置矩形框
}



void bullet::updatebulletpos()
{
    if(this->bullet_free == false)  // 子弹不发射时，不更新坐标
    {
        return;
    }


    this->m_bullet_y -= Bullet_speed;  // 子弹从底部往上发射
    this->m_rect.moveTo(this->m_bullet_x,this->m_bullet_y); // 将子弹进行发射
    if(this->m_bullet_y <= -this->m_rect.height())  // 当子弹在窗口外时
    {
        this->bullet_free = false;  // 将子弹状态置为false,不发射
    }
}














