#ifndef HEADER_Client_Utils
#define HEADER_Client_Utils

#include <QtGui>
#include <QtNetwork>

#include <QTextEdit>

class Client_Utils : public QObject
{
    Q_OBJECT
public:
    Client_Utils(QTextEdit* liste);
    Client_Utils();
    ~Client_Utils();
    void connect_to(QString ip, int port);
    void send(const QString &messageAEnvoyer);

private slots:
       
        void on_message_returnPressed()  {};
        void donneesRecues();
        void connecte();
        void deconnecte();
        void erreurSocket(QAbstractSocket::SocketError erreur);

    private:
        QTcpSocket *socket; // Représente le serveur
        quint16 tailleMessage;
        QTextEdit* listeMessages;
};


#endif // CLIENT_UTILS_H
