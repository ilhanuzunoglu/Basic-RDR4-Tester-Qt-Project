#include "systeminfowidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QProcess>

SystemInfoWidget::SystemInfoWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *title = new QLabel("Cihaz Bilgileri");
    title->setAlignment(Qt::AlignCenter);
    QFont font = title->font();
    font.setPointSize(20);
    font.setBold(true);
    title->setFont(font);

    QLabel *ipLabel = new QLabel("IP: " + getIPAddress());
    QLabel *hostLabel = new QLabel("Hostname: " + getHostname());
    QLabel *kernelLabel = new QLabel("Kernel: " + getKernel());
    QLabel *uptimeLabel = new QLabel("Uptime: " + getUptime());

    QPushButton *backBtn = new QPushButton("Geri Dön");
    connect(backBtn, &QPushButton::clicked, this, &SystemInfoWidget::backRequested);

    layout->addWidget(title);
    layout->addWidget(ipLabel);
    layout->addWidget(hostLabel);
    layout->addWidget(kernelLabel);
    layout->addWidget(uptimeLabel);
    layout->addStretch();
    layout->addWidget(backBtn);
}

QString SystemInfoWidget::getIPAddress()
{
    QProcess p;
    p.start("sh", QStringList() << "-c" << "ip addr show | grep 'inet ' | grep -v '127.0.0.1' | awk '{print $2}' | cut -d/ -f1 | head -n 1");
    p.waitForFinished();
    return p.readAllStandardOutput().trimmed();
}

QString SystemInfoWidget::getHostname()
{
    QProcess p;
    p.start("hostname");
    p.waitForFinished();
    return p.readAllStandardOutput().trimmed();
}

QString SystemInfoWidget::getKernel()
{
    QProcess p;
    p.start("uname -r");
    p.waitForFinished();
    return p.readAllStandardOutput().trimmed();
}

QString SystemInfoWidget::getUptime()
{
    QProcess p;
    p.start("uptime -p");
    p.waitForFinished();
    return p.readAllStandardOutput().trimmed();
}
