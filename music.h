#ifndef MUSIC_H
#define MUSIC_H

#include <QDialog>
#include<QMediaPlayer>
#include<QAudioOutput>
#include<QDebug>
#include<timer.h>



namespace Ui {

class music;
}

class music : public QDialog
{
    Q_OBJECT

public:
    explicit music(QWidget *parent = nullptr);
    ~music();



private slots:
    void on_music_startButton_clicked();

    void on_music_stopButton_clicked();
    void on_Pomodoro_backButton_clicked();

    void on_sliderVolume_sliderMoved(int position);

    void on_sliderProgress_sliderMoved(int position);


    void on_durationChanged(qint64 position);
    void on_positionChanged(qint64 position);




    //void on_listWidget_itemPressed(QListWidgetItem *item);







    void on_timerButton_clicked();

private:


    Ui::music *ui;
    QMediaPlayer *player;
    QAudioOutput *audio;
    timer *timerwindow;


};

#endif // MUSIC_H






