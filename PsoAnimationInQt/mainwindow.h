#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "utils.h"

#define POPULATION_SIZE 5

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
    QPointF convertVector2dtoqpointf(QVector2D vector);
private:
    Ui::MainWindow *ui;
    QPixmap pixmap;

    VectorOfSolutions vectorOfSolutions;
    void buildInitialSolutions();
};

#endif // MAINWINDOW_H
