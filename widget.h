#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QDir>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void showTime();
    void on_pushButton_clicked();
    void setCalc(QString *point_Calc, QDir *point_open, int option);
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
