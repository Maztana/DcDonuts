#include "profil.h"

Profil::Profil(QString nom) :
    QObject(0), nom(nom)
{
    score = 0;
}
Profil::Profil(int id, QString name, int score){
    this->id=id;
    this->nom=name;
    this->score=score;
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

