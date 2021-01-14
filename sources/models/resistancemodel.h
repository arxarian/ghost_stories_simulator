
#pragma once

#include <QAbstractListModel>
#include <QTimer>

class ResistanceItem;

class ResistanceModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(qint32 resitance READ resitance NOTIFY resitanceChanged)

public:
    enum Roles
    {
        ObjectRole = Qt::UserRole
    };
    Q_ENUM(Roles)

    ResistanceModel(QObject* parent = nullptr);

    static void DeclareQml();

    Q_INVOKABLE virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    Q_INVOKABLE virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE virtual QHash<int, QByteArray> roleNames() const override;

    qint32 resitance() const;

signals:
    void resitanceChanged(qint32 resitance);

private:
    QList<ResistanceItem*> m_arrItems;
    qint32 m_resitance = 0;

private slots:
    void setResitance(qint32 resitance);
    void updateResistance();
};
