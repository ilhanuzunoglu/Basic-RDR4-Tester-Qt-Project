#include "musicplayer.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QDebug>

MusicPlayer::MusicPlayer(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Müzik Çalar");
    resize(400, 120);

    comboBox = new QComboBox(this);
    comboBox->addItems({
        "Front_Center.wav",
        "Front_Left.wav",
        "Rear_Right.wav",
        "Noise.wav",
        "Rear_Center.wav",
        "Side_Left.wav",
        "Front_Right.wav",
        "Rear_Left.wav",
        "Side_Right.wav"
    });

    playBtn = new QPushButton("Çal", this);
    stopBtn = new QPushButton("Durdur ve Kapat", this);

    connect(playBtn, &QPushButton::clicked, this, &MusicPlayer::playMusic);
    connect(stopBtn, &QPushButton::clicked, this, &MusicPlayer::stopMusic);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(playBtn);
    btnLayout->addWidget(stopBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(comboBox);
    mainLayout->addLayout(btnLayout);

    process = new QProcess(this);
}

MusicPlayer::~MusicPlayer()
{
    if (process->state() == QProcess::Running) {
        process->kill();
        process->waitForFinished();
    }
}

void MusicPlayer::playMusic()
{
    if (process->state() == QProcess::Running) {
        process->kill();
        process->waitForFinished();
    }

    QString selected = comboBox->currentText();
    QString filePath = "/usr/share/sounds/alsa/" + selected;

    process->start("/usr/bin/aplay", QStringList() << filePath);

    if (process->waitForStarted()) {
        qDebug() << "Müzik başlatıldı:" << filePath;
    } else {
        qDebug() << "Müzik başlatılamadı!";
    }
}

void MusicPlayer::stopMusic()
{
    if (process->state() == QProcess::Running) {
        process->kill();
        process->waitForFinished();
        qDebug() << "Müzik durduruldu.";
    }
    accept(); // Pop-up kapanır
}
