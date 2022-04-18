#include "music.h"
#include "ui_music.h"

music::music(QWidget *parent) :
   QDialog(parent),
    ui(new Ui::music)
{
    ui->setupUi(this);


    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    player->setAudioOutput(audio);

    connect (player, &QMediaPlayer::positionChanged, this, &music:: on_positionChanged);
    connect (player, &QMediaPlayer::durationChanged, this, &music:: on_durationChanged);


}

music::~music()
{
    delete ui;
}




void music::on_music_startButton_clicked() // for music
{
    // load and play the file


        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/studymusic/s4.mp3"));

        player->play();
        qDebug()<< player->errorString();
}



void music::on_music_stopButton_clicked() // for music
{
    player->stop();

}
void music::on_Pomodoro_backButton_clicked()
{
    this->hide();
    QWidget * parent  = this->parentWidget();
    parent->show();
}

void music:: on_positionChanged(qint64 position)
{
    ui->sliderProgress->setValue(position);
}
void music:: on_durationChanged(qint64 position)
{
    ui->sliderProgress->setMaximum(position);
}
void music::on_sliderVolume_sliderMoved(int position)
{
    audio->setVolume(position);

}

void music::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
}







void music::on_timerButton_clicked()
{
    hide();
    timerwindow  = new timer(this);
    timerwindow->show();
}

