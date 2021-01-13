
#include "taoistitem.h"

#include <QQmlEngine>

const QMap<qint32, QUrl> Taoist = {{TaoistItem::Power::Neutral, QUrl("qrc:/images/taoist_neutral.png")},
                                   {TaoistItem::Power::SecondWind, QUrl("qrc:/images/taoist_second_wind.png")},
                                   {TaoistItem::Power::StrengthOfTheMountain, QUrl("qrc:/images/taoist_strength_of_the_mountain.png")},
                                   {TaoistItem::Power::GodsFavorite, QUrl("qrc:/images/taoist_gods_favorite.png")}};


TaoistItem::TaoistItem(QObject* parent) : QObject(parent)
{
    //
}

TaoistItem::TaoistItem(TaoistItem::Power power, QObject* parent) : QObject(parent), m_power(power)
{
    m_image = Taoist.value(power);
}

void TaoistItem::DeclareQml()
{
    qmlRegisterType<TaoistItem>("Datamodels", 1, 0, "TaoistItem");
}

QUrl TaoistItem::image() const
{
    return m_image;
}

bool TaoistItem::selected() const
{
    return m_selected;
}

TaoistItem::Power TaoistItem::power() const
{
    return m_power;
}

void TaoistItem::onClicked()
{
    setSelected(!m_selected);
}

void TaoistItem::setImage(QUrl image)
{
    if (m_image == image)
        return;

    m_image = image;
    emit imageChanged(m_image);
}

void TaoistItem::setSelected(bool selected)
{
    if (m_selected == selected)
        return;

    m_selected = selected;
    emit selectedChanged(m_selected);
}

void TaoistItem::setPower(TaoistItem::Power power)
{
    if (m_power == power)
        return;

    m_power = power;
    emit powerChanged(m_power);
}
