#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QDialog>
#include <QProcess>

class QPushButton;

class MusicPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer();

private slots:
    void playMusic();
    void stopMusic();

private:
    QProcess *musicProcess;
};

#endif // MUSICPLAYER_H
