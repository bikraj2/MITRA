#ifndef MUSIC_H
#define MUSIC_H

#include <QDialog>
#include<QMediaPlayer>
#include<QAudioOutput>
#include<QDebug>
#include<timer.h>
#include<QAbstractSlider>
#include<QToolButton>
#include<QStyle>
#include<QSlider>


QT_BEGIN_NAMESPACE
class QMediaPlayer;
QT_END_NAMESPACE

namespace Ui
{

class music;

}

class music : public QDialog
{
    Q_OBJECT

public:
    explicit music(QWidget *parent = nullptr);
    ~music();

signals:
    void stop();
    void next();
    void previous();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();
    void on_Pomodoro_backButton_clicked();

    void on_sliderVolume_valueChanged(int duration);

   // void on_sliderProgress_sliderMoved(int position);


    //void on_durationChanged(qint64 position);
    //void on_positionChanged(qint64 position);

    float volume() const;



    //void on_listWidget_itemPressed(QListWidgetItem *item);







    void on_timerButton_clicked();


private:


    Ui::music *ui;
    QMediaPlayer *player;
    QAudioOutput *audio;
    timer *timerwindow;
    QAbstractSlider *sliderVolume = nullptr;
    QAbstractButton *playButton = nullptr;
    QAbstractButton *stopButton = nullptr;
    QAbstractButton *nextButton = nullptr;
    QAbstractButton *previousButton = nullptr;
    QAbstractButton *muteButton = nullptr;




};

#endif // MUSIC_H






