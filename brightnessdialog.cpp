#include "brightnessdialog.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QFile>
#include <QTextStream>

BrightnessDialog::BrightnessDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Brightness Control");

    QFile maxFile("/sys/class/backlight/backlight/max_brightness");
    if (maxFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&maxFile);
        in >> maxBrightness;
        maxFile.close();
    } else {
        maxBrightness = 100;
    }

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, maxBrightness);
    label = new QLabel("Brightness");

    QPushButton *btnApply = new QPushButton("Apply");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(slider);
    layout->addWidget(btnApply);

    slider->setValue(readBrightness());
    label->setText(QString("Brightness: %1").arg(slider->value()));

    connect(slider, &QSlider::valueChanged, this, [=](int value){
        label->setText(QString("Brightness: %1").arg(value));
    });

    connect(btnApply, &QPushButton::clicked, this, &BrightnessDialog::applyBrightness);
}

int BrightnessDialog::readBrightness()
{
    QFile file("/sys/class/backlight/backlight/brightness");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        int value;
        in >> value;
        file.close();
        return value;
    }
    return 50;
}

void BrightnessDialog::applyBrightness()
{
    QFile file("/sys/class/backlight/backlight/brightness");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << slider->value();
        file.close();
    }
    accept(); // Dialog'u kapatır (exec() çağrısını sonlandırır)
}

