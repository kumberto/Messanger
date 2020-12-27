#ifndef GUI_H
#define GUI_H
#include <string>
#include <vector>
#include <QObject>
#include <memory>
#include "GUIRequestInterface.h"
#include "GUIResponseInterface.h"


class GUI : public QObject, public GUIResponseInterface
{
    Q_OBJECT;

    public:
        //Q_PROPERTY(bool visibleRegistryForm READ visibleRegistryForm WRITE setVisibleRegistryForm NOTIFY visibleRegistryFormChanged);
        GUI(std::unique_ptr<GUIRequestInterface>);
        Q_INVOKABLE void singIn(QString nickName, QString password);
        //Q_INVOKABLE void singUp(QString nickName, QString password);

    private:
        void singInResponse(std::string errorConnect) override;
        void registrationResponse(std::string errorConnect) override;
        void findFriendResponse(std::string error, QJsonDocument friends) override;
        void getHistoryOfUserResponse(QJsonDocument history) override;
        void addFriendResponse(std::string error, std::string nick) override;
        void sendMessageResponse(std::string message, std::string error) override;
        void loadingDataResponse(QJsonDocument data) override;

    private:
        std::unique_ptr<GUIRequestInterface> m_controller;
};

#endif // GUIINTERFACE_H
