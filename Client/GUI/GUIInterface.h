#ifndef GUIINTERFACE_H
#define GUIINTERFACE_H
#include <string>
#include <vector>
struct History
{
    struct Data
    {
        int day;
        int month;
        int year;
    };
    std::string message;
};

struct UsersData
{

};

class GUIInterface
{
    public:
        virtual bool registration(std::string nickName, std::string password) = 0;
        virtual bool findFriend(std::string nickName) = 0;
        virtual std::vector<History> getHistoryOfUser() = 0;
        virtual void addFriend(std::string nickName) = 0;
        virtual bool sendMessage(std::string message) = 0;
        virtual UsersData loadingData() = 0;
};

#endif // GUIINTERFACE_H
