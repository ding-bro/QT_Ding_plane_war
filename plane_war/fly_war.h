 #ifndef FLY_WAR_H
#define FLY_WAR_H

//#include <QWidget>
#include <QMainWindow>
#include<QTimer>
#include"fly_map.h"
#include"myplane.h"
#include"bullet.h"
#include"enemyplane.h"
#include"boom.h"

namespace Ui {
class fly_war;
}

class fly_war : public QMainWindow
{
    Q_OBJECT

public:
    explicit fly_war(QMainWindow *parent = 0);


    // 初始化窗口
    void initfly();


    // 重写画图事件
    void paintEvent(QPaintEvent *event);


    // 启动游戏
    void startgame();


    // 更新游戏中的所有元素坐标
    void update_pos();


    // 重写鼠标事件
    void mouseMoveEvent(QMouseEvent *event);


    // 敌机出场
    void enemycome();


    // 重写按键按下事件   (上下左右)
    void keyPressEvent(QKeyEvent *event);


    // 碰撞检测
    void crashcheck();


public:
    // 定时器
    QTimer m_timer;

    // 地图对象
    Fly_map map;

    // 飞机对象
    myplane plane;

    // 子弹对象
    bullet m_bullet;

    // 敌机对象
    enemyplane enemy;

    // 敌机数量
    enemyplane m_enemy[Enemy_num];

    // 记录敌机出场
    int m_recorder;

    // 爆炸数组
    boom m_boom[Boom_num];

    //hellmodel hell;

    //bool ishell;

    ~fly_war();

private:
    Ui::fly_war *ui;
};












#endif // FLY_WAR_H
