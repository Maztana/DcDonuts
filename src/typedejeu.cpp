#include "typedejeu.h"
#include "ressources.h"

#include "addition.h"
#include "soustraction.h"
#include "division.h"
#include "multiplication.h"

int TypeDeJeu::INCREMENTAL_SCORE = 1;

TypeDeJeu::TypeDeJeu(Niveau* niveauDuJeu):
    QObject(0), niveauDuJeu(niveauDuJeu)
{
}

TypeDeJeu::~TypeDeJeu()
{
}

const Niveau& TypeDeJeu::getNiveau()
{
    return *niveauDuJeu;
}

TypeDeJeu* TypeDeJeu::makeTypeJeu(Niveau* niveauDeLaPartie, QString nameJeu)
{
    TypeDeJeu* typeActif;

    if(!nameJeu.compare(MODE_FLASHCARD))
    {
        typeActif = new Addition(niveauDeLaPartie);
    }
    else if(!nameJeu.compare(MODE_DENOMBREMENT))
    {
        typeActif = new Soustraction(niveauDeLaPartie);
    }
    else if(!nameJeu.compare(MODE_COULEUR))
    {
        typeActif = new Multiplication(niveauDeLaPartie);
    }
    else
    {
        typeActif = TypeDeJeu::makeTypeCalcul(niveauDeLaPartie, nameJeu);
    }
    return typeActif;
}

TypeDeJeu* TypeDeJeu::makeTypeCalcul(Niveau* niveauDeLaPartie, QString nameTypeJeu)
{
    TypeDeJeu* typeActif;

    if(!nameTypeJeu.compare(MODE_ADDITION))
    {
        typeActif = new Addition(niveauDeLaPartie);
    }
    else if(!nameTypeJeu.compare(MODE_SOUSTRACTION))
    {
        typeActif = new Soustraction(niveauDeLaPartie);
    }
    else if(!nameTypeJeu.compare(MODE_MULTIPLICATION))
    {
        typeActif = new Multiplication(niveauDeLaPartie);
    }
    else
    {
        typeActif = new Division(niveauDeLaPartie);
    }
    return typeActif;
}
