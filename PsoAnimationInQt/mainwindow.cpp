#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include "coordinatesmanip.h" //to get CoordinatesManip::getArrowPoints()

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "solution.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buildInitialSolutions();

    this->refreshPixmap();
}

void MainWindow::buildInitialSolutions()
{
    /* initialize random seed: */
    srand (time(NULL));
    auto size = this->size();
    Solution s;
    QVector2D position;
    QVector2D velocity;

    for (auto index = 0; index < POPULATION_SIZE; ++index)
    {
        position = QVector2D(static_cast<int>(rand() % size.width()), static_cast<int>(rand() % size.height()));
        velocity = QVector2D(static_cast<int>(rand() % size.width()), static_cast<int>(rand() % size.height()));
        s = Solution(position, velocity);
        vectorOfSolutions.push_back(s);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(event->rect(), this->pixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshPixmap()
{
    pixmap = QPixmap(size());
    pixmap.fill(Qt::white);

    QPainter painter(&pixmap);
    painter.initFrom(this);

    painter.setFont(QFont("times", 12));

    /*QPoint origin (10,10), destiny(200,200);

    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    painter.setPen(Qt::black);

    QLineF line(origin, destiny);
    painter.drawLine(line);

    std::vector<QPointF> vec = CoordinatesManip::getArrowPoints(line);

    if (vec.size() > 0)
        painter.drawConvexPolygon(vec.data(), 3);*/

    for (auto solution: vectorOfSolutions)
    {
        QLineF line(convertVector2dtoqpointf(solution.getPosition()), convertVector2dtoqpointf(solution.getVelocity()));
        painter.drawLine(line);

        std::vector<QPointF> vec = CoordinatesManip::getArrowPoints(line);

        if (vec.size() > 0)
            painter.drawConvexPolygon(vec.data(), 3);
    }

    update();
}

QPointF MainWindow::convertVector2dtoqpointf(QVector2D vector)
{
    return QPointF{vector.x(), vector.y()};
}

