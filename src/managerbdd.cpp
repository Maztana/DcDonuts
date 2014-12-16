#include "managerbdd.h"
#include "ressources.h"
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDateTime>

// les ifdef proviennent du site http://developer.nokia.com/community/wiki/Creating_an_SQLite_database_in_Qt
ManagerBdd ManagerBdd::s_instance= ManagerBdd();

/** Default constructor
 * @brief ManagerBdd::ManagerBdd
 */
ManagerBdd::ManagerBdd()
{
}

/** Get number of rows in learn_tbl
 * @brief ManagerBdd::getNbRowsTableLearn
 * @return number of row in table learn_tbl
 */
int ManagerBdd::getNbRowsTableLearn()
{
    int nbRows = 0;

    QSqlQuery queryCount(m_dbFlashcard);
    queryCount.exec("SELECT COUNT(*) FROM learn_tbl");

    if(queryCount.next()){
        nbRows = queryCount.value(0).toInt();
    }
    return nbRows;
}

/** Default destructor
 * @brief ManagerBdd::~ManagerBdd
 */
ManagerBdd::~ManagerBdd()
{
}

/** Return ManagerBDD's instance
 * @brief ManagerBdd::getInstance
 * @return ManagerBdd instance
 */
ManagerBdd& ManagerBdd::getInstance()
{
    return s_instance;
}

/** Create and open sqlite database in /home/nemo/.config/harbour-dr-donut/
 * @brief ManagerBdd::openDB
 * @return true if database is open, else return false
 */
bool ManagerBdd::openDB()
{
    // Find QSLite driver
    if(QSqlDatabase::contains(CONNECTION_NAME_PROFILES))
    {
        m_db = QSqlDatabase::database(CONNECTION_NAME_PROFILES);
    }
    else
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE", CONNECTION_NAME_PROFILES);
    }

#ifdef Q_OS_LINUX
    QString path(PATH_CONFIG);
    path = QDir::toNativeSeparators(path);

    QDir dir;
    dir.mkpath(path);

    path.append(QDir::separator()).append(NAME_DATA_BASE);
    path = QDir::toNativeSeparators(path);
    m_db.setDatabaseName(path);

#else
    m_db.setDatabaseName(NAME_DATA_BASE);
#endif

    // Open database
    return m_db.open();
}

/** Close database
 * @brief ManagerBdd::closeDB
 */
void ManagerBdd::closeDB()
{
    m_db.close();
    m_db = QSqlDatabase();
    QSqlDatabase::removeDatabase(m_db.connectionName());
}

/** Create tables of database
 * @brief ManagerBdd::createTables
 */
void ManagerBdd::createTables()const
{

    QSqlQuery query(m_db);
    query.exec("CREATE TABLE IF NOT EXISTS profile (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(20), score INTEGER)");

}

/** Insert a new profile in database and return a profile object
 * @brief ManagerBdd::insertProfile
 * @param name of the player
 * @param score of the player
 * @return Profile
 */
Profile* ManagerBdd::insertProfile(QString name, int score) const
{
    int lastId=-1;
    createTables();

    QSqlQuery query(m_db);

    query.exec("INSERT INTO profile(name,score) VALUES('"+name+"',"+QString::number(score)+")");
    query.exec("SELECT MAX(id) FROM profile");

    if(query.next()){
        lastId = query.value(0).toInt();
    }

    Profile* newProfile = new Profile(lastId,name,score);

    return newProfile;

}

/** Update a profile in database
 * @brief ManagerBdd::updateProfile
 * @param profile
 */
void ManagerBdd::updateProfile(Profile& profile) const
{
    QSqlQuery query(m_db);
    query.exec("UPDATE profile SET score="+QString::number(profile.getScore())+" WHERE id="+QString::number(profile.getId()));
}

/** Delete a profile in database
 * @brief ManagerBdd::deleteProfile
 * @param profile
 */
void ManagerBdd::deleteProfile(Profile& profile) const
{
    QSqlQuery query(m_db);
    query.exec("DELETE from profile WHERE id="+QString::number(profile.getId()));
}


/** Reset score of a profile
 * @brief resetProfile
 * @param profile to reset
 */
void ManagerBdd::resetProfile(Profile& profile)const{

    QSqlQuery query(m_db);
    query.exec("UPDATE profile SET score=0 WHERE id="+QString::number(profile.getId()));

}

/** Select all profiles which are in database and return them in a list
 * @brief ManagerBdd::selectAllProfiles
 * @return List of all profiles
 */
QList<Profile*> ManagerBdd::selectAllProfiles()
{
    QList<Profile*> listProfiles;

    int id;
    QString name;
    int score;

    QSqlQuery query(m_db);
    query.exec("SELECT * FROM profile");

    while(query.next()){

        id = query.value(0).toInt();
        name = query.value(1).toString();
        score = query.value(2).toInt();

        listProfiles.append(new Profile(id,name,score));
    }

    return listProfiles;
}


