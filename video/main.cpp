#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSql>
#include <QStringList>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QStringList drivers = QSqlDatabase::drivers();
   // qDebug()<<drivers;
    //QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
      // db.setHostName("localhost");
      // db.setDatabaseName("mysql");
      // db.setUserName("root");
     //  db.setPassword("hua!hua123/456");
       //db.open();
     //  QSqlQuery query;
     //  query=QSqlQuery::QSqlQuery(db);
     //  if(db.open())
      // {
      //    QSqlQuery query;
       // query.exec("select * from criminal");
      //    while(query.next())
      //   {
      //         int id = query.value(0).toInt();
      //         QString str = query.value(1).toString();
      //         qDebug() << id << "|" << str;
        //   }
      //     db.close();
     //  }
     // else
     // {
     //     qDebug() << "opened success";
     //  }

    MainWindow w;
    w.show();

    return a.exec();
}
