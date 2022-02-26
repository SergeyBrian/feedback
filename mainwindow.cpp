#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MainWindow::Windows.append(ui->Page_1);


    for (auto & page : MainWindow::Pages) {
        QLayout * Page = new QVBoxLayout();
        QLabel * Question = new QLabel();

        Page->addWidget(Question);
//        Question->setGeometry(170, 90, 460, 150);
//        Page->setStyleSheet("QLabel {}")
        Question->setText(page);

        Page->setGeometry(QRect(0, 0, 800, 530));

        MainWindow::Windows.append(Page);

    }
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
        QApplication::closeAllWindows();
        return;
    }
    MainWindow::Windows[CurrentStage]->setParent(nullptr);
    MainWindow::CurrentStage++;
    ui->progressBar->setValue((int)(100*(MainWindow::CurrentStage+1)/MainWindow::Windows.size()));
    ui->verticalLayout->addWidget(MainWindow::Windows[CurrentStage]->widget(), Qt::AlignCenter);
}

