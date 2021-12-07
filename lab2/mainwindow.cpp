#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    
   ui->setupUi(this);
   QStringList lstOfNotes=ShowNotes();
   ui->listWidget->addItems(lstOfNames);
   ui->textBrowser->setVisible(false);
   ui->pushButton->setVisible(false);

   noteWindow=new Note();
   connect(noteWindow, &Note::noteWindow, this, &MainWindow::show);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonNew_clicked()
{

    noteWindow->show();
    this->close();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

delete ui->listWidget->takeItem(ui->listWidget->currentRow());

}


void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    ui->pushButton_2->setVisible(true);
    ui->listWidget->setVisible(true);
    ui->ButtonNew->setVisible(true);
    ui->ButtonAddArch->setVisible(true);
    ui->textBrowser->setVisible(false);
    ui->pushButton->setVisible(false);

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    QStringList lstOfNotes=ShowNotes();
    ui->listWidget->addItems(lstOfNames);
}





void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->listWidget->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->ButtonNew->setVisible(false);
    ui->ButtonAddArch->setVisible(false);
    ui->textBrowser->setVisible(true);
    ui->pushButton->setVisible(true);
    ui->textBrowser->insertPlainText(GetText(item));
}


void MainWindow::on_listWidget_itemPressed(QListWidgetItem *item)
{
    QString name=item->text();
    NoteToArch(name);
delete ui->listWidget->takeItem(ui->listWidget->currentRow());
}

