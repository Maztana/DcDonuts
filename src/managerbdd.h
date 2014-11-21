#ifndef MANAGERBDD_H
#define MANAGERBDD_H
#include "profil.h"
#include <QSqlDatabase>

class ManagerBdd
{
private:
    QSqlDatabase db;
    static ManagerBdd instance;
    explicit ManagerBdd();

public:
    ~ManagerBdd();
    static ManagerBdd& getInstance();

    bool openDB();
    void closeDB();


    void creerTables() const;

    void insererProfil(Profil& profil) const;
    void modifierProfil(Profil& profil) const;
    void supprimerProfil(Profil& profil) const;

    QList<Profil*> selectAllProfils();

};

#endif // MANAGERBDD_H


