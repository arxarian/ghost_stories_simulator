
#pragma once

#include <QAbstractListModel>
#include <QTimer>

#include "sources/models/items/taoistitem.h"

class ChancesModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal chance READ chance NOTIFY chanceChanged)
    Q_PROPERTY(qint32 dice READ dice WRITE setDice NOTIFY diceChanged)
    Q_PROPERTY(qint32 resistance READ resistance WRITE setResistance NOTIFY resistanceChanged)
    Q_PROPERTY(TaoistItem::Power power READ power WRITE setPower NOTIFY powerChanged)

public:
    ChancesModel(QObject* parent = nullptr);

    static void DeclareQml();

    qreal chance() const;
    qint32 dice() const;
    qint32 resistance() const;
    TaoistItem::Power power() const;

public slots:
    void setDice(qint32 dice);
    void setResistance(qint32 resistance);
    void setPower(TaoistItem::Power power);

signals:
    void chanceChanged(qreal chance);
    void diceChanged(qint32 dice);
    void resistanceChanged(qint32 resistance);
    void powerChanged(TaoistItem::Power power);

private:
    qreal m_chance            = 0.0;
    TaoistItem::Power m_power = TaoistItem::Power::Neutral;
    qint32 m_dice             = 0;
    qint32 m_resistance       = 0;

private:
    void updateChance();

private slots:
    void setChance(qreal chance);
};
