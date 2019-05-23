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
    void mousePressEvent(QMouseEvent *event);
private:
    Ui::MainWindow *ui;
    QPixmap pixmap;

    VectorOfSolutions vectorOfSolutions;
    void buildInitialSolutions();
    void pso(int iterations);
    void wasteTime();
    QVector2D sum(QVector2D v1, QVector2D v2);
};

#endif // MAINWINDOW_H
