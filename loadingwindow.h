#ifndef HEADER_LOADINGWINDOW
#define HEADER_LOADINGWINDOW

#include <QWidget>
#include <QString>
#include <QStyle>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QApplication>
#include <QDesktopWidget>



class LoadingWindow : public QWidget
{

    Q_OBJECT

    public:
    //Constructs the loading screen with a background picture
    //and a text (for example "loading...")
    LoadingWindow(QString text, QApplication* a);

    private:
    QString text;

};
#endif
