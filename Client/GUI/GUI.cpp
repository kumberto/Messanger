#include "GUI.h"

GUI::GUI(std::unique_ptr<GUIRequestInterface> controller)
    :m_controller(std::move(controller))
{

}

void GUI::singIn(QString nickName, QString password)
{
    m_controller->singInRequest(nickName.toStdString(), password.toStdString());
}

void GUI::singInResponse(std::string errorConnect)
{
    if(errorConnect == "Success")
    {

    }
}

void GUI::registrationResponse(std::string errorConnect)
{

}

void GUI::findFriendResponse(std::string error, QJsonDocument friends)
{

}

void GUI::getHistoryOfUserResponse(QJsonDocument history)
{

}

void GUI::addFriendResponse(std::string error, std::string nick)
{

}

void GUI::sendMessageResponse(std::string message, std::string error)
{

}

void GUI::loadingDataResponse(QJsonDocument data)
{

}
