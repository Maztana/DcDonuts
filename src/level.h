#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>

class Level : public QObject
{
    Q_OBJECT

    /** Name of level */
    QString m_name;

public:
    explicit Level(QString nameNiveau);

    const QString& getName()const;

signals:

public slots:

};

#endif // LEVEL_H
