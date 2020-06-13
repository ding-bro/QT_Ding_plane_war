#include "fly_war.h"
#include "ui_fly_war.h"
#include<QIcon>
#include<QMenuBar>
#include<QPainter>
#include<QMouseEvent>
#include<ctime>
#include<QKeyEvent>
#include<QMessageBox>


fly_war::fly_war(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::fly_war)
{
    ui->setupUi(this);

    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    QMenu * pass = bar->addMenu("功能");

    QAction * explain = pass->addAction("操作说明");
    QAction * exit = pass->addAction("退出游戏");

    connect(explain,&QAction::triggered,[=](){
        QString str1 = "操作说明";
        QString str2 = "DYN:\n飞机可用鼠标拖拽\n飞机可用键盘操控\n游戏参数在mydata中可修改";
        QMessageBox::question(this,str1,str2,QStringLiteral("确定"));
    });

    connect(exit,&QAction::triggered,[=](){
        this->close();
    });


    this->initfly();  // 初始化窗口


    this->m_timer.setInterval(Timer_speed);  // 设置定时器刷新间隔

    this->startgame();


}


void fly_war::initfly()
{
    this->setFixedSize(Fly_width,Fly_height);
    this->setWindowTitle(Fly_title);
    this->setWindowIcon(QIcon(Fly_icon));

    this->m_recorder = 0; // 敌机出场计数器清零

    srand((unsigned int )time(NULL));  // 敌机出场随机数种子
}




void fly_war::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    QPixmap pix;

    pix.load(Fly_background);   // 加载背景图片

    paint.drawPixmap(0,0,this->width(),this->height(),pix);


    // 地图滚动
    paint.drawPixmap(0,this->map.map1_y,this->map.m_pix1);
    paint.drawPixmap(0,this->map.map2_y,this->map.m_pix2);
    paint.drawPixmap(0,this->map.map3_y,this->map.m_pix3);


    // 绘制飞机
    paint.drawPixmap(this->plane.m_Rect,this->plane.m_plane);

    // 测试子弹
    //paint.drawPixmap(m_bullet.m_rect,m_bullet.m_bullet);

    // 绘制子弹
    for(int i = 0;i < Bullet_num;i++)
    {
        if(this->plane.m_bullet[i].bullet_free == true)  // 只显示发射状态的子弹
        {
             paint.drawPixmap(this->plane.m_bullet[i].m_rect,this->plane.m_bullet[i].m_bullet);
        }
    }

    // 绘制敌机
    for(int i = 0;i < Enemy_num; i++)
    {
        if(this->m_enemy[i].m_free == true) // 只显示出场状态的敌机
        {
            paint.drawPixmap(this->m_enemy[i].m_rect,this->m_enemy[i].m_enemy);
        }
    }


    // 绘制爆炸效果
    for(int i = 0;i < Boom_num; i++)
    {
        if(this->m_boom[i].boom_free == true)
        {
            paint.drawPixmap(this->m_boom[i].m_x,this->m_boom[i].m_y,this->m_boom[i].pix_boom[this->m_boom[i].m_index]); // 播放的是容器中的图片下标元素
        }
    }
}


void fly_war::startgame()
{
    // 启动定时器
    m_timer.start();

    // 播放背景音乐
    QSound::play(Sound_background);

    // 定时器发送信号
    connect(&m_timer,&QTimer::timeout,[=](){
        // 敌机出场
        this->enemycome();

        this->update_pos();   // 更新坐标
        update();  //  调用paintevent画图事件内函数

        // 碰撞检测
        this->crashcheck();
    });
}


void fly_war::update_pos()
{
    this->map.map_roll_pos(); // 更新地图坐标

    // 测试子弹发射
    //m_bullet.bullet_free = false;  // 子弹置为发射状态
    //m_bullet.updatebulletpos();   // 更新子弹坐标

    // 发射子弹
    this->plane.shoot();

    // 更新发射状态的子弹的坐标
    for(int i = 0;i < Bullet_num;i++)
    {
        if(this->plane.m_bullet[i].bullet_free == true)  // 在发射状态
        {
           this->plane.m_bullet[i].updatebulletpos();
        }
    }

    // 敌机出场/更新出场坐标
    for(int i = 0;i < Enemy_num; i++)
    {
        if(this->m_enemy[i].m_free == true)
        {
            this->m_enemy[i].updateenemypos();
        }
    }

    // 更新爆炸坐标
    for(int i = 0;i < Boom_num; i++)
    {
        if(this->m_boom[i].boom_free == true)
        {
            this->m_boom[i].updateinfo();
        }
    }
}


