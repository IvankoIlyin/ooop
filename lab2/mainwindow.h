#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QFile>
#include <QTextStream>
#include<QString>
#include "note.h"
#include<archive.h>
#include<QVector>
#include<QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    QString names;

    QStringList lstOfNames;
    Q_OBJECT

public:
    QStringList ShowNotes(){
        QString filNoteNames ="D:\\QtProjects\\lab2\\files\\notesNames.txt";
        QFile fileNames(filNoteNames);
        fileNames.open(QFile::ReadOnly | QFile::Text);
        names=fileNames.readAll();
             fileNames.close();
             lstOfNames=names.split(" ");
             return lstOfNames;
    };
    QString GetText(QListWidgetItem *item){
        QString text;
        QString name=item->text();
            QFile file("D:\\QtProjects\\lab2\\files\\notes\\"+name+".txt");
            file.open(QIODevice::ReadOnly| QIODevice::Text);
                QString line = file.readAll();
                text=line;
            file.close();
        return text;
    };



    void NoteToArch(QString nameOfNote){
        QString filNoteNames ="D:\\QtProjects\\lab2\\files\\notesNames.txt";
        QFile fileNames(filNoteNames);
        fileNames.open(QFile::ReadOnly | QFile::Text);
        names=fileNames.readAll();
             fileNames.close();
            QStringList lstOfNames1=names.split(" ");
             QStringList lstOfNames2;
             for(int i=0;i<lstOfNames1.size();i++){
                 if(lstOfNames1[i]!=nameOfNote){lstOfNames2.push_back(lstOfNames1[i]);}
                 else{addNameArch(lstOfNames1[i]);}
             }
             fileNames.open(QFile::WriteOnly | QFile::Text);
             QString text1;
             for(int i=0;i<lstOfNames2.size();i++){
                 text1=fileNames.readAll();
                 text1=lstOfNames2[i]+" "+text1;
             }
             QTextStream outNames(&fileNames);
             outNames <<text1;
                  fileNames.close();




    }
    void addNameArch(QString names){
        QString filArchNames ="D:\\QtProjects\\lab2\\files\\archiveNames.txt";
        QFile fileArchNames(filArchNames);
        fileArchNames.open(QFile::Append | QFile::Text);
        QString text1;
        text1=fileArchNames.readAll();
         text1=names+" "+text1;
            QTextStream outNames(&fileArchNames);
            outNames <<text1;
            fileArchNames.close();

    }


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ButtonNew_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemPressed(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    Note *noteWindow;
    Archive *archiveWindow;


};
#endif // MAINWINDOW_H
