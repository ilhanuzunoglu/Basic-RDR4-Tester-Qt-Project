#ifndef VOLUMECONTROL_H
#define VOLUMECONTROL_H

#include <QDialog>

class QSlider;
class QPushButton;

class VolumeControl : public QDialog
{
    Q_OBJECT

public:
    explicit VolumeControl(QWidget *parent = nullptr);

private slots:
    void applyVolume();

private:
    QSlider *slider;
};

#endif // VOLUMECONTROL_H
