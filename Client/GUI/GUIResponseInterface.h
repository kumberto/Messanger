#ifndef GUIRESPONSEINTERFACE_H
#define GUIRESPONSEINTERFACE_H
#include <string>
#include <vector>
#include <QJsonDocument>


class GUIResponseInterface
{
    public:
        virtual void singInResponse(std::string errorConnect) = 0;
        virtual void registrationResponse(std::string errorConnect) = 0;
        virtual void findFriendResponse(std::string error, QJsonDocument friends) = 0;
        virtual void getHistoryOfUserResponse(QJsonDocument history) = 0;
        virtual void addFriendResponse(std::string error, std::string nick) = 0;
        virtual void sendMessageResponse(std::string message, std::string error) = 0;
        virtual void loadingDataResponse(QJsonDocument data) = 0;
};
#endif // GUIRESPONSEINTERFACE_H
