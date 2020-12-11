#include "server.h"
//#include <QDebug>

Server::Server()
{

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
            m_socket->write("");
}

void Server::sockReady()
{

}

void Server::sockDisc()
{

}
