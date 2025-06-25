#ifndef SYSTEMINFOWIDGET_H
#define SYSTEMINFOWIDGET_H

#include <QWidget>

class QLabel;
class QPushButton;

class SystemInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SystemInfoWidget(QWidget *parent = nullptr);

signals:
    void backRequested();

private:
    QString getIPAddress();
    QString getHostname();
    QString getKernel();
    QString getUptime();
};

#endif // SYSTEMINFOWIDGET_H
