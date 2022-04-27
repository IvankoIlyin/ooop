#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<Note.h>
#include<QString>
Note keyC,keyD,keyE,keyF,keyG,keyA,keyB,keydiezC,keydiezD,keydiezF,keydiezG,keydiezA;
QString octave,instrument;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Cfour->setChecked(1);
    ui->GrandPiano->setChecked(1);
    if(ui->GrandPiano->isChecked()){instrument="GrandPiano";}
    if(ui->Synth->isChecked()){instrument="Synth";}
    if(ui->Guitar->isChecked()){instrument="Guitar";}
    if(ui->Cthree->isChecked()){octave="C3";}
    if(ui->Cfour->isChecked()){octave="C4";}
    if(ui->Cfive->isChecked()){octave="C5";}

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_keyC_pressed()
{
    keyC.intstrument=instrument;
    keyC.octave=octave;
    keyC.note="C";
    keyC.playN();}
void MainWindow::on_keyC_released()
{
    keyC.stopN();
}


void MainWindow::on_keyD_pressed()
{
    keyD.intstrument=instrument;
    keyD.octave=octave;
    keyD.note="D";
    keyD.playN();}
void MainWindow::on_keyD_released()
{
    keyD.stopN();
}


void MainWindow::on_keyE_pressed()
{
    keyE.intstrument=instrument;
    keyE.octave=octave;
    keyE.note="E";
    keyE.playN();}
void MainWindow::on_keyE_released()
{
    keyE.stopN();
}


void MainWindow::on_keyF_pressed()
{
    keyF.intstrument=instrument;
    keyF.octave=octave;
    keyF.note="F";
    keyF.playN();}
void MainWindow::on_keyF_released()
{
    keyF.stopN();
}


void MainWindow::on_keyG_pressed()
{
    keyG.intstrument=instrument;
    keyG.octave=octave;
    keyG.note="G";
    keyG.playN();}
void MainWindow::on_keyG_released()
{
    keyG.stopN();
}


void MainWindow::on_keyA_pressed()
{
    keyA.intstrument=instrument;
    keyA.octave=octave;
    keyA.note="A";
    keyA.playN();}
void MainWindow::on_keyA_released()
{
    keyA.stopN();
}


void MainWindow::on_keyB_pressed()
{
    keyB.intstrument=instrument;
    keyB.octave=octave;
    keyB.note="B";
    keyB.playN();}
void MainWindow::on_keyB_released()
{
    keyB.stopN();
}


void MainWindow::on_keydiezC_pressed()
{
    keydiezC.intstrument=instrument;
    keydiezC.octave=octave;
    keydiezC.note="C#";
    keydiezC.playN();}
void MainWindow::on_keydiezC_released()
{
    keydiezC.stopN();
}


void MainWindow::on_keydiezD_pressed()
{
    keydiezD.intstrument=instrument;
    keydiezD.octave=octave;
    keydiezD.note="D#";
    keydiezD.playN();}
void MainWindow::on_keydiezD_released()
{
    keydiezD.stopN();
}


void MainWindow::on_keydiezF_pressed()
{
    keydiezF.intstrument=instrument;
    keydiezF.octave=octave;
    keydiezF.note="F#";
    keydiezF.playN();}
void MainWindow::on_keydiezF_released()
{
    keydiezF.stopN();
}


void MainWindow::on_keydiezG_pressed()
{
    keydiezG.intstrument=instrument;
    keydiezG.octave=octave;
    keydiezG.note="G#";
    keydiezG.playN();}
void MainWindow::on_keydiezG_released()
{
    keydiezG.stopN();
}


void MainWindow::on_keydiezA_pressed()
{
    keydiezA.intstrument=instrument;
    keydiezA.octave=octave;
    keydiezA.note="A#";
    keydiezA.playN();}
void MainWindow::on_keydiezA_released()
{
    keydiezA.stopN();
}


void MainWindow::on_GrandPiano_clicked()
{
    if(ui->GrandPiano->isChecked()){instrument="GrandPiano"; }
}

