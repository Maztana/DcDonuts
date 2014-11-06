#include "typedejeu.h"

TypeDeJeu::TypeDeJeu():
    QObject(0)
{
}

void TypeDeJeu::setNiveau(Niveau *newNiveau)
{
    niveauDuJeu = newNiveau;
}
