
#include "dicemodel.h"
#include "items/dieitem.h"

#include <QQmlEngine>

constexpr qint32 MaxDice = 3;

DiceModel::DiceModel(QObject* parent) : QAbstractListModel(parent)
{
    for (qint32 i = 0; i < MaxDice; ++i)
    {
        m_arrItems.append(new DieItem(DieItem::Type::Basic, this));
        connect(m_arrItems.last(), &DieItem::selectedChanged, this, &DiceModel::updateDice);
    }

    m_arrItems.first()->setSelected(true);

    m_arrItems.append(new DieItem(DieItem::Type::Extra, this));
    connect(m_arrItems.last(), &DieItem::selectedChanged, this, &DiceModel::updateDice);

    updateDice();
}

void DiceModel::DeclareQml()
{
    DieItem::DeclareQml();

    qmlRegisterType<DiceModel>("Datamodels", 1, 0, "DiceModel");
}

int DiceModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return m_arrItems.count();
}

QVariant DiceModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= rowCount())
    {
        return QVariant();
    }

    DieItem* pItem = m_arrItems.at(index.row());
    if (role == Roles::ObjectRole)
    {
        return QVariant::fromValue(pItem);
    }

    return QVariant();
}

QHash<int, QByteArray> DiceModel::roleNames() const
{
    return {{Roles::ObjectRole, "object"}};
}

qint32 DiceModel::dice() const
{
    return m_dice;
}

bool DiceModel::extraDie() const
{
    return m_extraDie;
}

void DiceModel::setExtraDie(bool extraDie)
{
    if (m_extraDie == extraDie)
        return;

    m_extraDie = extraDie;
    emit extraDieChanged(m_extraDie);

    if (!m_extraDie)
    {
        for (DieItem* die : m_arrItems)
        {
            if (die->type() == DieItem::Type::Extra)
            {
                die->setSelected(false);
            }
        }
    }
}

void DiceModel::setDice(qint32 dice)
{
    if (m_dice == dice)
        return;

    m_dice = dice;
    emit diceChanged(m_dice);
}

void DiceModel::updateDice()
{
    qint32 dice = 0;
    for (DieItem* item : m_arrItems)
    {
        if (item->selected())
        {
            ++dice;
        }
    }

    setDice(dice);
}
