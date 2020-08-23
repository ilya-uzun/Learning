#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// https://evileg.com/ru/post/426/ 
// чтение из QLineEdit

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onGetMaximumValuePushButtonClicked();

private:
    Ui:Widget * ui;
};

#endif // WIDGET_H