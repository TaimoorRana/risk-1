#ifndef HEADER_FENSERVEUR
#define HEADER_FENSERVEUR

#include <QtWidgets>
#include <QtGui>
#include <QtNetwork>
#include <QMap>
#include <QDialog>
#include "../pseudo_net/server_utils.h"

class CreateBox : public QDialog
{
    Q_OBJECT

    public:
        CreateBox();
       // void envoyerATous(const QString &message);
        //void sendTo(const QList<int> l, const QString &message);

	/*    private slots:
        void nouvelleConnexion();
        void donneesRecues();
        void deconnexionClient();
	*/
    private:
        QLabel *etatServeur;
        QPushButton *boutonQuitter;
        IServer* server;
	
};

#endif
