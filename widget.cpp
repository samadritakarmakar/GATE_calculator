#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QString Calc;
    ui->setupUi(this);
    this->setWindowTitle("Scientific Calculator");
    QDir open;
    qDebug()<<"Current Directory"<<open.currentPath();

    if(open.cd("Calc"))
        setCalc(&Calc, &open, 1);
    else
    {
        qWarning("Cannot Find Directory \"Calc\" in Current Directory. Will look in home Directory");
        open.setCurrent(open.homePath());
        qDebug()<<"Current Directory"<<open.currentPath();
        if(open.cd("Calc"))
            setCalc(&Calc, &open, 1);
        else
        {
            qWarning("Cannot Find Directory \"Calc\" in home directory\nReverting to default website page");
            setCalc(&Calc, &open, 2);
            Calc="https://www.tcsion.com/OnlineAssessment/ScientificCalculator/Calculator.html";
        }
    }
    qDebug()<<Calc;
    ui->webView->load(QUrl(Calc));
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
}

void Widget::setCalc(QString *point_Calc, QDir *point_open, int option)
{
    if (option==1)
    {
        point_open->setCurrent(point_open->currentPath()+point_open->fromNativeSeparators("/Calc"));
        *point_Calc="file:"+point_open->fromNativeSeparators("//")+point_open->fromNativeSeparators("/")+point_open->currentPath()+point_open->fromNativeSeparators("/SCIENTIFIC%20CALCULATOR.html");
        qDebug()<<"Variable Calc= "<<*point_Calc;
    }
    else if(option==2)
        *point_Calc="https://www.tcsion.com/OnlineAssessment/ScientificCalculator/Calculator.html";
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
