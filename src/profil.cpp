#include "profil.h"

Profil::Profil(int id, QString name, int score):
    id(id), nom(name), score(score)
{

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

int Profil::getId()const{
    return id;
}

void Profil::incrementScore(int nbPoints){
    score+=nbPoints;
}

