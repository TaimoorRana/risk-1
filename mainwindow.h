#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "gui/yesnodialogbox.h"

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
    void on_quit_pressed();
    void on_question_pressed();
    void on_start_pressed();
    void on_toMenu_pressed();
    void on_cards_pressed();
    void on_freeTroops_pressed();
    void on_addTroops_pressed();
    void on_moveTroops_pressed();
    void on_networkButton_pressed();
    void on_returnButton_pressed();
    void on_joinButton_pressed();
    void on_createButton_pressed();
    void on_showMission_clicked();
    bool askUser(QString question); // yes-no pop-up created when called
    void tellUser(QString info);

public:
    const static QColor colors[6];
    static QString playersList[6];
    static void setPlayers(int, QString[]);
    static int nbPlayer;
    static int freeTroops;
    static bool isFreeingTroops;
    static bool isAddingTroops;
    static bool isMovingTroops;

private:
    Ui::MainWindow *ui;
    YesNoDialogBox *d;
};

#endif // MAINWINDOW_H
