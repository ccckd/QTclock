#include "clock.h"
#include "ui_clock.h"

Clock::Clock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clock)
{
    ui->setupUi(this);
    this->setFixedWidth(428);
    this->setFixedHeight(233);
    backGround.load(":/Ast/电子钟背景.png");
    seg.load(":/Ast/间隔.png");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

}

QString Clock::findPng(QChar c)
{
    qDebug() << tr(":/Ast/%1.png").arg(c);
    return tr(":/Ast/%1.png").arg(c);
}

Clock::~Clock()
{
    delete timer;
    delete ui;
}

void Clock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    hh.load(findPng(text[0]));
    hl.load(findPng(text[1]));
    mh.load(findPng(text[3]));
    ml.load(findPng(text[4]));
    sh.load(findPng(text[6]));
    sl.load(findPng(text[7]));
    this->update();


}

void Clock::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QRect s(0, 0,  backGround.width(), backGround.height());
    QRect t(0, 0, this->width(), this->height());
    p.drawPixmap(t, backGround, s);

    QRect s1(0, 0,  hh.width(), hh.height());
    QRect t1(33, 33, hh.width(), hh.height());
    p.drawPixmap(t1, hh, s1);

    QRect s2(0, 0,  hl.width(), hl.height());
    QRect t2(71, 33, hl.width(), hl.height());
    p.drawPixmap(t2, hl, s2);

    QRect s3(0, 0,  mh.width(), mh.height());
    QRect t3(175, 33, mh.width(), mh.height());
    p.drawPixmap(t3, mh, s3);

    QRect s4(0, 0,  ml.width(), ml.height());
    QRect t4(213, 33, ml.width(), ml.height());
    p.drawPixmap(t4, ml, s4);

    QRect s5(0, 0,  sh.width(), sh.height());
    QRect t5(319, 33, sh.width(), sh.height());
    p.drawPixmap(t5, sh, s5);

    QRect s6(0, 0,  sl.width(), sl.height());
    QRect t6(358, 33, sl.width(), sl.height());
    p.drawPixmap(t6, sl, s6);

    QRect s7(0, 0,  seg.width(), seg.height());
    QRect t7(111, 33, seg.width(), seg.height());
    p.drawPixmap(t7, seg, s7);

    QRect s8(0, 0,  seg.width(), seg.height());
    QRect t8(254, 33, seg.width(), seg.height());
    p.drawPixmap(t8, seg, s8);


}
