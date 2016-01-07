#include "widget.h"
#include <QTextStream>
#include <QFile>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_Layout_Main_Frame();
    setAutoFillBackground(true);
    QPalette l_palette = palette();
    l_palette.setColor(QPalette::Window, QColor(255, 255, 255));
    setPalette(l_palette);
    connect(&m_timer, m_timer.timeout, this, m_Set_Timer);
    connect(&m_left_frame, m_left_frame.m_Eat_Food_Sig, this, m_Set_Score_Num);
    connect(&m_left_frame, m_left_frame.m_Eat_Food_Sig, this, m_Set_Spd_Num);
    connect(&m_left_frame, m_left_frame.m_Game_Over_Sig, this, m_Set_Over);
    connect(&m_left_frame, m_left_frame.m_Replay_Game_Sig, this, m_Set_Start);

    m_left_frame.setFocusPolicy(Qt::StrongFocus);
    m_left_frame.setFocus();
}

Widget::~Widget()
{

}

void Widget::m_Set_Label_Content()
{
    m_record->setText(QString().sprintf("Record: %d", m_record_num));
    m_score->setText(QString().sprintf("Score: %d", m_score_num));
    m_sped->setText(QString().sprintf("Speed: %d", m_spd_num));
    m_time->setText(QString().sprintf("Time: %d", m_time_num));
}

void Widget::m_Layout_Right_Frame()
{
    m_record_num = 0;
    m_score_num = 0;
    m_spd_num = 0;
    m_time_num = 0;
    //Read Config
    QFile l_file("Config.txt");
    if (l_file.open(QIODevice::ReadWrite))
    {
        QTextStream l_stream(&l_file);
        m_record_num = l_stream.readLine().toInt();
        l_file.close();
    }
    m_record = new QLabel();
    m_score = new QLabel();
    m_sped = new QLabel();
    m_time = new QLabel();
    //Set Label Content
    m_Set_Label_Content();

    //Layout All the Labels
    QVBoxLayout *l_layout = new QVBoxLayout();
    l_layout->addWidget(m_record);
    l_layout->addWidget(m_score);
    l_layout->addWidget(m_sped);
    l_layout->addWidget(m_time);
    l_layout->addWidget(new QLabel("W: Up"));
    l_layout->addWidget(new QLabel("S: Down"));
    l_layout->addWidget(new QLabel("A: Left"));
    l_layout->addWidget(new QLabel("D: Right"));
    l_layout->addWidget(new QLabel("P: Pause/Start"));
    l_layout->addWidget(new QLabel("R: Replay"));
    l_layout->setMargin(5);
    l_layout->setSpacing(20);
    m_right_frame.setLayout(l_layout);
    QPalette l_palette = m_right_frame.palette();
    m_right_frame.setAutoFillBackground(true);
    l_palette.setColor(QPalette::Window, QColor(48, 100, 100));
    l_palette.setColor(QPalette::WindowText, QColor(0, 0, 0, 200));
    m_right_frame.setPalette(l_palette);
    m_right_frame.setFixedSize(100, 500);
}

void Widget::m_Layout_Main_Frame()
{
    QHBoxLayout *l_main_layout = new QHBoxLayout();
    //m_left_frame.setGeometry(0, 0, 500, 500);
    //m_left_frame.setMinimumSize(200, 200);
    m_Layout_Right_Frame();
    l_main_layout->addWidget(&m_left_frame);
    l_main_layout->addWidget(&m_right_frame);
    l_main_layout->setMargin(5);
    //l_main_layout->setSpacing(20);
    setLayout(l_main_layout);
}

void Widget::m_Set_Score_Num()
{
    m_score_num += 10;
    m_Set_Label_Content();
}

void Widget::m_Set_Spd_Num()
{
    m_spd_num += 1;
    m_Set_Label_Content();
}

void Widget::m_Set_Start()
{
    if (m_score_num > m_record_num)
    {
        m_record_num = m_score_num;
        QFile l_file("Config.txt");
        if (l_file.open(QIODevice::ReadWrite))
        {
            QTextStream l_stream(&l_file);
            m_record_num = l_stream.readLine().toInt();
            l_file.close();
        }
    }
    m_score_num = 0;
    m_spd_num = 0;
    m_time_num = 0;
    if (!m_timer.isActive())
        m_timer.start(1000);
}

void Widget::m_Set_Timer()
{
    m_time_num += 1;
    m_Set_Label_Content();
}

void Widget::m_Set_Over()
{
    if (m_score_num > m_record_num)
    {
        m_record_num = m_score_num;
        QFile l_file("Config.txt");
        if (l_file.open(QIODevice::ReadWrite))
        {
            l_file.resize(0);
            QTextStream l_stream(&l_file);
            l_stream<<m_record_num;
            l_file.close();
            m_Set_Label_Content();
        }
    }
    if (m_timer.isActive())
        m_timer.stop();
}
