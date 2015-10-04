#ifndef HEADER_FENSERVEUR
#define HEADER_FENSERVEUR

#include <QtWidgets>
#include <QtGui>
#include <QtNetwork>
#include <QMap>

class FenServeur : public QWidget
{
    Q_OBJECT

    public:
        FenServeur();
        void envoyerATous(const QString &message);
        void sendTo(const QList<int> l, const QString &message);
        QList<int> ids;

    private slots:
        void nouvelleConnexion();
        void donneesRecues();
        void deconnexionClient();

    private:
        QLabel *etatServeur;
        QPushButton *boutonQuitter;
        QMap<int, QTcpSocket *> map;
        QTcpServer *serveur;
        QList<QTcpSocket *> clients;
        quint16 tailleMessage;
        int id_count;
};

#endif
