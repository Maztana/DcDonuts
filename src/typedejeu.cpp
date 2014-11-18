#include "typedejeu.h"

TypeDeJeu::TypeDeJeu(Niveau* niveauDuJeu):
    QObject(0)
{
    setNiveau(niveauDuJeu);
}

TypeDeJeu::~TypeDeJeu()
{
}

const Niveau& TypeDeJeu::getNiveau()
{
    return *niveauDuJeu;
}

void TypeDeJeu::setNiveau(Niveau *newNiveau)
{
    niveauDuJeu = newNiveau;
}

