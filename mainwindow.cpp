#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::Windows.append(ui->Page_1);
    MainWindow::Windows.append(ui->Page_2);
//    MainWindow::Windows.append(ui->Page_3);
//    MainWindow::Windows.append(ui->Page_1);
//    MainWindow::Windows.append(ui->Page_1);
//    MainWindow::Windows.append(ui->Page_1);
//    MainWindow::Windows.append(ui->Page_1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_RatingSlider_valueChanged(int value)
{
    QPixmap newPixmap;
    if (value < 19) {
        newPixmap = QPixmap(":/icons/src/icons/emoji_angry.png");
    } else if (value < 39) {
        newPixmap = QPixmap(":/icons/src/icons/emoji_sad.png");
    } else if (value < 59) {
        newPixmap = QPixmap(":/icons/src/icons/emoji_neutral.png");
    } else if (value < 79) {
        newPixmap = QPixmap(":/icons/src/icons/emoji_slightly_smile.png");
    } else {
        newPixmap = QPixmap(":/icons/src/icons/emoji_smile.png");
    }

    ui->RatingLabel->setPixmap(newPixmap);
}


void MainWindow::on_ButtonClose_clicked()
{
    this->close();
}


void MainWindow::on_ButtonNext_clicked()
{
    if (MainWindow::CurrentStage + 2 == MainWindow::Windows.size()) {
        ui->ButtonNext->setText("Отправить");
    }
    if (MainWindow::CurrentStage + 1 == MainWindow::Windows.size()) {
        this->close();
    }
    MainWindow::Windows[CurrentStage]->setVisible(false);
    MainWindow::CurrentStage++;
    ui->progressBar->setValue((int)(100*(MainWindow::CurrentStage+1)/MainWindow::Windows.size()));
    MainWindow::Windows[CurrentStage]->setVisible(true);
}

