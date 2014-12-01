#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>

class Level : public QObject
{
    Q_OBJECT

    /** Name of level */
    QString m_name;
    /** Number propositions also level */
    int m_numberPropositions;

public:
    explicit Level(QString nameNiveau);

    const QString& getName()const;
    int getNumberPropositions()const;

signals:

public slots:

};

#endif // LEVEL_H
