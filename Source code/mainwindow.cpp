#include "mainwindow.h"
#include "ui_mainwindow.h"

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dba_alghoritm_processing(){

    const QString x = "input x1: ";
    const QString y = "input x2: ";
    const QString r = "input y1: ";
    this->x1_label->setText(x);
    this->x2_label->setText(y);
    this->y1_label->setText(r);
    this->line_y2->setVisible(true);
    this->y2_label->setVisible(true);
    this->line_x1->setVisible(true);
    this->line_x2->setVisible(true);
    this->line_y1->setVisible(true);
    this->y1_label->setVisible(true);
    this->x1_label->setVisible(true);
    this->x2_label->setVisible(true);
    this->line_x1->clear();
    this->line_x2->clear();
    this->line_y1->clear();
    this->line_y2->clear();
    this->demonstrate_button->setVisible(true);
}

void MainWindow::steps_alghoritm_processing(){

    const QString x = "input x1: ";
    const QString y = "input x2: ";
    const QString r = "input y1: ";
    this->x1_label->setText(x);
    this->x2_label->setText(y);
    this->y1_label->setText(r);
    this->line_y2->setVisible(true);
    this->y2_label->setVisible(true);
    this->line_x1->setVisible(true);
    this->line_x2->setVisible(true);
    this->line_y1->setVisible(true);
    this->y1_label->setVisible(true);
    this->x1_label->setVisible(true);
    this->x2_label->setVisible(true);
    this->line_x1->clear();
    this->line_x2->clear();
    this->line_y1->clear();
    this->line_y2->clear();
    this->demonstrate_button->setVisible(true);
}

void MainWindow::bresenhame_alghoritm_processing(){

    const QString x = "input x1: ";
    const QString y = "input x2: ";
    const QString r = "input y1: ";
    this->x1_label->setText(x);
    this->x2_label->setText(y);
    this->y1_label->setText(r);
    this->line_y2->setVisible(true);
    this->y2_label->setVisible(true);
    this->line_x1->setVisible(true);
    this->line_x2->setVisible(true);
    this->line_y1->setVisible(true);
    this->y1_label->setVisible(true);
    this->x1_label->setVisible(true);
    this->x2_label->setVisible(true);
    this->line_x1->clear();
    this->line_x2->clear();
    this->line_y1->clear();
    this->line_y2->clear();
    this->demonstrate_button->setVisible(true);
}

void MainWindow::circle_alghoritm_processing(){
    this->line_x1->clear();
    this->line_x2->clear();
    this->line_y1->clear();
    this->line_y2->clear();
    const QString x = "X:";
    const QString y = "Y:";
    const QString r = "R:";
    this->x1_label->setText(x);
    this->x2_label->setText(y);
    this->y1_label->setText(r);
    this->line_y2->setVisible(false);
    this->y2_label->setVisible(false);
    this->line_x1->setVisible(true);
    this->line_x2->setVisible(true);
    this->line_y1->setVisible(true);
    this->y1_label->setVisible(true);
    this->x1_label->setVisible(true);
    this->x2_label->setVisible(true);
    this->demonstrate_button->setVisible(true);
}

void MainWindow::demonstrate_button_clicked(){

    bool check1,check2, check3, check4 ;
    int num1 = this->line_x1->text().toInt(&check1);
    int num2 = this->line_x2->text().toInt(&check2);
    int num3 = this->line_y1->text().toInt(&check3);

    if (bresenham_circle_alghoritm->isChecked()){
        if(check1 && check2 && check3){
            BresenhamCircleAlghoritm(num1, num2, num3);
        }
    }
    else{
        int num4 = this->line_y2->text().toInt(&check4);
        if (check1 && check2 && check3 && check4){
            if (bresenham_alghoritm->isChecked()){
                BresenhamAlghoritm(num1, num3, num2, num4);
            }
            else if (step_by_step_alghoritm->isChecked()){
                StepByStepAlghoritm((int)num1, (int)num2, (int)num3, (int)num4);
            }
            else if (dda_alghoritm->isChecked()){
                DBAAlghoritm(num1, num2, num3, num4);
            }
        }
    }
}

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

void MainWindow::drawcircle(int xc, int yc, int x, int y, QVector<double>& xs,QVector<double>& ys){
    xs.append(xc + x); ys.append(yc + y);
    xs.append(xc - x); ys.append(yc + y);
    xs.append(xc + x); ys.append(yc - y);
    xs.append(xc - x); ys.append(yc - y);
    xs.append(xc + y); ys.append(yc + x);
    xs.append(xc - y); ys.append(yc + x);
    xs.append(xc + y); ys.append(yc - x);
    xs.append(xc - y); ys.append(yc - x);
}

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
