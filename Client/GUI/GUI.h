#ifndef GUI_H
#define GUI_H
#include <string>
#include <vector>
#include <QObject>
#include <memory>
#include "GUIInterface.h"


class GUI : public QObject
{
    Q_OBJECT;

    public:
        GUI(std::unique_ptr<GUIInterface>);
        Q_INVOKABLE void singIn(QString nickName, QString password);
    private:
        std::unique_ptr<GUIInterface> m_controller;
};

#endif // GUIINTERFACE_H
