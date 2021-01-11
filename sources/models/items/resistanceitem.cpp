
#include "resistanceitem.h"

#include <QQmlEngine>

ResistanceItem::ResistanceItem(QObject* parent) : QObject(parent)
{
    //
}

void ResistanceItem::DeclareQml()
{
    qmlRegisterType<ResistanceItem>("Datamodels", 1, 0, "ResistanceItem");
}

QUrl ResistanceItem::image() const
{
    return m_image;
}

bool ResistanceItem::selected() const
{
    return m_selected;
}

void ResistanceItem::setImage(QUrl image)
{
    if (m_image == image)
        return;

    m_image = image;
    emit imageChanged(m_image);
}

void ResistanceItem::setSelected(bool selected)
{
    if (m_selected == selected)
        return;

    m_selected = selected;
    emit selectedChanged(m_selected);
}
