#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<QFrame *> Windows;
    int CurrentStage = 0;


private slots:
    void on_RatingSlider_valueChanged(int value);
    void on_ButtonClose_clicked();
    void on_ButtonNext_clicked();
};
#endif // MAINWINDOW_H
