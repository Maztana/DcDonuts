#ifndef MANAGERBDD_H
#define MANAGERBDD_H
#include "profil.h"
#include <QSqlDatabase>

class ManagerBdd
{
private:

    /** Database Object */
    QSqlDatabase m_db;
    /** ManagerBdd instance */
    static ManagerBdd s_instance;


    explicit ManagerBdd();

public:
    ~ManagerBdd();
    static ManagerBdd& getInstance();

    bool openDB();
    bool deleteDB();
    void closeDB();


    void createTables() const;
    Profil* insertProfile(QString name, int score) const;
    void updateProfile(Profil& profile) const;
    void deleteProfile(Profil& profile) const;
    void resetProfile(Profil& profile) const;

    QList<Profil*> selectAllProfiles();

};

#endif // MANAGERBDD_H


