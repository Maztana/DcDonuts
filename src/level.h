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
    explicit Level(QString nameLevel);

    int getIndex()const;
    const QString& getName()const;

private:
    void initLevel();

};

#endif // LEVEL_H
