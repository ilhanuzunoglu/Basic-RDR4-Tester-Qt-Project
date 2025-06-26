#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "brightnessdialog.h"
#include "systeminfowidget.h"
#include "volumecontrol.h"
#include "musicplayer.h"

#include <QSlider>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      currentValue(50),
      infoWidget(nullptr)
{
    ui->setupUi(this);

    ui->valueSlider->setRange(0, 100);
    ui->valueSlider->setValue(currentValue);
    ui->valueSlider->setTickPosition(QSlider::TicksBothSides);
    ui->valueSlider->setTickInterval(10);

    ui->statusLabel->setText(QString("Mevcut Değer: %1").arg(currentValue));

    connect(ui->increaseButton, &QPushButton::clicked, this, &MainWindow::on_increaseButton_clicked);
    connect(ui->decreaseButton, &QPushButton::clicked, this, &MainWindow::on_decreaseButton_clicked);
    connect(ui->valueSlider, &QSlider::valueChanged, this, &MainWindow::on_valueSlider_valueChanged);

    connect(ui->brightnessButton, &QPushButton::clicked, this, &MainWindow::on_brightnessButton_clicked);
    connect(ui->infoButton, &QPushButton::clicked, this, &MainWindow::on_infoButton_clicked);
    connect(ui->volumeButton, &QPushButton::clicked, this, &MainWindow::on_volumeButton_clicked);
    connect(ui->musicButton, &QPushButton::clicked, this, &MainWindow::on_musicButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (infoWidget) {
        delete infoWidget;
        infoWidget = nullptr;
    }
}

void MainWindow::on_increaseButton_clicked()
{
    currentValue += 5;
    if (currentValue > 100)
        currentValue = 100;

    ui->valueSlider->setValue(currentValue);
    ui->statusLabel->setText(QString("Mevcut Değer: %1").arg(currentValue));
}

void MainWindow::on_decreaseButton_clicked()
{
    currentValue -= 5;
    if (currentValue < 0)
        currentValue = 0;

    ui->valueSlider->setValue(currentValue);
    ui->statusLabel->setText(QString("Mevcut Değer: %1").arg(currentValue));
}

void MainWindow::on_valueSlider_valueChanged(int value)
{
    currentValue = value;
    ui->statusLabel->setText(QString("Mevcut Değer: %1").arg(currentValue));
}

void MainWindow::on_brightnessButton_clicked()
{
    BrightnessDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_infoButton_clicked()
{
    if (!infoWidget) {
        infoWidget = new SystemInfoWidget();
        connect(infoWidget, &SystemInfoWidget::backRequested, this, [this]() {
            infoWidget->hide();
            this->show();
        });
    }

    this->hide();
    infoWidget->showFullScreen();
}

void MainWindow::on_volumeButton_clicked()
{
    VolumeControl dialog(this);
    dialog.exec();
}

void MainWindow::on_musicButton_clicked()
{
    MusicPlayer player(this);
    player.exec();
}
