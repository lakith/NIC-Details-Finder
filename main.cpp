#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>


QString readTesxtFile(QString path){
    QFile file(path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        return in.readAll();
    }

    return "";
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

       QString css = readTesxtFile(":/new/prefix1/resource/css/css.css");
       if(css.length() > 0){
           a.setStyleSheet(css);
       }


    MainWindow w;
    w.show();

    return a.exec();
}
