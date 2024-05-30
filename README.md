### Description:

The task is to write an application to demonstrate the following rasterization algorithms: step-by-step algorithm, DBA algorithm, Bresenham algorithm. Bresenham's algorithm also needs to be implemented for a circle. C ++ and the Qt framework were chosen as the programming language.Also, the QCustomplot library was chosen to plot the graph.

### Code examples:
<br>
Code from main method:
<br>

``` cpp
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
```
<br>

### MainWindow class declaration.

Rasterization functions are declared here to demonstrate how they work. Also objects of graphic elements for creation of design are declared.

``` cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qboxlayout.h"
#include<math.h>
#include <QDebug>
#include <QMainWindow>
#include "QRadioButton"
#include "qlabel.h"
#include "qlineedit.h"
#include "qpushbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void demonstrate_button_clicked();
    void dba_alghoritm_processing();
    void bresenhame_alghoritm_processing();
    void circle_alghoritm_processing();
    void steps_alghoritm_processing();

private:
    Ui::MainWindow *ui;
    void drawcircle(int xc, int yc, int x, int y, QVector<double>& xs,QVector<double>& ys);
    void DBAAlghoritm(int x1, int x2, int y1, int y2);
    void BresenhamAlghoritm(int x1, int x2, int y1, int y2);
    void BresenhamCircleAlghoritm(int xc, int yc, int r);
    void StepByStepAlghoritm(int x1, int x2, int y1, int y2);
    QVBoxLayout* vlayout;
    QHBoxLayout* hlayout;
    QRadioButton* dda_alghoritm;
    QRadioButton* step_by_step_alghoritm;
    QRadioButton* bresenham_alghoritm;
    QRadioButton* bresenham_circle_alghoritm;
    QGridLayout* grid_layout;
    QVBoxLayout* rad_button_layout;
    QVBoxLayout* v_input_layout;
    QLabel* x1_label;
    QLabel* x2_label;
    QLabel* y1_label;
    QLabel* y2_label;
    const QString x_name = "X";
    const QString y_name = "Y";
    QHBoxLayout* x1_h_layout;
    QHBoxLayout* x2_h_layout;
    QHBoxLayout* y1_h_layout;
    QHBoxLayout* y2_h_layout;
    QLineEdit* line_x1;
    QLineEdit* line_x2;
    QLineEdit* line_y1;
    QLineEdit* line_y2;
    QPushButton* demonstrate_button;
};
#endif // MAINWINDOW_H

```

### MainWindow class implementation

<br>
Below is an example of the implementation of the main window class constructor, where graphic elements are created and the design for the application is formed. Events and corresponding handler functions are also connected
<br>

``` cpp
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plot->setInteraction(QCP::iRangeZoom, true);

    ui->plot->xAxis->setLabel(this->x_name);
    ui->plot->yAxis->setLabel(this->y_name);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    hlayout = new QHBoxLayout();
    vlayout = new QVBoxLayout();
    dda_alghoritm = new QRadioButton("DDA alghoritm");
    bresenham_alghoritm = new QRadioButton("Bresenham alghoritm");
    step_by_step_alghoritm = new QRadioButton("Step by step alghoritm");
    bresenham_circle_alghoritm = new QRadioButton("Circle alghoritm");
    vlayout->addWidget(ui->plot);
    grid_layout = new QGridLayout();
    rad_button_layout = new QVBoxLayout();

    x1_label = new QLabel("input x1: ");
    x2_label = new QLabel("input x2: ");
    y1_label = new QLabel("input y1: ");
    y2_label = new QLabel("input y2: ");
    x1_label->setVisible(false);
    x2_label->setVisible(false);
    y1_label->setVisible(false);
    y2_label->setVisible(false);

    line_x1 = new QLineEdit();
    line_x2 = new QLineEdit();
    line_y1 = new QLineEdit();
    line_y2 = new QLineEdit();
    line_x1->setVisible(false);
    line_x2->setVisible(false);
    line_y1->setVisible(false);
    line_y2->setVisible(false);
    v_input_layout = new QVBoxLayout();

    x1_h_layout = new QHBoxLayout();
    x2_h_layout = new QHBoxLayout();
    y1_h_layout = new QHBoxLayout();
    y2_h_layout = new QHBoxLayout();

    x1_h_layout->addWidget(x1_label);
    x1_h_layout->addWidget(line_x1);
    x2_h_layout->addWidget(x2_label);
    x2_h_layout->addWidget(line_x2);
    y1_h_layout->addWidget(y1_label);
    y1_h_layout->addWidget(line_y1);
    y2_h_layout->addWidget(y2_label);
    y2_h_layout->addWidget(line_y2);

    v_input_layout->addLayout(x1_h_layout);
    v_input_layout->addLayout(x2_h_layout);
    v_input_layout->addLayout(y1_h_layout);
    v_input_layout->addLayout(y2_h_layout);


    rad_button_layout->addWidget(dda_alghoritm);
    rad_button_layout->addWidget(bresenham_alghoritm);
    rad_button_layout->addWidget(bresenham_circle_alghoritm);
    rad_button_layout->addWidget(step_by_step_alghoritm);
    grid_layout->setHorizontalSpacing(25);
    grid_layout->addLayout(rad_button_layout, 0, 0, Qt::AlignCenter);
    grid_layout->addLayout(v_input_layout, 0, 1, Qt::AlignCenter);
    demonstrate_button = new QPushButton("Demonstrate");
    demonstrate_button->setFixedSize(120, 70);
    grid_layout->addWidget(demonstrate_button, 1, 0, 1, 2, Qt::AlignHCenter);
    vlayout->addLayout(grid_layout);
    QWidget *widget = new QWidget();
    widget->setLayout(vlayout);
    this->setCentralWidget(widget);
    connect(this->demonstrate_button, SIGNAL(clicked()),SLOT(demonstrate_button_clicked()));
    connect(this->dda_alghoritm, SIGNAL(toggled(bool)), SLOT(dba_alghoritm_processing()));
    connect(this->step_by_step_alghoritm, SIGNAL(toggled(bool)), SLOT(steps_alghoritm_processing()));
    connect(this->bresenham_alghoritm, SIGNAL(toggled(bool)), SLOT(bresenhame_alghoritm_processing()));
    connect(this->bresenham_circle_alghoritm, SIGNAL(toggled(bool)), SLOT(circle_alghoritm_processing()));
    this->demonstrate_button->setVisible(false);

}
```
<br>
Example of implementation for producing DBA rasterization algorithm:
<br>

