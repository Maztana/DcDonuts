#include "niveau.h"

Niveau::Niveau() :
    QObject(0)
{
    name = "non défini";
}

const QString& Niveau::getName()const
{
    return name;
}
