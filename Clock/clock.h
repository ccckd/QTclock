#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QPixmap>
#include <QTime>
#include <QTimer>
#include <QDebug>

namespace Ui {
class Clock;
}

class Clock : public QWidget
{
    Q_OBJECT

public:
    explicit Clock(QWidget *parent = 0);
    QString findPng(QChar s);
    ~Clock();

public slots:
    void showTime();

protected:
    void paintEvent(QPaintEvent*);

private:
    Ui::Clock *ui;
    QPixmap backGround;
    QPixmap hh;
    QPixmap hl;
    QPixmap mh;
    QPixmap ml;
    QPixmap sh;
    QPixmap sl;
    QPixmap seg;
    QTimer *timer;
};

#endif // CLOCK_H
