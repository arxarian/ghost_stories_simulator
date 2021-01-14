
#pragma once

#include <QAbstractListModel>
#include <QTimer>

class TaoistItem;

class TaoistModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(TaoistItem* selectedTaoist READ selectedTaoist WRITE setSelectedTaoist NOTIFY selectedTaoistChanged)

public:
    enum Roles
    {
        ObjectRole = Qt::UserRole
    };
    Q_ENUM(Roles)

    TaoistModel(QObject* parent = nullptr);

    static void DeclareQml();

    Q_INVOKABLE virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    Q_INVOKABLE virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE virtual QHash<int, QByteArray> roleNames() const override;

    TaoistItem* selectedTaoist() const;

public slots:
    void setSelectedTaoist(TaoistItem* selectedTaoist);

signals:
    void selectedTaoistChanged(TaoistItem* selectedTaoist);

private:
    QList<TaoistItem*> m_arrItems;

    TaoistItem* m_selectedTaoist = nullptr;
};