void fly_war::mouseMoveEvent(QMouseEvent *event)
{
    // 做减法是为了让鼠标拖拽时鼠标在图片的正中间
    int x = event->x() - this->plane.m_plane.width() / 2;
    int y = event->y() - this->plane.m_plane.height() / 2;

    // 边界检测
    if(x <= 0)
    {
        x = 0;
    }
    else if(x >= Fly_width - plane.m_Rect.width())
    {
        x = Fly_width - plane.m_Rect.width();
    }
    else if(y <= 0)
    {
        y = 0;
    }
    else if(y >= Fly_height - plane.m_Rect.height())
    {
        y = Fly_height - plane.m_Rect.height();
    }

    this->plane.setplanepos(x,y);   // x和y记录鼠标点击的位置
}


void fly_war::enemycome()
{
    this->m_recorder++;

    if(this->m_recorder < Enemy_time)  // 没到出场时间return
    {
        return;
    }

    this->m_recorder = 0;

    for(int i = 0;i < Enemy_num; i++)
    {
        if(this->m_enemy[i].m_free == false) // 不是出场状态就置为出场状态
        {
            this->m_enemy[i].m_free = true;

            this->m_enemy[i].m_enemy_x = rand() % (Fly_width - this->m_enemy[i].m_rect.width()); // 敌机的出场横坐标生成随机数
            this->m_enemy[i].m_enemy_y = -this->m_enemy[i].m_rect.height(); // 敌机由窗口上方出场
            break;
        }
    }

}


void fly_war::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)  // 上
    {        
        this->plane.m_Rect.moveTo(this->plane.m_plane_x,this->plane.m_plane_y -= Plane_move_speed);
        if(this->plane.m_plane_y < 10)  // 10是进行微调后的数值
        {
            this->plane.m_plane_y = 10;
        }
    }
    else if(event->key() == Qt::Key_Down)  // 下
    {
        this->plane.m_Rect.moveTo(this->plane.m_plane_x,this->plane.m_plane_y += Plane_move_speed);
        if(this->plane.m_plane_y > Fly_height - this->plane.m_plane.height() - 10)
        {
            this->plane.m_plane_y = Fly_height - this->plane.m_plane.height() - 10;
        }
    }
    else if(event->key() == Qt::Key_Left)  // 左
    {
        this->plane.m_Rect.moveTo(this->plane.m_plane_x -= Plane_move_speed,this->plane.m_plane_y);
        if(this->plane.m_plane_x < 10)
        {
            this->plane.m_plane_x = 10;
        }
    }
    else if(event->key() == Qt::Key_Right)  // 右
    {
        this->plane.m_Rect.moveTo(this->plane.m_plane_x += Plane_move_speed,this->plane.m_plane_y);
        if(this->plane.m_plane_x > Fly_width - this->plane.m_plane.width() - 10)
        {
            this->plane.m_plane_x = Fly_width - this->plane.m_plane.width() - 10;
        }
    }
}



void fly_war::crashcheck()
{
    for(int i = 0; i < Enemy_num; i++)
    {
        if(this->m_enemy[i].m_free == false)   // 敌机不出现时执行下一次循环，直到找到敌机为true
        {
            continue;
        }

        for(int j = 0; j < Bullet_num; j++)
        {
            if(this->plane.m_bullet[j].bullet_free == false)   // 子弹不发射时执行下一次循环，直到找到子弹发射
            {
                continue;
            }

            if(this->m_enemy[i].m_rect.intersects(this->plane.m_bullet[j].m_rect) == true)  // 敌机和子弹的矩形框相交代表碰撞
            {
                // 碰撞之后，重新置为敌机不出现/子弹不发射状态
                this->m_enemy[i].m_free = false;
                this->plane.m_bullet[j].bullet_free = false;

                // 敌机和子弹碰撞之后播放爆炸效果
                for(int k = 0;k < Boom_num; k++)
                {
                    if(this->m_boom[k].boom_free == false)  // 如果不是爆炸状态置为爆炸状态
                    {
                        // 播放爆炸音效
                        QSound::play(Sound_boom);

                        this->m_boom[k].boom_free = true;

                        // 更新爆炸的坐标，与敌机此时的坐标相同
                        this->m_boom[k].m_x = this->m_enemy[i].m_enemy_x;
                        this->m_boom[k].m_y = this->m_enemy[i].m_enemy_y;
                        break;
                    }
                }
            }
            else if(this->m_enemy[i].m_rect.intersects(this->plane.m_Rect) == true)
            {
                this->m_enemy[i].m_free = false;    // 敌机与飞机本身碰撞，让敌机消失

                // 敌机和飞机碰撞之后播放爆炸效果
                for(int n = 0;n < Boom_num; n++)
                {
                    if(this->m_boom[n].boom_free == false)  // 如果不是爆炸状态置为爆炸状态
                    {
                        // 播放爆炸音效
                        QSound::play(Sound_boom);

                        this->m_boom[n].boom_free = true;

                        // 更新爆炸的坐标，与敌机此时的坐标相同
                        this->m_boom[n].m_x = this->m_enemy[i].m_enemy_x;
                        this->m_boom[n].m_y = this->m_enemy[i].m_enemy_y;
                        break;
                    }
                }
            }
        }
    }
}





fly_war::~fly_war()
{
    delete ui;
}








