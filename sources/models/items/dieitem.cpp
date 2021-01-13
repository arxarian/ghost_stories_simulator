
#include "dieitem.h"

#include <QQmlEngine>

const QMap<qint32, QUrl> Dice = {{DieItem::Type::Basic, QUrl("qrc:/images/die_basic.png")},
                                 {DieItem::Type::Extra, QUrl("qrc:/images/die_extra.png")}};


DieItem::DieItem(QObject* parent) : QObject(parent)
{
    //
}

DieItem::DieItem(DieItem::Type type, QObject* parent) : QObject(parent), m_type(type)
{
    m_image = Dice.value(type);
}

void DieItem::DeclareQml()
{
    qmlRegisterType<DieItem>("Datamodels", 1, 0, "DieItem");
}

QUrl DieItem::image() const
{
    return m_image;
}

bool DieItem::selected() const
{
    return m_selected;
}

DieItem::Type DieItem::type() const
{
    return m_type;
}

void DieItem::onClicked()
{
    setSelected(!m_selected);
}

void DieItem::setImage(QUrl image)
{
    if (m_image == image)
        return;

    m_image = image;
    emit imageChanged(m_image);
}

void DieItem::setSelected(bool selected)
{
    if (m_selected == selected)
        return;

    m_selected = selected;
    emit selectedChanged(m_selected);
}

void DieItem::setType(DieItem::Type type)
{
    if (m_type == type)
        return;

    m_type = type;
    emit typeChanged(m_type);
}
