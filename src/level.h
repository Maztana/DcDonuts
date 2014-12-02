#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>

class Level : public QObject
{
    Q_OBJECT

    /** Index of level */
    int m_indexLevel;
    /** Name of level */
    QString m_name;

public:
    explicit Level(int indexNiveau);

    int getIndex()const;
    const QString& getName()const;
    int getNumberPropositions()const;

private:
    void initLevel();

signals:

public slots:

};

#endif // LEVEL_H
