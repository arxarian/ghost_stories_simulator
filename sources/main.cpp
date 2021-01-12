
#include "models/dicemodel.h"
#include "models/resistancemodel.h"
#include "models/taoistmodel.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    TaoistModel::DeclareQml();
    DiceModel::DeclareQml();
    ResistanceModel::DeclareQml();

    ResistanceModel* resistanceModel = new ResistanceModel(&engine);
    TaoistModel* taoistModel         = new TaoistModel(&engine);
    DiceModel* diceModel             = new DiceModel(&engine);

    engine.rootContext()->setContextProperty("resistanceModel", resistanceModel);
    engine.rootContext()->setContextProperty("taoistModel", taoistModel);
    engine.rootContext()->setContextProperty("diceModel", diceModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
