#include "profil.h"

Profil::Profil(QString nom, QDate *dateDeNaissance) :
    QObject(0), nom(nom), dateDeNaissance(dateDeNaissance)
{
}

QString Profil::getNom()
{
    return nom;
}

QDate* Profil::getDateDeNaissance()
{
    return dateDeNaissance;
}
