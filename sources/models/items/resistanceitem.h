
#pragma once

#include <QObject>
#include <QUrl>

class ResistanceItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl image READ image WRITE setImage NOTIFY imageChanged)
    Q_PROPERTY(bool selected READ selected WRITE setSelected NOTIFY selectedChanged)

public:
    explicit ResistanceItem(QObject* parent = nullptr);

    static void DeclareQml();

    QUrl image() const;
    bool selected() const;

public slots:
    void onClicked();

    void setImage(QUrl image);
    void setSelected(bool selected);

signals:
    void imageChanged(QUrl image);
    void selectedChanged(bool selected);

private:
    QUrl m_image    = QUrl("qrc:/images/resistance.png");
    bool m_selected = false;
};
