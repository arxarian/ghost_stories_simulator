
#include "dicemodel.h"
#include "items/dieitem.h"

#include <QQmlEngine>

constexpr qint32 MaxDice = 3;

DiceModel::DiceModel(QObject* parent) : QAbstractListModel(parent)
{
    for (qint32 i = 0; i < MaxDice; ++i)
    {
        m_arrItems.append(new DieItem(DieItem::Type::Basic, this));
        connect(m_arrItems.last(), &DieItem::selectedChanged, this, &DiceModel::updateResistance);
    }

    m_arrItems.append(new DieItem(DieItem::Type::Extra, this));
    connect(m_arrItems.last(), &DieItem::selectedChanged, this, &DiceModel::updateResistance);
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

void DiceModel::setDice(qint32 dice)
{
    if (m_dice == dice)
        return;

    m_dice = dice;
    emit diceChanged(m_dice);
}

void DiceModel::updateResistance()
{
    qint32 resistance = 0;
    for (DieItem* item : m_arrItems)
    {
        if (item->selected())
        {
            ++resistance;
        }
    }

    setDice(resistance);
}
