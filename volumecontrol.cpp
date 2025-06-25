#include "volumecontrol.h"
#include <QVBoxLayout>
#include <QSlider>
#include <QPushButton>
#include <QProcess>

VolumeControl::VolumeControl(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Ses Kontrol");
    resize(300, 100);

    QVBoxLayout *layout = new QVBoxLayout(this);
    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(50);

    QPushButton *applyBtn = new QPushButton("Uygula");
    connect(applyBtn, &QPushButton::clicked, this, &VolumeControl::applyVolume);

    layout->addWidget(slider);
    layout->addWidget(applyBtn);
}

void VolumeControl::applyVolume()
{
    int value = slider->value();
    QString cmd = QString("amixer sset 'Master' %1%").arg(value);
    QProcess::execute("sh", QStringList() << "-c" << cmd);
    accept(); // popup kapansın
}
