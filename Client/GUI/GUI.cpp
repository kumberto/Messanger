#include "GUI.h"

GUI::GUI(std::unique_ptr<GUIInterface> controller)
    :m_controller(std::move(controller))
{

}

void GUI::singIn(QString nickName, QString password)
{
    m_controller->singIn(nickName.toStdString(), password.toStdString());
}
