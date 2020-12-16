#include "Model.h"
#include <QDebug>

Model::Model(QObject *parent) : QObject(parent)
{
    m_socket = new QTcpSocket(this);
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
}

bool Model::singIn(std::string nickName, std::string password)
{
    m_socket->connectToHost("127.0.0.1", 5555);
    std::string data = nickName + password;
    m_socket->write(data.c_str(), data.length());
}

void Model::sockReady()
{
    if(m_socket->waitForConnected(500))
    {
        m_socket->waitForReadyRead(500);
        m_data = m_socket->readAll();
        qDebug() << m_data;
    }
}

void Model::sockDisc()
{
    m_socket->deleteLater();
}
