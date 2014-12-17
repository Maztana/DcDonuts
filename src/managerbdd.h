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
    int getNbRowsTableLearn();


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


    bool openDBFlashcard(QString path);
    void closeDBFlashcard();
    void saveResultFlashcard(int id, int answer,int idProfile);
    void initLearnTable(int idProfile);
    QList<Question*> getFirstCards(int idProfile);
    QList<Question*> getOldCards(int idProfile);

    void deleteStatsFlashcardByProfile(int idProfile, QString fileName);
    void resetStatsFlashcardByProfile(int idProfile, QString fileName);

};

#endif // MANAGERBDD_H