/** Open a db of flashcards
 * @brief ManagerBdd::openDBFlashcard
 * @param fileName name of the db
 * @return true is db is open else return false
 */
bool ManagerBdd::openDBFlashcard(QString fileName)
{
    if(QSqlDatabase::contains(CONNECTION_NAME_FLASHCARDS))
    {
        m_dbFlashcard = QSqlDatabase::database(CONNECTION_NAME_FLASHCARDS);
    }
    else
    {
        m_dbFlashcard = QSqlDatabase::addDatabase("QSQLITE", CONNECTION_NAME_FLASHCARDS);
    }

    QString path(PATH_LOCAL);
    path = QDir::toNativeSeparators(path);

    path.append(QDir::separator()).append(fileName);
    path = QDir::toNativeSeparators(path);
    m_dbFlashcard.setDatabaseName(path);

    return m_dbFlashcard.open();
}


/** Close Flashcard database
 * @brief ManagerBdd::closeDBFlashcard
 */
void ManagerBdd::closeDBFlashcard()
{
    m_dbFlashcard.close();
    m_dbFlashcard = QSqlDatabase();
    QSqlDatabase::removeDatabase(m_dbFlashcard.connectionName());
}


/** Save the answer of a flashcard question.
 * @brief ManagerBdd::saveResultFlashcard
 * @param fileName name of the database file
 * @param id of the question
 * @param answer that the player have selected
 */
void ManagerBdd::saveResultFlashcard(int id, int answer)
{
    QDateTime date = QDateTime::currentDateTimeUtc();

    QSqlQuery query(m_dbFlashcard);
    query.exec("SELECT * FROM learn_tbl WHERE _id="+QString::number(id));

    if(query.next()){

        int nbAnswers=0;
        double ratio=0;
        int lastGrade = 0;

        QSqlQuery queryBis(m_dbFlashcard);
        queryBis.exec("SELECT acq_reps, easiness, grade FROM learn_tbl WHERE _id="+QString::number(id));

        if(queryBis.next()){
            nbAnswers = queryBis.value("acq_reps").toInt();
            ratio = queryBis.value("easiness").toDouble();
            lastGrade = queryBis.value("grade").toInt();

            nbAnswers++;

            ratio += answer + lastGrade;
            ratio /= nbAnswers + 1;

            query.exec("UPDATE learn_tbl SET date_learn='"+date.toString()+"',acq_reps="+QString::number(nbAnswers)+",easiness="+QString::number(ratio)+" WHERE _id="+QString::number(id));
        }
    }
    else{
        query.exec("INSERT INTO learn_tbl(_id, date_learn, easiness, grade, acq_reps) VALUES("+QString::number(id)+",'"+date.toString()+"',"+QString::number(answer)+","+QString::number(answer)+",1)");
    }

}

/** Filling the learn_tbl with all questions and default values
 * @brief ManagerBdd::initLearnTable
 */
void ManagerBdd::initLearnTable()
{

    QSqlQuery query(m_dbFlashcard);
    query.exec("SELECT _id FROM dict_tbl");


    QSqlQuery queryInsert(m_dbFlashcard);

    while(query.next()){
        queryInsert.exec("INSERT INTO learn_tbl(_id, easiness, grade, acq_reps) VALUES("+QString::number(query.value(0).toInt())+",1.5,0,0)");
    }
}



/** Return a list which contains 1/3 of all questions which are sorted by easiness
 * @brief ManagerBdd::getFirstCards
 * @return list of question cards
 */
QList<Question*> ManagerBdd::getFirstCards()
{
    QList<Question*> cards;

    int nbRows = getNbRowsTableLearn();

    QSqlQuery query(m_dbFlashcard);
    query.exec("SELECT dict_tbl._id, question, answer FROM dict_tbl, learn_tbl WHERE dict_tbl._id = learn_tbl._id ORDER BY easiness");

    int cpt = 0;

    while(query.next() && (cpt < (nbRows/3))){
        cpt++;
        cards.append(new Question({query.value("answer").toString()},
                                      query.value("question").toString(),
                                      query.value("_id").toInt()));
    }

    return cards;
}

/** Return a list which contains 2/3 of all questions which are sorted by date_learn
 * @brief ManagerBdd::getOldCards
 * @return list of question cards
 */
QList<Question*> ManagerBdd::getOldCards()
{
    QList<Question*> cards;

    int nbRows = getNbRowsTableLearn();

    QSqlQuery query(m_dbFlashcard);
    query.exec("SELECT dict_tbl._id, question, answer FROM dict_tbl, learn_tbl WHERE dict_tbl._id = learn_tbl._id ORDER BY date_learn");

    int cpt = 0;

    while(query.next() && (cpt < (nbRows/3)*2)){
        cpt++;
        cards.append(new Question({query.value("answer").toString()},
                                      query.value("question").toString(),
                                      query.value("_id").toInt()));
    }

    return cards;
}


