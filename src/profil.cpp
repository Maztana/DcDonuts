#include "profil.h"

Profil::Profil(QString nom, QDate *dateDeNaissance) :
    QObject(0), nom(nom), dateDeNaissance(dateDeNaissance)
{
}

Profil::~Profil()
{
    delete(dateDeNaissance);
}

QString Profil::getNom()
{
    return nom;
}

QDate* Profil::getDateDeNaissance()
{
    return dateDeNaissance;
}