void MainWindow::on_Synth_clicked()
{
   if(ui->Synth->isChecked()){instrument="Synth";}
}

void MainWindow::on_Guitar_clicked()
{
 if(ui->Guitar->isChecked()){instrument="Guitar";}
}


void MainWindow::on_Cthree_clicked()
{
    if(ui->Cthree->isChecked()){octave="C3";}
}


void MainWindow::on_Cfour_clicked()
{
  if(ui->Cfour->isChecked()){octave="C4";}
}


void MainWindow::on_Cfive_clicked()
{
   if(ui->Cfive->isChecked()){octave="C5";}
}


void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_3){
        octave="C3";
        ui->Cthree->setChecked(1);
    }

    if(event->key()==Qt::Key_4){
        octave="C4";
        ui->Cfour->setChecked(1);
    }

    if(event->key()==Qt::Key_5){
        octave="C5";
        ui->Cfive->setChecked(1);
    }

    if(event->key()==Qt::Key_A){
        keyC.intstrument=instrument;
        keyC.octave=octave;
        keyC.note="C";
        keyC.playN();
    }

    if(event->key()==Qt::Key_S){
        keyD.intstrument=instrument;
        keyD.octave=octave;
        keyD.note="D";
        keyD.playN();
    }

    if(event->key()==Qt::Key_D){
        keyE.intstrument=instrument;
        keyE.octave=octave;
        keyE.note="E";
        keyE.playN();
    }

    if(event->key()==Qt::Key_F){
    keyF.intstrument=instrument;
    keyF.octave=octave;
    keyF.note="F";
    keyF.playN();
}

    if(event->key()==Qt::Key_G){
    keyG.intstrument=instrument;
    keyG.octave=octave;
    keyG.note="G";
    keyG.playN();
}

    if(event->key()==Qt::Key_H){
    keyA.intstrument=instrument;
    keyA.octave=octave;
    keyA.note="A";
    keyA.playN();
}

    if(event->key()==Qt::Key_J){
    keyB.intstrument=instrument;
    keyB.octave=octave;
    keyB.note="B";
    keyB.playN();
}

    if(event->key()==Qt::Key_W){
        keydiezC.intstrument=instrument;
        keydiezC.octave=octave;
        keydiezC.note="C#";
        keydiezC.playN();
    }

    if(event->key()==Qt::Key_E){
        keydiezD.intstrument=instrument;
        keydiezD.octave=octave;
        keydiezD.note="D#";
        keydiezD.playN();
    }

    if(event->key()==Qt::Key_T){
        keydiezF.intstrument=instrument;
        keydiezF.octave=octave;
        keydiezF.note="F#";
        keydiezF.playN();
    }

    if(event->key()==Qt::Key_Y){
        keydiezG.intstrument=instrument;
        keydiezG.octave=octave;
        keydiezG.note="G#";
        keydiezG.playN();
    }

    if(event->key()==Qt::Key_U){
        keydiezA.intstrument=instrument;
        keydiezA.octave=octave;
        keydiezA.note="A#";
        keydiezA.playN();
    }
}


void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_A){
       keyC.stopN();
    }

    if(event->key()==Qt::Key_S){
        keyD.stopN();
    }

    if(event->key()==Qt::Key_D){
        keyE.stopN();
    }

    if(event->key()==Qt::Key_F){
        keyF.stopN();
    }

    if(event->key()==Qt::Key_G){
        keyG.stopN();
    }

    if(event->key()==Qt::Key_H){
        keyA.stopN();
    }

    if(event->key()==Qt::Key_J){
        keyB.stopN();
    }

    if(event->key()==Qt::Key_W){
        keydiezC.stopN();
    }

    if(event->key()==Qt::Key_E){
        keydiezD.stopN();
    }

    if(event->key()==Qt::Key_T){
        keydiezF.stopN();
    }

    if(event->key()==Qt::Key_Y){
        keydiezG.stopN();
    }

    if(event->key()==Qt::Key_U){
        keydiezA.stopN();
    }

}







