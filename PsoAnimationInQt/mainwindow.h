#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void refreshPixmap();
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H