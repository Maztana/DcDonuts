#ifndef NIVEAU_H
#define NIVEAU_H

#include <QObject>

class Niveau : public QObject
{
    Q_OBJECT

    QString name;

public:
    explicit Niveau();

    const QString& getName()const;

signals:

public slots:

};

#endif // NIVEAU_H
