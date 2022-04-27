#ifndef NOTE_H
#define NOTE_H

#include <QMainWindow>
#include <QObject>
#include<QString>
#include <QMediaPlayer>
#include <QAudioOutput>

class Note
{
public:
QString note;
QString octave;
QString intstrument;
private:
QMediaPlayer* player = new QMediaPlayer;
QAudioOutput* Output = new QAudioOutput;
public:
void playN(){
    player->setAudioOutput(Output);
    player->setSource(QUrl::fromLocalFile("D:/QtProjects/PianoDemo/Sounds/"+intstrument+"/"+octave+"/"+note+".mp3"));
    Output->setVolume(70);
    player->setLoops(QMediaPlayer::Infinite);
    player->play();
}
void stopN(){
    player->stop();
}

public:

    Note();
};

#endif // NOTE_H
