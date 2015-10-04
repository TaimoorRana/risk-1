#include "mainwindow.h"
#include "gui/form.h"
#include "ui_mainwindow.h"
#include "gui/cardbox.h"
#include <QApplication>
#include <QObject>
#include "gui/joinbox.h"
#include "gui/createbox.h"
#include "gui/yesnodialogbox.h"
#include "gui/dialogbox.h"
#include "gui/battleresultsintermediate.h"
#include "gui/battleresults.h"
#include "gui/missionbox.h"

/*
 * mainwindow of the game, set the general background of the game
 * author zhouwei42
 * TODO : main menu, help, card window button
 *
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mapBox->load(":maps/mapInfo.txt");
    qDebug() << "maps loaded";
    QPalette p;
    p = palette();
    p.setBrush(QPalette::Window, QBrush(QPixmap(":/maps/textbg.png")));
    setPalette(p);
    QObject::connect(ui->mapBox,SIGNAL(countrySelected(QString,int,int,int,int)),ui->infobox,SLOT(country(QString,int,int,int,int)));
    ui->stackedWidget->setCurrentWidget(ui->menu);
    QString playerList[6] = {"Player 1", "Player 2", "Player 3", "Player 4", "Player 5", "Player 6"};
    MainWindow::setPlayers(6,playerList);
}


QString MainWindow::playersList[6] = {"No Player", "No Player", "No Player", "No Player", "No Player", "No Player"};

const QColor MainWindow::colors[6] = {QColor(255,255,0),QColor(255,0,0),QColor(255,0,255),QColor(0,255,0),QColor(0,255,255),QColor(0,0,255)};

int MainWindow::nbPlayer = 6;

int MainWindow::freeTroops = 0;

bool MainWindow::isFreeingTroops = false;

bool MainWindow::isAddingTroops = false;

bool MainWindow::isMovingTroops = false;

void MainWindow::setPlayers(int n,QString names[]){
    MainWindow::nbPlayer = n;
    for (int i = 0; i < n; i++){
        MainWindow::playersList[i] = names[i];
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quit_pressed()
{
    close();
}


void MainWindow::on_question_pressed()
{
    Form *win = new Form(this);
    win->show();
}


void MainWindow::on_start_pressed()
{
    ui->stackedWidget->setCurrentWidget(ui->game);
}

void MainWindow::on_toMenu_pressed()
{
    ui->stackedWidget->setCurrentWidget(ui->menu);
}


void MainWindow::on_cards_pressed()
{
    CardBox *cardbox = new CardBox(this);
    cardbox->show();
}

void MainWindow::on_freeTroops_pressed()
{
    if (MainWindow::isFreeingTroops)
    {
        ui->freeTroops->setText("Free Troops");
        ui->addTroops->setEnabled(true);
        ui->moveTroops->setEnabled(true);
        MainWindow::isFreeingTroops = false;
    }
    else
    {
        ui->freeTroops->setText("Stop Freeing");
        ui->addTroops->setEnabled(false);
        ui->moveTroops->setEnabled(false);
        MainWindow::isFreeingTroops = true;
    }
}

void MainWindow::on_addTroops_pressed()
{
    if (MainWindow::isAddingTroops)
    {
        ui->addTroops->setText("Add Troops");
        ui->freeTroops->setEnabled(true);
        ui->moveTroops->setEnabled(true);
        MainWindow::isAddingTroops = false;
    }
    else
    {
        ui->addTroops->setText("Stop Adding");
        ui->freeTroops->setEnabled(false);
        ui->moveTroops->setEnabled(false);
        MainWindow::isAddingTroops = true;
    }
}

void MainWindow::on_moveTroops_pressed()
{
    {
        if (MainWindow::isMovingTroops)
        {
            ui->moveTroops->setText("Move Troops");
            ui->addTroops->setEnabled(true);
            ui->freeTroops->setEnabled(true);
            MainWindow::isMovingTroops = false;
        }
        else
        {
            ui->moveTroops->setText("Stop Moving");
            ui->freeTroops->setEnabled(false);
            ui->addTroops->setEnabled(false);
            MainWindow::isMovingTroops = true;
        }
    }
}

void MainWindow::on_networkButton_pressed()
{
    ui->stackedWidget->setCurrentWidget(ui->network);
}

void MainWindow::on_returnButton_pressed()
{
    ui->stackedWidget->setCurrentWidget(ui->menu);
}

void MainWindow::on_joinButton_pressed()
{
    JoinBox* joinbox = new JoinBox();
    joinbox->show();
}

void MainWindow::on_createButton_pressed()
{
    CreateBox* createbox = new CreateBox();
    createbox->show();
}

void MainWindow::on_showMission_clicked()
{
    missionbox missionWindow;
    missionWindow.setModal(true);
    missionWindow.exec();

}

bool MainWindow::askUser(QString question){
    YesNoDialogBox* askbox = new YesNoDialogBox(question);
    return askbox->ask();
}

void MainWindow::tellUser(QString info){
    DialogBox* tellbox = new DialogBox(info);
    tellbox->tell();
}
