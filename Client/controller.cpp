#include "controller.h"

Controller::Controller(std::unique_ptr<ModelInterface> model)
    :m_model(std::move(model))
{
}

void Controller::singInRequest(std::string nickName, std::string password)
{
    m_model->singIn(nickName, password);
}

void Controller::registrationRequest(std::string nickName, std::string password)
{

}
void Controller::findFriendRequest(std::string nickName)
{
}
void Controller::getHistoryOfUserRequest()
{
}
void Controller::addFriendRequest(std::string nickName)
{

}
void Controller::sendMessageRequest(std::string message)
{
}
void Controller::loadingDataRequest()
{
}
