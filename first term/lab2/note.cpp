#include "note.h"
#include "ui_note.h"
#include<QString>
#include<QFile>
#include"mainwindow.h"

Note::Note(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Note)
{

    ui->setupUi(this);
}

Note::~Note()
{
    delete ui;
}

void Note::on_ButtonSave_clicked()
{
    QString text;
    QString name;
    text=ui->textEdit->toPlainText();
    name=ui->name->text();
    ui->textEdit->clear();
    ui->name->clear();
    CreateNote(name,text);
    emit noteWindow();
    this->close();
}

