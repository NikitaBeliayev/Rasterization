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
