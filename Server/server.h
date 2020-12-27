#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFile>
#include <QMap>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();
    ~Server();

private:
    QTcpSocket* m_socket;
    QByteArray m_data;

    QJsonDocument m_document;
    QJsonParseError m_error;

    QMap<QString, QString> m_usersOnline;
    QJsonDocument m_users;

public slots:
    void startServer();
    void incomingConnection(qintptr socketDescriptor);
    void sockReady();
    void sockDisc();
};

#endif // SERVER_H
