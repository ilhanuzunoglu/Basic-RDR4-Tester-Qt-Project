#include "musicplayer.h"
#include <QVBoxLayout>
#include <QPushButton>

MusicPlayer::MusicPlayer(QWidget *parent) : QDialog(parent), musicProcess(new QProcess(this))
{
    setWindowTitle("Müzik Çalar");
    resize(300, 100);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *playBtn = new QPushButton("Oynat");
    QPushButton *stopBtn = new QPushButton("Durdur");

    connect(playBtn, &QPushButton::clicked, this, &MusicPlayer::playMusic);
    connect(stopBtn, &QPushButton::clicked, this, &MusicPlayer::stopMusic);

    layout->addWidget(playBtn);
    layout->addWidget(stopBtn);
}

MusicPlayer::~MusicPlayer()
{
    stopMusic(); // Uygulama kapanırken sesi durdur
}

void MusicPlayer::playMusic()
{
    stopMusic(); // Önce varsa oynatılanı durdur

    QString filePath = "/usr/share/sounds/alsa/Front_Center.wav"; // sabit dosya
    musicProcess->start("aplay", QStringList() << filePath);
}

void MusicPlayer::stopMusic()
{
    if (musicProcess->state() == QProcess::Running) {
        musicProcess->kill(); // çalmayı durdur
        musicProcess->waitForFinished();
    }
}
