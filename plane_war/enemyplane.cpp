#include "enemyplane.h"

enemyplane::enemyplane()
{
    this->m_enemy.load(M_enemy);

    this->m_free = false; // 默认敌机不出场

    this->m_enemy_x = 0;
    this->m_enemy_y = 0;

    this->m_rect.setWidth(this->m_enemy.width());
    this->m_rect.setHeight(this->m_enemy.height());
    this->m_rect.moveTo(this->m_enemy_x,this->m_enemy_y);


}


void enemyplane::updateenemypos()
{
    if(this->m_free == false)  // 不出场时return
    {
        return;
    }

    this->m_enemy_y += Enemy_speed;  // 敌机由上往下出场
    this->m_rect.moveTo(this->m_enemy_x,this->m_enemy_y);

    if(this->m_enemy_y >= Fly_height + this->m_rect.height())  // 敌机超出屏幕重置
    {
        this->m_free = false;
    }
}










