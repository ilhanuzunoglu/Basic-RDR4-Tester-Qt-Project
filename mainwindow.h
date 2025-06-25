#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "brightnessdialog.h"
#include "systeminfowidget.h"
#include "volumecontrol.h"
#include "musicplayer.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_increaseButton_clicked();
    void on_decreaseButton_clicked();
    void on_valueSlider_valueChanged(int value);
    void on_brightnessButton_clicked();
    void on_infoButton_clicked();
    void on_volumeButton_clicked();
    void on_musicButton_clicked();


private:
    Ui::MainWindow *ui;
    int currentValue;
    SystemInfoWidget *infoWidget;


};

#endif // MAINWINDOW_H
