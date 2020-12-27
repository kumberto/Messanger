#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>


#include "ModelInterface.h"

class Model : public QObject, public ModelInterface
{
    Q_OBJECT
    Q_PROPERTY(QString errorMessage READ getErrorMessage WRITE setErrorMessage NOTIFY errorMessageChanged)
public:
    explicit Model();

    QString getErrorMessage() const;
    void setErrorMessage(QString value);

private:
    void singIn(std::string nickName, std::string password) override;

signals:
    void errorMessageChanged();
private:
    QTcpSocket* m_socket;
    QByteArray m_data;
    QJsonDocument m_document;
    QJsonParseError m_error;
    QString m_errorMessage;

public slots:
    void sockReady();
    void sockDisc();
//    QString getErrorMessage() const;
//    void setErrorMessage(QString value);
};

#endif // MODEL_H
