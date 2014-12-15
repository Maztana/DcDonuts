#ifndef MANAGERBDD_H
#define MANAGERBDD_H
#include "profile.h"
#include <QSqlDatabase>
#include "question.h"

class ManagerBdd
{
private:

    /** Database Object */
    QSqlDatabase m_db;
    /** ManagerBdd instance */
    static ManagerBdd s_instance;
    /** DataBase flashcard */
    QSqlDatabase m_dbFlashcard;

    explicit ManagerBdd();


public:
    ~ManagerBdd();
    static ManagerBdd& getInstance();

    bool openDB();
    void closeDB();


    void createTables() const;
    Profile* insertProfile(QString name, int score) const;
    void updateProfile(Profile& profile) const;
    void deleteProfile(Profile& profile) const;
    void resetProfile(Profile& profile) const;

    QList<Profile*> selectAllProfiles();


    bool openDBFlashcard(QString fileName);
    void closeDBFlashcard();
    QList<Question*> loadDbFlashcard();
    void saveResultFlashcard(int id, int answer);
    void initLearnTable();
    QList<Question*> getFirstCards();
};

#endif // MANAGERBDD_H


