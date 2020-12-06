#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "GUI/GUIInterface.h"


class Controller : public QObject, public GUIInterface
{
    Q_OBJECT;
public:
    Controller();
private:
    virtual bool registration(std::string nickName, std::string password) override;
    virtual bool findFriend(std::string nickName) override;
    virtual std::vector<History> getHistoryOfUser() override;
    virtual void addFriend(std::string nickName) override;
    virtual bool sendMessage(std::string message) override;
    virtual UsersData loadingData() override;
};

#endif // CONTROLLER_H
