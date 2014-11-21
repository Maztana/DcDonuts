#ifndef MANAGERBDD_H
#define MANAGERBDD_H
#include "profile.h"
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

    void insererProfil(Profile& profil) const;
    void modifierProfil(Profile& profil) const;
    void supprimerProfil(Profile& profil) const;

    QList<Profile*> selectAllProfils();

};

#endif // MANAGERBDD_H


