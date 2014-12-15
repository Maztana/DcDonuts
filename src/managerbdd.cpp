#include "managerbdd.h"
#include "ressources.h"
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

// les ifdef proviennent du site http://developer.nokia.com/community/wiki/Creating_an_SQLite_database_in_Qt
ManagerBdd ManagerBdd::s_instance= ManagerBdd();

/** Default constructor
 * @brief ManagerBdd::ManagerBdd
 */
ManagerBdd::ManagerBdd()
{
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


/** Load all question of a db of flashcard
 * @brief ManagerBdd::loadDbFlashcard
 * @param fileName name of the database
 * @return list of question of a flashcard database
 */
QList<Question*> ManagerBdd::loadDbFlashcard(QString fileName)
{
    closeDBFlashcard();

    QList<Question*> listCards;
    openDBFlashcard(fileName);
    QSqlQuery query(m_dbFlashcard);
    query.exec("SELECT _id, question, answer FROM dict_tbl");

    while(query.next()){
        listCards.append(new Question({query.value("answer").toString()},
                                      query.value("question").toString(),
                                      query.value("_id").toInt()));
    }

    return listCards;
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
