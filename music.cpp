#include "music.h"
#include "ui_music.h"
#include<QHBoxLayout>

music::music(QWidget *parent) :
   QDialog(parent),
    ui(new Ui::music)
{
    ui->setupUi(this);
    this->setWindowTitle("Music");


    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    player->setAudioOutput(audio);

    playButton = new QToolButton(this);
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    connect(playButton, &QAbstractButton::clicked, this, &music::on_startButton_clicked);

    stopButton = new QToolButton(this);
    stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    stopButton->setEnabled(false);

    connect(stopButton, &QAbstractButton::clicked, this, &music::stop);

    nextButton = new QToolButton(this);
    nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));

    connect(nextButton, &QAbstractButton::clicked, this, &music::next);

    previousButton = new QToolButton(this);
    previousButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    //previousButton ->setIcon(style()->standardIcon(Qstyle::PM_ButtonIconsize());

    connect(previousButton, &QAbstractButton::clicked, this, &music::previous);

   // muteButton = new QToolButton(this);
   // muteButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

   // connect(muteButton, &QAbstractButton::clicked, this, &music::muteClicked);

    sliderVolume = new QSlider(Qt::Horizontal, this);
    sliderVolume->setRange(0, 100);

    connect(sliderVolume, &QSlider::valueChanged, this, &music::on_sliderVolume_valueChanged);

    QBoxLayout *layout = new QHBoxLayout;
    layout->setContentsMargins(300, 300, 300, 300);
      layout->addWidget(stopButton);
      layout->addWidget(previousButton);
      layout->addWidget(playButton);
      layout->addWidget(nextButton);
      //nextButton->setFixedSize(50,50);
      //previousButton->setFixedSize(50,50);
     // layout->addWidget(m_muteButton);
      layout->addWidget(sliderVolume);
//   layout->addWidget(m_rateBox);
       setLayout(layout);

    //  connect (player, &QMediaPlayer::positionChanged, this, &music:: on_positionChanged);
     // connect (player, &QMediaPlayer::durationChanged, this, &music:: on_durationChanged);
      //connect (audio , &QSlider:: valueChanged,this, &music:: on_sliderVolume_valueChanged);

};
music::~music()
{

    delete ui;
}




void music::on_startButton_clicked() // for music
{
    // load and play the file


        player->setSource(QUrl::fromLocalFile("qrc:/studymusic/songs/s1.mp3"));

        player->play();
        qDebug()<< player->errorString();
}



void music::on_stopButton_clicked() // for music
{
    player->stop();

}
void music::on_Pomodoro_backButton_clicked()
{
    this->hide();
    QWidget * parent  = this->parentWidget();
    parent->show();
}

//void music:: on_positionChanged(qint64 position)
//{
//    ui->sliderProgress->setValue(position);
//}
//void music:: on_durationChanged(qint64 position)
//{
//    ui->sliderProgress->setMaximum(position);
//}
void music::on_sliderVolume_valueChanged(int duration)
{

        qreal linearVolume = QAudio::convertVolume(duration/ qreal(100.0),
                                                   QAudio::LogarithmicVolumeScale,
                                                   QAudio::LinearVolumeScale);

        audio->setVolume(qRound(linearVolume * 100));

}

float music::volume() const
{
    qreal linearVolume =  QAudio::convertVolume(sliderVolume->value() / qreal(100),
                                                QAudio::LogarithmicVolumeScale,
                                                QAudio::LinearVolumeScale);

    return linearVolume;
}

//float music::volume() const
//{
//    qreal linearVolume =  QAudio::convertVolume(audio-> / qreal(100),
//                                                QAudio::LogarithmicVolumeScale,
//                                                QAudio::LinearVolumeScale);

//    return linearVolume;
//}

//float PlayerControls::volume() const
//{
//    qreal linearVolume =  QAudio::convertVolume(m_volumeSlider->value() / qreal(100),
//                                                QAudio::LogarithmicVolumeScale,
//                                                QAudio::LinearVolumeScale);

//    return linearVolume;
//}

//void PlayerControls::setVolume(float volume)
//{
//    qreal logarithmicVolume = QAudio::convertVolume(volume,
//                                                    QAudio::LinearVolumeScale,
//                                                    QAudio::LogarithmicVolumeScale);

//    m_volumeSlider->setValue(qRound(logarithmicVolume * 100));
//}
//void music::on_sliderProgress_sliderMoved(int position)
//{
//    player->setPosition(position);
//}







void music::on_timerButton_clicked()
{
    hide();
    timerwindow  = new timer(this);
    timerwindow->show();
}




