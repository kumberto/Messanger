#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include "GUI/GUI.h"
#include "controller.h"
#include "Model/Model.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/QML/main.qml"));

    std::unique_ptr<ModelInterface> model = std::make_unique<Model>();
    std::unique_ptr<GUIInterface> controller = std::make_unique<Controller>(std::move(model));
    GUI gui(std::move(controller));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextObject(&gui);

    engine.load(url);

    return app.exec();
}
