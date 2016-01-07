#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "csnakeframe.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLabel *m_record;
    QLabel *m_score;
    QLabel *m_sped;
    QLabel *m_time;

    QFrame m_right_frame;
    CSnakeFrame m_left_frame;

    int m_record_num;
    int m_score_num;
    int m_spd_num;
    int m_time_num;
    QTimer m_timer;

private:
    void m_Layout_Right_Frame();
    void m_Layout_Main_Frame();
    void m_Set_Label_Content();


public slots:
    void m_Set_Score_Num();
    void m_Set_Spd_Num();
    void m_Set_Start();
    void m_Set_Over();
    void m_Set_Timer();

};

#endif // WIDGET_H
