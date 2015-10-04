#include "loadingwindow.h"
#include "mainwindow.h"

LoadingWindow::LoadingWindow(QString text, QApplication* a)
{

    setWindowFlags( Qt::CustomizeWindowHint );
    this->text = text;
    this->setFixedSize(570, 300);
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, this->size(), a->desktop()->availableGeometry()));
    this->setStyleSheet("background-image: url()");

    QLabel *waitingText = new QLabel(this);
    waitingText->setText(text);
    waitingText->setAlignment(Qt::AlignCenter);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(waitingText);
    setLayout(layout);

}

