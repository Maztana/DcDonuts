#include "typedejeu.h"

TypeDeJeu::TypeDeJeu():
    QObject(0)
{
}

TypeDeJeu::~TypeDeJeu()
{
    delete(niveauDuJeu);
}

const Niveau& TypeDeJeu::getNiveau()
{
    return *niveauDuJeu;
}

void TypeDeJeu::setNiveau(Niveau *newNiveau)
{
    niveauDuJeu = newNiveau;
    defNiveau();
}
