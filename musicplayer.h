#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QDialog>
#include <QProcess>

class QComboBox;
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
    QComboBox *comboBox;
    QPushButton *playBtn;
    QPushButton *stopBtn;
    QProcess *process;
};

#endif // MUSICPLAYER_H
