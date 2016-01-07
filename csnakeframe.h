#ifndef CSNAKEFRAME_H
#define CSNAKEFRAME_H

#include <QFrame>
#include <QPoint>
#include <QList>
#include <QKeyEvent>
#include <QTimer>
#include <QPaintEvent>
#include <QObject>
class CSnakeFrame : public QFrame
{
Q_OBJECT

public:
    enum Dir{
        Up = 0,
        Down,
        Left,
        Right
    };

    enum MoveCase{
        StepMove = 0,
        EatFood,
        CrashWall
    };


public:
    CSnakeFrame(QWidget* parent = 0);
public:
    Dir m_dir;
    QList<QPoint> m_snake_list;
    QPoint m_food_pos;
    bool m_pause;
    bool m_is_over;
    QTimer m_timer;
    int m_move_spd;

signals:
    void m_Eat_Food_Sig();
    void m_Game_Over_Sig();
    void m_Replay_Game_Sig();

public:
    void m_Init_Scene();
    void m_Draw_Snake();
    void m_Gene_Food();

    void m_Step_Move();
    void m_Move_Snake();
    void m_Pause_Game();
    void m_Start_Game();
    void m_Eat_Food();
    void m_Game_Over();
    void m_Replay_Game();

    MoveCase m_Get_Move_Case();
    virtual void keyPressEvent(QKeyEvent*);
    virtual void paintEvent(QPaintEvent*);
};

#endif // CSNAKEFRAME_H
