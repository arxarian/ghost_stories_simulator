
#pragma once

#include <QAbstractListModel>
#include <QTimer>

class DieItem;

class DiceModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(qint32 dice READ dice NOTIFY diceChanged)

public:
    enum Roles
    {
        ObjectRole = Qt::UserRole
    };
    Q_ENUM(Roles)

    DiceModel(QObject* parent = nullptr);

    static void DeclareQml();

    Q_INVOKABLE virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    Q_INVOKABLE virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE virtual QHash<int, QByteArray> roleNames() const override;

    //    Q_INVOKABLE bool enableExtraDie(bool enable);

    qint32 dice() const;

signals:
    void diceChanged(qint32 resitance);

private:
    QList<DieItem*> m_arrItems;
    qint32 m_dice = 0;

private slots:
    void setDice(qint32 dice);
    void updateResistance();
};