``` cpp
void MainWindow::DBAAlghoritm(int x1, int x2, int y1, int y2){
    ui->plot->clearGraphs();
    int length = std::max(std::abs(x2 - x1), std::abs(y2 - y1));
    QVector<double> xs, ys;
    double dx = (x2 - x1) / length;
    double dy = (y2 - y1) / length;
    double x = x1 + 0.5 * std::signbit(dx);
    double y = y1 + 0.5 * std::signbit(dy);
    xs.append(x);
    ys.append(y);
    for (int i = 1; i < length; i++){
        x += dx;
        y += dy;
        xs.append(x);
        ys.append(y);
    }
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(xs, ys);
    ui->plot->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

}
```
<br>
Example of implementation for producing Bresenham circle rasterization algorithm:
<br>

``` cpp
void MainWindow::BresenhamCircleAlghoritm(int xc, int yc, int r){
    ui->plot->clearGraphs();
    int x = 0, y = r, d = 3 - 2 * r;
    QVector<double> xs, ys;
    drawcircle(xc, yc, x, y , xs, ys);
    while (y >= x){
        x++;
        if (d > 0){
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else{
            d = d + 4 * x + 6;
        }
        drawcircle(xc, yc, x, y , xs, ys);
    }
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(xs, ys);
    ui->plot->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
}
```
<br>
Example of implementation for producing Bresenham rasterization algorithm:
<br>

``` cpp
void MainWindow::BresenhamAlghoritm(int x1, int y1, int x2, int y2){
    ui->plot->clearGraphs();
    QVector<double> xs, ys;
    int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new - (x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++) {
            xs.push_back(x);
            ys.push_back(y);
            slope_error_new += m_new;
            if (slope_error_new >= 0) {
                y++;
                slope_error_new -= 2 * (x2 - x1);
            }
        }
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(xs, ys);
    ui->plot->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
}
```
<br>
Example of implementation for producing Step by step rasterization algorithm
<br>

``` cpp
void MainWindow::StepByStepAlghoritm(int x1, int x2, int y1, int y2){
    ui->plot->clearGraphs();
    QVector<double> xs, ys;
    double k = (double)(y2 - y1) / (double)(x2 - x1);
    double b = y1 - k * x1;
    int y;
    for (int x = x1; x <= x2; x++){
        y = (int)(k * x + b);
        xs.append(x);
        ys.append(y);
    }
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(xs, ys);
    ui->plot->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
}
```
<br>
<br>
The result is the following application:

![](https://raw.githubusercontent.com/NikitaBeliayev/BSU-Computer-Graphic-Programming/development/Rasterization%20algorithms/.media/Screenshot%202023-06-16%20104611.png)
![](https://raw.githubusercontent.com/NikitaBeliayev/BSU-Computer-Graphic-Programming/development/Rasterization%20algorithms/.media/Screenshot%202023-06-16%20104623.png)
![](https://raw.githubusercontent.com/NikitaBeliayev/BSU-Computer-Graphic-Programming/development/Rasterization%20algorithms/.media/Screenshot%202023-06-16%20104515.png)
