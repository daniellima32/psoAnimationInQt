#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include "coordinatesmanip.h" //to get CoordinatesManip::getArrowPoints()

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "mainwindow.h"
#include "solution.h"

#include <iostream>

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
        s = Solution(position, velocity, 1, 1, 1, size);
        vectorOfSolutions.push_back(s);
    }
}

void MainWindow::pso(int iterations)
{
    int GBestID = 0;
    int fitnessGBest = 0;

    for (auto index = 0; index < iterations;++index)
    {
        //Calcula GBest
        GBestID = 0;
        fitnessGBest = vectorOfSolutions[0].getFitnessOfPBest();

        for (auto index2 =1; index2 < vectorOfSolutions.size(); ++index2)
        {
            if (vectorOfSolutions[index2].getFitnessOfPBest() > fitnessGBest)
            {
                GBestID = index2;
                fitnessGBest = vectorOfSolutions[index2].getFitnessOfPBest();
            }
        }

        auto gBest = vectorOfSolutions[GBestID].getPBest();
        //Indica para os nós atualizarem as suas velocidades e posições
        for (auto index2 = 0; index2 < vectorOfSolutions.size(); ++index2)
        {
            vectorOfSolutions[index2].updateVelocityAndPosition(gBest);
        }

        //atualiza gui
        this->refreshPixmap();

        std::cout << "Iteration: " << index << std::endl;
        std::cout.flush();
        //wasteTime();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    pso(1);
}

void MainWindow::wasteTime()
{
    for (int i=0;i<99999;i++)
    {
        for (int j=0;j<9999;j++)
        {}
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

