#include "dialog.h"

#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMediaPlayer *player = new QMediaPlayer;
    QVideoWidget *video = new QVideoWidget;

    player->setVideoOutput(video);
    player->setMedia(QUrl::fromLocalFile("F:\\song\\Muskan (Official Video) - Rudhveer - JB&Rmee - Sunny pal - Jasko records - Latest punjabi Songs 2020.mp4"));

    video->setGeometry(100,100,750,450);
    video->show();
    player->play();


    Dialog w;
    w.show();
    return a.exec();
}
