
#include "resistancemodel.h"
#include "items/resistanceitem.h"

#include <QQmlEngine>

ResistanceModel::ResistanceModel(QObject* parent) : QAbstractListModel(parent)
{
    m_arrItems.append(new ResistanceItem(this));
    m_arrItems.append(new ResistanceItem(this));
    m_arrItems.append(new ResistanceItem(this));
    m_arrItems.append(new ResistanceItem(this));
}

void ResistanceModel::DeclareQml()
{
    ResistanceItem::DeclareQml();

    qmlRegisterType<ResistanceModel>("Datamodels", 1, 0, "ResistanceModel");
}

int ResistanceModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return m_arrItems.count();
}

QVariant ResistanceModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= rowCount())
    {
        return QVariant();
    }

    ResistanceItem* pSubMenuItem = m_arrItems.at(index.row());
    if (role == Roles::ObjectRole)
    {
        return QVariant::fromValue(pSubMenuItem);
    }

    return QVariant();
}

QHash<int, QByteArray> ResistanceModel::roleNames() const
{
    return {{Roles::ObjectRole, "object"}};
}
