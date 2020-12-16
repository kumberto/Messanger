#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QTcpSocket>

#include "ModelInterface.h"

class Model : public QObject, public ModelInterface
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

private:
    bool singIn(std::string nickName, std::string password) override;

signals:
private:
    QTcpSocket* m_socket;
    QByteArray m_data;

public slots:
    void sockReady();
    void sockDisc();
};

#endif // MODEL_H
