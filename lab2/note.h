#ifndef NOTE_H
#define NOTE_H
#include<QString>
#include <QMainWindow>
#include<QFile>
#include <QTextStream>
namespace Ui {
class Note;
}

class Note : public QMainWindow
{
    QString Name;
    QString text;
    Q_OBJECT

public:
    void CreateNote(QString name, QString text){
        QString filNote ="D:\\QtProjects\\lab2\\files\\notes\\"+name+".txt";
        QFile file(filNote);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream out(&file);
            out << text;
            file.close();

            QString filNoteNames ="D:\\QtProjects\\lab2\\files\\notesNames.txt";
            QFile fileNames(filNoteNames);
            fileNames.open(QFile::Append | QFile::Text);
            QString text1;
            text1=fileNames.readAll();
             text1=name+" "+text1;
                QTextStream outNames(&fileNames);
                outNames <<text1;
                fileNames.close();

    };
    explicit Note(QWidget *parent = nullptr);
    ~Note();
signals:
    void noteWindow();
private slots:
    void on_ButtonSave_clicked();

private:
    Ui::Note *ui;
};

#endif // NOTE_H
