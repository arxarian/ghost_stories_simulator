
#include "chancesmodel.h"

#include <QQmlEngine>

const QMap<QString, qreal> Neutral = {{"1/1", 33.33}, {"2/2", 11.11}, {"2/1", 55.55}, {"3/3", 3.71}, {"3/2", 25.93}, {"3/1", 70.38}};

const QMap<QString, qreal> SecondWind = {
  {"1/1", 55.56},
  {"2/2", 20.99},
  {"2/1", 80.24},
  {"3/3", 7.27},
  {"3/2", 45.14},
  {"3/1", 91.22},
};

const QMap<QString, qreal> GodsFavorite = {
  {"1/1", 55.57},
  {"2/2", 30.87},
  {"2/1", 80.25},
  {"3/3", 17.15},
  {"3/2", 58.3},
  {"3/1", 91.22},
};

const QMap<QString, qreal> StrengthOfTheMountain = {{"1/1", 33.33},
                                                    {"2/2", 11.11},
                                                    {"2/1", 55.55},
                                                    {"3/3", 3.71},
                                                    {"3/2", 25.93},
                                                    {"3/1", 70.38},
                                                    {"4/4", 1.24},
                                                    {"4/3", 11.11},
                                                    {"4/2", 40.74},
                                                    {"4/1", 80.25}};

const QMap<TaoistItem::Power, QMap<QString, qreal>> Chances = {{TaoistItem::Power::Neutral, Neutral},
                                                               {TaoistItem::Power::SecondWind, SecondWind},
                                                               {TaoistItem::Power::GodsFavorite, GodsFavorite},
                                                               {TaoistItem::Power::StrengthOfTheMountain, StrengthOfTheMountain}};


ChancesModel::ChancesModel(QObject* parent) : QObject(parent)
{
    //
}

void ChancesModel::DeclareQml()
{
    qmlRegisterType<ChancesModel>("Datamodels", 1, 0, "ChancesModel");
}

qreal ChancesModel::chance() const
{
    return m_chance;
}

qint32 ChancesModel::dice() const
{
    return m_dice;
}

qint32 ChancesModel::resistance() const
{
    return m_resistance;
}

TaoistItem::Power ChancesModel::power() const
{
    return m_power;
}

void ChancesModel::setDice(qint32 dice)
{
    if (m_dice == dice)
        return;

    m_dice = dice;
    emit diceChanged(m_dice);

    updateChance();
}

void ChancesModel::setResistance(qint32 resistance)
{
    if (m_resistance == resistance)
        return;

    m_resistance = resistance;
    emit resistanceChanged(m_resistance);

    updateChance();
}

void ChancesModel::setPower(TaoistItem::Power power)
{
    if (m_power == power)
        return;

    m_power = power;
    emit powerChanged(m_power);

    updateChance();
}


void ChancesModel::updateChance()
{
    const QMap<QString, qreal>& taoistChances = Chances.value(m_power);
    qreal chance                              = 0.0;
    if (taoistChances.contains(QString("%1/%2").arg(m_dice).arg(m_resistance)))
    {
        chance = taoistChances.value(QString("%1/%2").arg(m_dice).arg(m_resistance));
    }

    setChance(chance);
}

void ChancesModel::setChance(qreal chance)
{
    if (qFuzzyCompare(m_chance, chance))
        return;

    m_chance = chance;
    emit chanceChanged(m_chance);
}
