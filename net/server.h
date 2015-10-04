#ifndef SERVER_H
#define SERVER_H

#include <QtWidgets>
#include <QtGui>
#include <QtNetwork>
#include <QMap>

class Server : public QWidget
{
    Q_OBJECT

    public:
        Server();
        void send_message(const QJsonObject j);
        void send_message(const QList<int> l, const QJsonObject j);
        QList<int> ids;
        int port;

    private slots:
        void newConnexion();
        void receive_message();
        void disconnectClient();

    private:
        QLabel *Serverstate;
        QPushButton *boutonQuitter;
        QMap<int, QTcpSocket *> map;
        QTcpServer *server;
        QList<QTcpSocket *> clients;
        quint64 messageLength;
        QMap<void*, int> pointeurMap;
        int id_count;
};

#endif // SERVER_H

