
#include "models/resistancemodel.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // taoist model
    // dice model
    ResistanceModel::DeclareQml();

    ResistanceModel* pResistanceModel = new ResistanceModel(&engine);
    engine.rootContext()->setContextProperty("resistanceModel", pResistanceModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
