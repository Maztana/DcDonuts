#ifndef MANAGERBDD_H
#define MANAGERBDD_H
#include "profile.h"
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
    Profile* insertProfile(QString name, int score) const;
    void updateProfile(Profile& profile) const;
    void deleteProfile(Profile& profile) const;

    QList<Profile*> selectAllProfiles();

};

#endif // MANAGERBDD_H


