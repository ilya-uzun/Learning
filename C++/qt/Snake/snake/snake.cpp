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

void snake::checkCollision()
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
