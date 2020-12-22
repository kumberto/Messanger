#include "server.h"
//#include <QDebug>

Server::Server()
{
    QFile file;
    file.setFileName("Users.json");
    if (file.open(QIODevice::ReadOnly|QFile::Text))
    {
        QByteArray fromFile = file.readAll();
        m_Users = QJsonDocument::fromJson(fromFile, &m_error);
    }
    if(m_error.errorString().toInt() != QJsonParseError::NoError)
    {
        qDebug()<<"Error: " << m_error.errorString().toInt();
    }
}

Server::~Server()
{

}

void Server::startServer()
{
    if (listen(QHostAddress::Any, 5555))
    {
        qDebug()<<"Listening";
    }
    else
    {
        qDebug()<<"Not listening";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    m_socket = new QTcpSocket(this);
    m_socket->setSocketDescriptor(socketDescriptor);

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
    qDebug()<< socketDescriptor << "Client connected";
    m_socket->write("You are connect");

}

void Server::sockReady()
{
    m_data = m_socket->readAll();
    qDebug() << "Data: " << m_data;
    m_document = QJsonDocument::fromJson(m_data, &m_error);

    if(m_error.errorString().toInt() == QJsonParseError::NoError)
    {
        if (m_document.object().value("type").toString() == "SingIn")
        {

        }
    }
}

void Server::sockDisc()
{
    qDebug()<<"Disconnect";
    m_socket->deleteLater();
}
