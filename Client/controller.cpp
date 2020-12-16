#include "controller.h"

Controller::Controller(std::unique_ptr<ModelInterface> model)
    :m_model(std::move(model))
{
}

bool Controller::singIn(std::string nickName, std::string password)
{
    return m_model->singIn(nickName, password);
}

bool Controller::registration(std::string nickName, std::string password)
{
 return true;
}
bool Controller::findFriend(std::string nickName)
{
    return true;
}
std::vector<History> Controller::getHistoryOfUser()
{
    return std::vector<History>();
}
void Controller::addFriend(std::string nickName)
{

}
bool Controller::sendMessage(std::string message)
{
    return true;
}
UsersData Controller::loadingData()
{
return UsersData();
}
