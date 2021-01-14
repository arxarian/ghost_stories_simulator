
#pragma once

#include <QObject>
#include <QUrl>

class TaoistItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl image READ image WRITE setImage NOTIFY imageChanged)
    Q_PROPERTY(bool selected READ selected WRITE setSelected NOTIFY selectedChanged)
    Q_PROPERTY(Power power READ power WRITE setPower NOTIFY powerChanged)

public:
    enum Power
    {
        Neutral,               // red, yellow
        SecondWind,            // blue - complete reroll
        StrengthOfTheMountain, // green - an extra die
        GodsFavorite           // green - reroll of unfitting
    };
    Q_ENUM(Power)

    explicit TaoistItem(QObject* parent = nullptr);
    explicit TaoistItem(Power power, QObject* parent = nullptr);

    static void DeclareQml();

    QUrl image() const;
    bool selected() const;
    Power power() const;

public slots:
    void onClicked();

    void setImage(QUrl image);
    void setSelected(bool selected);
    void setPower(Power power);

signals:
    void imageChanged(QUrl image);
    void selectedChanged(bool selected);

    void powerChanged(Power power);

private:
    QUrl m_image;
    bool m_selected = false;
    Power m_power   = Power::Neutral;
};
