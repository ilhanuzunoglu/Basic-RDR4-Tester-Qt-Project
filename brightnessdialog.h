#ifndef BRIGHTNESSDIALOG_H
#define BRIGHTNESSDIALOG_H

#include <QDialog>

class QSlider;
class QLabel;

class BrightnessDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BrightnessDialog(QWidget *parent = nullptr);

private slots:
    void applyBrightness();

private:
    QSlider *slider;
    QLabel *label;
    int maxBrightness;
    int readBrightness();
};

#endif // BRIGHTNESSDIALOG_H
