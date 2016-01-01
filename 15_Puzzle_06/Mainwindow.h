#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QGridLayout>
#include<QObject>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_Game_triggered();
    void on_shuffle_button_clicked();
    void on_solve_button_clicked();

private:
    Ui::MainWindow *ui;
    QGridLayout *gridLayout;
    QWidget *widget;

};

#endif // MAINWINDOW_H
