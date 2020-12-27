#ifndef GUIREQUESTINTERFACE_H
#define GUIREQUESTINTERFACE_H
#include <string>
#include <vector>


class GUIRequestInterface
{
    public:
        virtual void singInRequest(std::string nickName, std::string password) = 0;
        virtual void registrationRequest(std::string nickName, std::string password) = 0;
        virtual void findFriendRequest(std::string nickName) = 0;
        virtual void getHistoryOfUserRequest() = 0;
        virtual void addFriendRequest(std::string nickName) = 0;
        virtual void sendMessageRequest(std::string message) = 0;
        virtual void loadingDataRequest() = 0;
};

#endif // GUIREQUESTINTERFACE_H
