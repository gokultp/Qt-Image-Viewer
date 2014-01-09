#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QPixmap>
#include<QString>
#include<QSize>
#include<QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setAttribute(Qt::WA_TranslucentBackground);
        setStyleSheet("background:transparent;");

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog d;
    QString fname=d.getOpenFileName(this,
                                     tr("Open Image"), "~/", tr("Image Files (*.png *.jpg *.bmp)"));
    QPixmap g(fname);
    QImage f();
    QSize s= g.size();



    if(s.height()>1000)
        g=g.scaledToHeight(500,Qt::FastTransformation);
    QSize ws=ui->centralWidget->size();
    int h=ws.height(),w=ws.width();
    s= g.size();

    ui->label->setPixmap(g);
    ui->lineEdit->setText(QString::number(w)+"X"+QString::number(h));
    ui->label->setGeometry(h-g.height(),w-g.width(),0,0);
    ui->label->adjustSize();


    ui->label->setAttribute(Qt::WA_TranslucentBackground);
}



void MainWindow::on_action_triggered()
{
    QFileDialog d;
    QString fname=d.getOpenFileName(this,
                                     tr("Open Image"), "~/", tr("Image Files (*.png *.jpg *.bmp)"));
    QPixmap g(fname);
    QSize s= g.size();

    if(s.height()>1000)
        g=g.scaledToHeight(500,Qt::FastTransformation);
    QSize ws=ui->centralWidget->size();
    int h=ws.height(),w=ws.width();
    s= g.size();

    ui->label->setPixmap(g);
    ui->lineEdit->setText(QString::number(w)+"X"+QString::number(h));
    ui->label->setGeometry(h-g.height(),w-g.width(),0,0);
    ui->label->adjustSize();


    ui->label->setAttribute(Qt::WA_TranslucentBackground);
}

void MainWindow::on_actionQ_triggered()
{
    exit(0);
}
