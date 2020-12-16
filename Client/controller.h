#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <memory>
#include "GUI/GUIInterface.h"
#include "Model/ModelInterface.h"

class Controller : public QObject, public GUIInterface
{
    Q_OBJECT;
public:
    Controller(std::unique_ptr<ModelInterface>);
private:
    virtual bool singIn(std::string nickName, std::string password) override;
    virtual bool registration(std::string nickName, std::string password) override;
    virtual bool findFriend(std::string nickName) override;
    virtual std::vector<History> getHistoryOfUser() override;
    virtual void addFriend(std::string nickName) override;
    virtual bool sendMessage(std::string message) override;
    virtual UsersData loadingData() override;

    std::unique_ptr<ModelInterface> m_model;
};

#endif // CONTROLLER_H
