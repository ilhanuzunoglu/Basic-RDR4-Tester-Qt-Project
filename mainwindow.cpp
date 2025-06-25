#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      currentValue(50)
{
    ui->setupUi(this);

    ui->valueSlider->setRange(0, 100);
    ui->valueSlider->setValue(currentValue);
    ui->valueSlider->setTickPosition(QSlider::TicksBothSides);
    ui->valueSlider->setTickInterval(10);

    ui->statusLabel->setText(QString("Mevcut Değer: %1").arg(currentValue));

    connect(ui->increaseButton, SIGNAL(clicked()), this, SLOT(on_increaseButton_clicked()));
    connect(ui->decreaseButton, SIGNAL(clicked()), this, SLOT(on_decreaseButton_clicked()));
    connect(ui->valueSlider, SIGNAL(valueChanged(int)), this, SLOT(on_valueSlider_valueChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
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
    infoWidget = new SystemInfoWidget();
    connect(infoWidget, &SystemInfoWidget::backRequested, this, [=]() {
        infoWidget->hide();
        this->show();
    });

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
    MusicPlayer dialog(this);
    dialog.exec();
}

