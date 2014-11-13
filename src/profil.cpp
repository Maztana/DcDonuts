#include "profil.h"

Profil::Profil(QString nom, QDate *dateDeNaissance) :
    QObject(0), nom(nom), dateDeNaissance(dateDeNaissance)
{
}

Profil::~Profil()
{
    delete(dateDeNaissance);
}

const QString Profil::getNom() const
{
    return nom;
}

const QDate* Profil::getDateDeNaissance()const
{
    return dateDeNaissance;
}
