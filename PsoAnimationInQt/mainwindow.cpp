#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include "coordinatesmanip.h" //to get CoordinatesManip::getArrowPoints()

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->refreshPixmap();
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

    QPoint origin (10,10), destiny(200,200);

    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    painter.setPen(Qt::black);

    QLineF line(origin, destiny);
    painter.drawLine(line);

    std::vector<QPointF> vec = CoordinatesManip::getArrowPoints(line);

    if (vec.size() > 0)
        painter.drawConvexPolygon(vec.data(), 3);

    update();
}

