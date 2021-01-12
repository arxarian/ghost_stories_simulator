
#pragma once

#include <QObject>
#include <QUrl>

class DieItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl image READ image WRITE setImage NOTIFY imageChanged)
    Q_PROPERTY(bool selected READ selected WRITE setSelected NOTIFY selectedChanged)
    Q_PROPERTY(Type type READ type WRITE setType NOTIFY typeChanged)

public:
    enum Type
    {
        Basic,
        Extra
    };
    Q_ENUM(Type)

    explicit DieItem(QObject* parent = nullptr);
    explicit DieItem(Type type, QObject* parent = nullptr);

    static void DeclareQml();

    QUrl image() const;
    bool selected() const;
    Type type() const;

public slots:
    void onClicked();

    void setImage(QUrl image);
    void setSelected(bool selected);
    void setType(Type type);

signals:
    void imageChanged(QUrl image);
    void selectedChanged(bool selected);
    void typeChanged(Type type);

private:
    QUrl m_image;
    bool m_selected = false;
    Type m_type     = Type::Basic;
};
