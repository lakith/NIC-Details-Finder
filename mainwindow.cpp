#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString nicNumber = ui->lineEdit->text();
    int dayText = 0;
    QString year;
    QString month;
    QString day;
    QString gender;

    if(nicNumber.length() != 10 && nicNumber.length() != 12){
        qDebug()<< nicNumber.length();
        QMessageBox msgBox;
        msgBox.setText("Invalied NIC NUmber");
        msgBox.exec();
    } else {

        //year
        if(nicNumber.length() == 10){
            year = "19" + nicNumber.mid(0,2);
            QString parse = nicNumber.mid(2,3);
            dayText = parse.toInt();
            qDebug() << year;
        } else {
            year = nicNumber.mid(0,4);
            QString parse = nicNumber.mid(4,3);
            dayText = parse.toInt();
            qDebug() << year;
        }

        //gender
        if(dayText > 500){
            gender = "Female";
            dayText = dayText- 500;
            qDebug() << gender;
        } else {
            gender = "Male";
            qDebug() << gender;
        }

        if(dayText < 1){
            QMessageBox msgBox;
            msgBox.setText("Invalied NIC NUmber");
            msgBox.exec();
        }  else if(dayText > 366){
            QMessageBox msgBox;
            msgBox.setText("Invalied NIC NUmber");
            msgBox.exec();
        }else {
            if(dayText > 335){
                day = QString::number(dayText-335);
                month = "December";
                qDebug() << day;
                qDebug() << month;
            } else if (dayText > 305) {
                day = QString::number(dayText - 305);
                month = "November";
                qDebug() << day;
                qDebug() << month;
            }
            else if (dayText > 274) {
                day = QString::number(dayText - 274);
                month = "October";
                qDebug() << day;
                qDebug() << month;
            }
            else if (dayText > 244) {
                day = QString::number(dayText - 244);
                month = "September";
                qDebug() << day;
                qDebug() << month;
            }
            else if (dayText > 213) {
                day = QString::number(dayText - 213);
                month = "Auguest";
                qDebug() << day;
                qDebug() << month;
            }
            else if (dayText > 182) {
                day = QString::number(dayText - 182);
                month = "July";
                qDebug() << day;
                qDebug() << month;
            }
            else if (dayText > 152) {
                day = QString::number(dayText - 152);
                month = "June";
                qDebug() << day;
                qDebug() << month;
            }
            else if (dayText > 121) {
                day = QString::number(dayText - 121);
                month = "May";
                qDebug() << day;
                qDebug() << month;
            }
            else if (dayText > 91) {
                day = QString::number(dayText - 91);
                month = "April";
                qDebug() << day;
                qDebug() << day;
                qDebug() << month;
            }
            else if (dayText > 60) {
                day = QString::number(dayText - 60);
                month = "March";
                qDebug() << day;
                qDebug() << month;
            }
            else if (dayText < 32) {
                month = "January";
                day = QString::number(dayText);
                qDebug() << day;
                qDebug() << month;
            }
            else if (dayText > 31) {
                day = QString::number(dayText - 31);
                month = "Febuary";
                qDebug() << day;
                qDebug() << month;

            }
        }
        QMessageBox msgBox;
        msgBox.setText("birthday  = "+year+"-"+month+"-"+day+"\n Gender - "+gender);
        msgBox.exec();
    }
}
