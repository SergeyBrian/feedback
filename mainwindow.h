#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QCheckBox>

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
    QVector<QString> Questions = {"Будете ли вы рекомендовать сервис друзьям?",
                                  "Были ли вы удовлетворены работой наших сотрудников?",
                                  "Наш сервис помог вам решить вашу проблему?",
                                  "Остались ли вы довольны нашей службой доставки?"};
    QVector<QWidget *> Actions;
    int CurrentStage = 0;


private slots:
    void on_RatingSlider_valueChanged(int value);
    void on_ButtonClose_clicked();
    void on_ButtonNext_clicked();
    void on_RadioButton_Change();
};
#endif // MAINWINDOW_H
