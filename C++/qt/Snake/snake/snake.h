#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QKeyEvent>

class snake : public QWidget
{
public:
    explicit snake(QWidget *parent = nullptr);

protected: // производные классы получают свободный доступ
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
private:
    QImage dot;
    QImage head;
    QImage apple;

    static const int B_WIDTH = 300;
    static const int B_HEIGHT = 300;
    static const int DOT_SIZE = 10;
    static const int ALL_DOTS = 900; // размеры яблока
    static const int RAND_POS = 29; // случайная позиция яблока
    static const int DELAY = 140; // скорость игры

    int timeID;
    int dots;
    int apple_x;
    int apple_y;
    // содержат координаты (x;y) всех «частей» тела змеи
    int x[ALL_DOTS];
    int y[ALL_DOTS];

    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;

    void loadImages();
    void initGame();
    void locateApple();
    void checkApple();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter &);

};

#endif // SNAKE_H
