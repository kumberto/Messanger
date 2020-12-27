#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <memory>
#include "GUI/GUIRequestInterface.h"
#include "Model/ModelInterface.h"

class Controller : public QObject, public GUIRequestInterface
{
    Q_OBJECT;
public:
    Controller(std::unique_ptr<ModelInterface>);
private:
    virtual void singInRequest(std::string nickName, std::string password) override;
    virtual void registrationRequest(std::string nickName, std::string password) override;
    virtual void findFriendRequest(std::string nickName) override;
    virtual void getHistoryOfUserRequest() override;
    virtual void addFriendRequest(std::string nickName) override;
    virtual void sendMessageRequest(std::string message) override;
    virtual void loadingDataRequest() override;

    std::unique_ptr<ModelInterface> m_model;
};

#endif // CONTROLLER_H
