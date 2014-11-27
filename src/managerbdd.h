#ifndef MANAGERBDD_H
#define MANAGERBDD_H
#include "profile.h"
#include <QSqlDatabase>

////////////////////////////////////////////////////////////////////////////////////////
///a envisager: Table config qui garde la langue et le current profile
///////////////////////////////////////////////////////////////////////////////////////

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
    void resetProfile(Profile& profile) const;

    QList<Profile*> selectAllProfiles();

};

#endif // MANAGERBDD_H


