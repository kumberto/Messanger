#include "Model.h"
#include <QDebug>
#include <QMessageBox>

Model::Model() : QObject()
{
    m_socket = new QTcpSocket(this);
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
    m_socket->connectToHost("127.0.0.1", 5555);
}

QString Model::getErrorMessage() const
{
    return m_errorMessage;
}

void Model::setErrorMessage(QString value)
{
    m_errorMessage = value;
    emit errorMessageChanged();
}

bool Model::singIn(std::string nickName, std::string password)
{
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
        m_document = QJsonDocument::fromJson(m_data, &m_error);

        if(m_error.errorString().toInt() == QJsonParseError::NoError)
        {
            if ((m_document.object().value("type").toString() == "connect") && (m_document.object().value("status").toString() == "yes"))
            {
                setErrorMessage("Connected");
            }
            else
            {
                setErrorMessage("No connected");
            }
        }
        else
        {
            qDebug() << m_error.errorString();
        }
    }
}

void Model::sockDisc()
{
    m_socket->deleteLater();
}

