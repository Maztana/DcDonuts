#include "niveau.h"

Niveau::Niveau(QString nameNiveau) :
    QObject(0), name(nameNiveau)
{
}

const QString& Niveau::getName()const
{
    return name;
}
