#include "csnakeframe.h"
#include <QPalette>
#include <QTime>
#include <QPainter>

CSnakeFrame::CSnakeFrame(QWidget* parent):QFrame(parent)
{
    //this->setGeometry(0, 0, 500, 500);
    this->setFixedSize(500, 500);
    setAutoFillBackground(true);
    QPalette l_p = palette();
    l_p.setColor(QPalette::Window, QColor(48, 100, 100, 200));
    this->setPalette(l_p);
    QTime l_cur_time = QTime::currentTime();
    qsrand(l_cur_time.msec() + l_cur_time.second()*1000);

    connect(&m_timer, m_timer.timeout, this, m_Move_Snake);

    m_Init_Scene();
}


void CSnakeFrame::m_Gene_Food()
{
    QPoint l_point;
    while(1)
    {
        l_point.rx() = qrand()%100 * 5;
        l_point.ry() = qrand()%100 * 5;

        if (m_snake_list.contains(l_point))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    m_food_pos = l_point;

}

void CSnakeFrame::m_Move_Snake()
{
    MoveCase l_move_case = m_Get_Move_Case();
    switch(l_move_case)
    {
    case StepMove:
        m_Step_Move();
        break;
    case CrashWall:
        m_Game_Over();
        break;
    case EatFood:
        m_Eat_Food();
        break;
    default:
        break;
    }
    update();
    return ;
}

void CSnakeFrame::m_Eat_Food()
{
    m_snake_list.append(m_food_pos);
    m_Gene_Food();
    if (m_move_spd >= 80)
    {
        m_move_spd -= 5;
    }
    m_timer.setInterval(m_move_spd);
    emit m_Eat_Food_Sig();
}

void CSnakeFrame::m_Step_Move()
{
    QPoint l_new_head = m_snake_list.last();
    if (m_dir == Up)
    {
        l_new_head.ry() -= 5;
    }
    else if (m_dir == Down)
    {
        l_new_head.ry() += 5;
    }
    else if (m_dir == Left)
    {
        l_new_head.rx() -= 5;
    }
    else
    {
        l_new_head.rx() += 5;
    }
    m_snake_list.removeFirst();
    m_snake_list.append(l_new_head);
}

void CSnakeFrame::m_Game_Over()
{
    m_is_over = true;
    m_pause = true;
    update();
    emit m_Game_Over_Sig();
}

CSnakeFrame::MoveCase CSnakeFrame::m_Get_Move_Case()
{
    QPoint l_head = m_snake_list.last();
    MoveCase l_ret = StepMove;
    switch (m_dir) {
    case Up:
        l_head.ry() -= 5;
        break;
    case Down:
        l_head.ry() += 5;
        break;
    case Left:
        l_head.rx() -= 5;
        break;
    case Right:
        l_head.rx() += 5;
        break;
    default:
        break;
    }
    if (l_head.rx() < 0 ||
            l_head.rx() >= 500||
            l_head.ry() < 0||
            l_head.ry() >= 500)
    {
        l_ret = CrashWall;
    }
    else if (m_snake_list.contains(l_head))
    {
        l_ret = CrashWall;
    }
    else if (l_head.rx() == m_food_pos.rx()&&
             l_head.ry() == m_food_pos.ry())
    {
        l_ret = EatFood;
    }
    else
    {
        l_ret = StepMove;
    }
    return l_ret;
}

void CSnakeFrame::m_Init_Scene()
{
    m_snake_list.clear();
    m_snake_list.append(QPoint(0, 0));
    m_Gene_Food();
    m_dir = Right;
    m_is_over = false;
    m_Pause_Game();
    m_move_spd = 300;
    m_timer.setInterval(m_move_spd);
    update();
}

void CSnakeFrame::keyPressEvent(QKeyEvent *event)
{
    static bool l_first = true;
    if (event->key() == Qt::Key_P)
    {
        if (false == m_is_over)
        {
            if (false == m_pause)
                m_Pause_Game();
            else
            {
                m_Start_Game();

                if (l_first)
                {
                    emit m_Replay_Game_Sig();
                    l_first = false;
                }

            }
        }
    }
    else if (event->key() == Qt::Key_W||
             event->key() == Qt::Key_Up)
    {
        if (Down != m_dir)
        {
            m_dir = Up;
        }
    }
    else if (event->key() == Qt::Key_S||
             event->key() == Qt::Key_Down)
    {
        if (Up != m_dir)
        {
            m_dir = Down;
        }
    }
    else if (event->key() == Qt::Key_A||
             event->key() == Qt::Key_Left)
    {
        if (Right != m_dir)
        {
            m_dir = Left;
        }
    }
    else if (event->key() == Qt::Key_D||
             event->key() == Qt::Key_Right)
    {
        if (Left != m_dir)
        {
            m_dir = Right;
        }
    }
    else if (event->key() == Qt::Key_R)
    {
        m_Replay_Game();
    }
}

void CSnakeFrame::m_Start_Game()
{
    m_pause = false;
    if (!m_timer.isActive())
    {
        m_timer.start();
    }
}

void CSnakeFrame::m_Pause_Game()
{

    m_pause = true;
    if (m_timer.isActive())
    {
        m_timer.stop();
    }
}

void CSnakeFrame::m_Replay_Game()
{
    m_Init_Scene();
    emit m_Replay_Game_Sig();
}

void CSnakeFrame::m_Draw_Snake()
{
    QPainter l_painter(this);
    QPoint l_p;
    if (true == m_is_over)
    {
        //Draw Game Over
        l_painter.setPen(QPen(QColor(255,0,0,150)));
        l_painter.drawText(100, 200, 300, 100, Qt::AlignCenter, "GAME OVER!!!");
        return ;
    }
    else
    {
        if (m_snake_list.empty())
        {
            return ;
        }
        l_painter.setBrush(QColor(255,0,0, 200));
        l_p = m_snake_list.back();
        l_painter.drawRect((int)l_p.rx(), (int)l_p.ry(), 5, 5);
        l_painter.setBrush(QColor(0, 155,155, 200));
        for (QList<QPoint>::iterator i = m_snake_list.begin(); (i != m_snake_list.end() )&& (i != (m_snake_list.end() - 1)); ++i)
        {
            l_painter.drawRect((int)((QPoint)*i).rx(), (int)((QPoint)*i).ry(), 5, 5);
        }
    }
    //Draw Food
    l_painter.setBrush(QColor(11, 215, 18, 230));
    l_painter.drawRect((int)m_food_pos.rx(), m_food_pos.ry(), 5, 5);
}

void CSnakeFrame::paintEvent(QPaintEvent *)
{
    m_Draw_Snake();
}
