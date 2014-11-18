#include "profil.h"

Profil::Profil(QString nom) :
    QObject(0), nom(nom)
{
    score = 0;
}

Profil::~Profil()
{

}

const QString Profil::getNom() const
{
    return nom;
}

int Profil::getScore()const
{
    return score;
}

void Profil::incrementScore(int nbPoints){
    score+=nbPoints;
}

