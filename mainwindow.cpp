#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QRadioButton>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::Windows.push_back(ui->Page_1);

//    QSlider * slider = new QSlider(Qt::Horizontal);

//    slider->setFixedWidth(200);

//    MainWindow::Actions.push_back(button);


    for (int i = 0; i < MainWindow::Questions.length(); i++) {
        QString question = MainWindow::Questions[i];
        bool bLast = i == Questions.length() - 1;

        QFrame * Page = new QFrame();
        QLayout * Layout = new QVBoxLayout();
        QLabel * Question = new QLabel();
        QWidget * buttons_container = new QWidget();
        QHBoxLayout * buttons = new QHBoxLayout();
        if (!bLast) {
            QRadioButton * button_yes = new QRadioButton("Да");
            QRadioButton * button_no = new QRadioButton("Нет");

            buttons->addWidget(button_yes);
            buttons->addWidget(button_no);

            connect(button_yes, SIGNAL(clicked()), this, SLOT(on_RadioButton_Change()));
            connect(button_no, SIGNAL(clicked()), this, SLOT(on_RadioButton_Change()));
        } else {
            QTextEdit * text_edit = new QTextEdit;
            buttons->addWidget(text_edit);
            text_edit->setPlaceholderText("Ваш отзыв...");
        }

        buttons->setAlignment(Qt::AlignCenter);
        buttons_container->setLayout(buttons);
        Page->setGeometry(QRect(0, 0, 800, 530));


        Question->setText(question);
        Question->setFont(QFont("ubuntu", 16));
        Question->setContentsMargins(0, 0, 0, 100);


        Layout->addWidget(Question);
        Layout->addWidget(buttons_container);
        Layout->setAlignment(Qt::AlignCenter);
        Page->setLayout(Layout);
        MainWindow::Windows.push_back(Page);

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
        ui->progressBar->hide();
    } else {
        ui->ButtonNext->setEnabled(false);
    }
    if (MainWindow::CurrentStage + 1 == MainWindow::Windows.size()) {
        QApplication::closeAllWindows();
        return;
    }
    MainWindow::Windows[CurrentStage]->setParent(nullptr);
    MainWindow::CurrentStage++;
    ui->progressBar->setValue((int)(100*(MainWindow::CurrentStage+1)/MainWindow::Windows.size()));
    ui->verticalLayout->addWidget(MainWindow::Windows[CurrentStage], Qt::AlignCenter);
}


void MainWindow::on_RadioButton_Change() {
    ui->ButtonNext->setEnabled(true);
}


void MainWindow::on_ButtonSkip_clicked()
{
   this->close();
}

