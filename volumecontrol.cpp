#include "volumecontrol.h"
#include <QVBoxLayout>
#include <QSlider>
#include <QPushButton>
#include <QProcess>
#include <QDebug>
#include <QRegularExpression>

VolumeControl::VolumeControl(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Ses Kontrol");
    resize(300, 100);

    QVBoxLayout *layout = new QVBoxLayout(this);
    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);

    // Sistemden mevcut sesi oku
    QProcess process;
    process.start("amixer sget Headphone");
    process.waitForFinished();
    QString output = process.readAllStandardOutput();

    QRegularExpression re(R"(\[([0-9]+)%\])");
    QRegularExpressionMatch match = re.match(output);
    int currentVolume = 50;
    if (match.hasMatch()) {
        currentVolume = match.captured(1).toInt();
    }

    slider->setValue(currentVolume);

    QPushButton *applyBtn = new QPushButton("Uygula");
    connect(applyBtn, &QPushButton::clicked, this, &VolumeControl::applyVolume);

    layout->addWidget(slider);
    layout->addWidget(applyBtn);
}

void VolumeControl::applyVolume()
{
    int percent = slider->value();

    // Ses seviyesi ayarla ve sesi aç
    QString cmd = QString("amixer sset Headphone %1% unmute").arg(percent);
    QProcess::execute("sh", QStringList() << "-c" << cmd);

    qDebug() << "Sistem sesi güncellendi:" << percent << "%";
    accept(); // popup kapansın
}
