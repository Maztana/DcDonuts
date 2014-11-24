#include "managerbdd.h"
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>

#include <QTextStream>

// les ifdef proviennent du site http://developer.nokia.com/community/wiki/Creating_an_SQLite_database_in_Qt

//Variable statique
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


/**
 * @brief ManagerBdd::getInstance
 * @return ManagerBdd instance
 */
ManagerBdd& ManagerBdd::getInstance()
{
    return s_instance;
}


/** Create and open sqlite database
 * @brief ManagerBdd::openDB
 * @return if database is open return true, else return false
 */
bool ManagerBdd::openDB()
{
    // Find QSLite driver
    m_db = QSqlDatabase::addDatabase("QSQLITE");

#ifdef Q_OS_LINUX
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("drdonut.db.sqlite");
    path = QDir::toNativeSeparators(path);
    m_db.setDatabaseName(path);

    QTextStream(stdout) << path << endl;

#else
    m_db.setDatabaseName("drdonut.db.sqlite");
#endif

    // Open database
    return m_db.open();
}


/** Close and Delete database
 * @brief ManagerBdd::deleteDB
 * @return if database is delete true, else return false
 */
bool ManagerBdd::deleteDB()
{
    m_db.close();

#ifdef Q_OS_LINUX
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("drdonut.db.sqlite");
    path = QDir::toNativeSeparators(path);
    return QFile::remove(path);
#else
    return QFile::remove("drdonut.db.sqlite");
#endif
}


/** Close database
 * @brief ManagerBdd::closeDB
 */
void ManagerBdd::closeDB()
{
    m_db.close();
}


/** Create tables of database
 * @brief ManagerBdd::createTables
 */
void ManagerBdd::createTables()const
{

    QSqlQuery query(m_db);
    query.exec("CREATE TABLE IF NOT EXISTS profile (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(20), score INTEGER)");

    // AJOUTER TABLE QUESTION
}


/** Insert a new profile in database and return a profile object
 * @brief ManagerBdd::insertProfile
 * @param name of the player
 * @param score of the player
 * @return Profile
 */
Profil* ManagerBdd::insertProfile(QString name, int score) const
{
    int lastId=-1;

    createTables();

    QSqlQuery query(m_db);

    query.exec("INSERT INTO profile(name,score) VALUES('"+name+"',"+QString::number(score)+")");
    query.exec("SELECT MAX(id) FROM profile");

    if(query.next()){
        lastId = query.value(0).toInt();
    }

    Profil* newProfile = new Profil(lastId,name,score);

    return newProfile;

}


/** Update a profile in database
 * @brief ManagerBdd::updateProfile
 * @param profile
 */
void ManagerBdd::updateProfile(Profil& profile) const
{
    QSqlQuery query(m_db);
    query.exec("UPDATE profile SET score="+QString::number(profile.getScore())+" WHERE id="+QString::number(profile.getId()));
}


/** Delete a profile in database
 * @brief ManagerBdd::deleteProfile
 * @param profil
 */
void ManagerBdd::deleteProfile(Profil& profile) const
{
    QSqlQuery query(m_db);
    query.exec("DELETE from profile WHERE id="+QString::number(profile.getId()));
}


/** Reset score of a profile
 * @brief resetProfile
 * @param profile to reset
 */
void ManagerBdd::resetProfile(Profil& profile)const{

    QSqlQuery query(m_db);
    query.exec("UPDATE profile SET score=0 WHERE id="+QString::number(profile.getId()));

}


/** Select all profiles which are in database and return them in a list
 * @brief ManagerBdd::selectAllProfiles
 * @return List of all profiles
 */
QList<Profil*> ManagerBdd::selectAllProfiles()
{
    QList<Profil*> lesProfiles;

    int id;
    QString name;
    int score;

    QSqlQuery query(m_db);
    query.exec("SELECT * FROM profile");

    while(query.next()){

        id = query.value(0).toInt();
        name = query.value(1).toString();
        score = query.value(2).toInt();

        lesProfiles.append(new Profil(id,name,score));
    }

    return lesProfiles;
}

