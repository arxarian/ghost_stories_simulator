
#include "models/chancesmodel.h"
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
    ChancesModel::DeclareQml();

    ResistanceModel* resistanceModel = new ResistanceModel(&engine);
    TaoistModel* taoistModel         = new TaoistModel(&engine);
    DiceModel* diceModel             = new DiceModel(&engine);
    ChancesModel* chancesModel       = new ChancesModel(&engine);

    QObject::connect(resistanceModel, &ResistanceModel::resitanceChanged, chancesModel, &ChancesModel::setResistance);
    QObject::connect(diceModel, &DiceModel::diceChanged, chancesModel, &ChancesModel::setDice);
    QObject::connect(taoistModel, &TaoistModel::selectedTaoistChanged, &engine, [chancesModel](TaoistItem* selectedTaoist) {
        chancesModel->setPower(selectedTaoist->power());
    });

    chancesModel->setResistance(resistanceModel->resitance());
    chancesModel->setDice(diceModel->dice());
    chancesModel->setPower(taoistModel->selectedTaoist()->power());

    engine.rootContext()->setContextProperty("resistanceModel", resistanceModel);
    engine.rootContext()->setContextProperty("taoistModel", taoistModel);
    engine.rootContext()->setContextProperty("diceModel", diceModel);
    engine.rootContext()->setContextProperty("chancesModel", chancesModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
