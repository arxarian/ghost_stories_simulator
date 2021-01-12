
#include "taoistmodel.h"
#include "items/taoistitem.h"

#include <QQmlEngine>

TaoistModel::TaoistModel(QObject* parent) : QAbstractListModel(parent)
{
    m_arrItems.append(new TaoistItem(TaoistItem::Power::Neutral, this));
    m_arrItems.append(new TaoistItem(TaoistItem::Power::SecondWind, this));
    m_arrItems.append(new TaoistItem(TaoistItem::Power::StrengthOfTheMountain, this));
    m_arrItems.append(new TaoistItem(TaoistItem::Power::GodsFavorite, this));
}

void TaoistModel::DeclareQml()
{
    TaoistItem::DeclareQml();

    qmlRegisterType<TaoistModel>("Datamodels", 1, 0, "TaoistModel");
}

int TaoistModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return m_arrItems.count();
}

QVariant TaoistModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= rowCount())
    {
        return QVariant();
    }

    TaoistItem* pItem = m_arrItems.at(index.row());
    if (role == Roles::ObjectRole)
    {
        return QVariant::fromValue(pItem);
    }

    return QVariant();
}

QHash<int, QByteArray> TaoistModel::roleNames() const
{
    return {{Roles::ObjectRole, "object"}};
}
