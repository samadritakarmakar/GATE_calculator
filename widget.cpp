#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QString>
#include <QDir>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Scientific Calculator");
    QDir open;
    if(!open.cd("Calc"))
        qWarning("Cannot Find Diectory \"Calc\"");
    open.setCurrent(open.currentPath()+open.fromNativeSeparators("//Calc"));
    QString Calc="file:"+open.fromNativeSeparators("//")+open.fromNativeSeparators("/")+open.currentPath()+open.fromNativeSeparators("/SCIENTIFIC%20CALCULATOR.html");
    //QString Calc="file:///home/sam/Programs/build-Browser-Unnamed-Release/Calc/SCIENTIFIC%20CALCULATOR.html";
    ui->webView->load(QUrl(Calc));
    //qDebug()<<Calc;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    ui->lcdNumber->display(text);

}

void Widget::on_pushButton_clicked()
{
    this->close();
}
