
#include "resistancemodel.h"
#include "items/resistanceitem.h"

#include <QQmlEngine>

constexpr qint32 MaxResistance = 3;

ResistanceModel::ResistanceModel(QObject* parent) : QAbstractListModel(parent)
{
    for (qint32 i = 0; i < MaxResistance; ++i)
    {
        m_arrItems.append(new ResistanceItem(this));
        connect(m_arrItems.last(), &ResistanceItem::selectedChanged, this, &ResistanceModel::updateResistance);
    }
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

    ResistanceItem* pItem = m_arrItems.at(index.row());
    if (role == Roles::ObjectRole)
    {
        return QVariant::fromValue(pItem);
    }

    return QVariant();
}

QHash<int, QByteArray> ResistanceModel::roleNames() const
{
    return {{Roles::ObjectRole, "object"}};
}

qint32 ResistanceModel::resitance() const
{
    return m_resitance;
}

void ResistanceModel::setResitance(qint32 resitance)
{
    if (m_resitance == resitance)
        return;

    m_resitance = resitance;
    emit resitanceChanged(m_resitance);
}

void ResistanceModel::updateResistance()
{
    qint32 resistance = 0;
    for (ResistanceItem* item : m_arrItems)
    {
        if (item->selected())
        {
            ++resistance;
        }
    }

    setResitance(resistance);
}
