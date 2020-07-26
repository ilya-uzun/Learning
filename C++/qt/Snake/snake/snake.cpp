#include "snake.h"
#include <QPainter>
#include <QTime>

snake::snake(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color:black;");
    leftDirection = false;
    rightDirection = true;
    upDirection = false;
    downDirection = false;
    inGame = true;

    resize(B_WIDTH, B_HEIGHT);
    loadImages();
    initGame();
}

void snake::loadImages()
{
    dot.load("dot.png");
    head.load("head.png");
    apple.load("apple.png");
}

void snake::initGame()
{
    dots = 3;

    for (int z = 0; z < dots; z++)
    {
        x[z] = 50 - z * 10;
        y[z] = 50;
    }

    locateApple();

    timeID = startTimer(DELAY);
}

void snake::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    doDrawing();
}

void snake::doDrawing()
{
    QPainter qp(this);

    if(inGame)
    {
        qp.drawImage(apple_x, apple_y, apple);

        for (int z = 0; z < dots; z++)
        {
            if (z == 0){
                qp.drawImage(x[z], y[z], head);
            } else{
                qp.drawImage(x[z], y[z], dot);
            }
        }
    }else {//if(inGame)
        gameOver(qp);
    }
}

void snake::gameOver(QPainter &qp)
{
    QString message = "Game over";
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    qp.setPen(QColor(Qt::white));
    qp.setFont(font);
    int h = height();
    int w = width();

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, message);
}

void snake::checkApple()
{
    if ((x[0] == apple_x) && (y[0] == apple_y))
    {
        dots++;
        locateApple();
    }
}

void snake::move()
{
    for (int z = dots; z > 0; z--) {
        x[z]= x[(z-1)];
        y[z]= y[(z-1)];
    }

    if(leftDirection) x[0] -= DOT_SIZE;

    if(rightDirection) x[0] += DOT_SIZE;

    if(upDirection) y[0] -= DOT_SIZE;

    if(downDirection) y[0] += DOT_SIZE;
}
void snake::checkCollision()
{
    for (int z = dots; z > 0; z--) {
       if ((z > 4) && (x[0] == x[z]) && (y[0] == y[z])) inGame = false;
    }

    if(y[0] >= B_HEIGHT) inGame = false;

    if(y[0] < 0) inGame = false;

    if(x[0] >= B_WIDTH) inGame = false;

    if(x[0] < 0) inGame = false;

    if(! inGame) killTimer(timeID);
}

void snake::locateApple()
{
    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());

    int r = qrand() % RAND_POS;
    apple_x = (r * DOT_SIZE);

    r = qrand() % RAND_POS;
    apple_y = (r * DOT_SIZE);
}

void snake::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    if (inGame)
    {
        checkApple();
        checkCollision();
        move();
    }

    repaint();
}

void snake::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();

    if ((key == Qt::Key_Left) && (!rightDirection))
    {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Right) && (!leftDirection))
    {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Up) && (!downDirection))
    {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Down) && (!upDirection))
    {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    QWidget::keyPressEvent(e);
}
