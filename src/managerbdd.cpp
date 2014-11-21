#include "managerbdd.h"
#include <QDir>
#include <QSqlQuery>
#include <QTextStream>
#include <QSqlError>

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
 * @return true if database is open, else return false
 */
bool ManagerBdd::openDB()
{
    // Find QSLite driver
    m_db = QSqlDatabase::addDatabase("QSQLITE");

#ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("drdonut.db.sqlite");
    path = QDir::toNativeSeparators(path);
    m_db.setDatabaseName(path);

    QTextStream(stdout) << path << endl;

#else
    // NOTE: File exists in the application private folder, in Symbian Qt implementation
    m_db.setDatabaseName("drdonut.db.sqlite");
#endif

    // Open database
    return m_db.open();
}

/** Close and Delete database
 * @brief ManagerBdd::deleteDB
 * @return true if database is delete, else return false
 */
bool ManagerBdd::deleteDB()
{
    m_db.close();

#ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("drdonut.db.sqlite");
    path = QDir::toNativeSeparators(path);
    return QFile::remove(path);
#else

    // Remove created database binary file
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
    query.exec("CREATE TABLE IF NOT EXISTS profil (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(20), score INTEGER)");

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

    query.exec("INSERT INTO profil(name,score) VALUES('"+name+"',"+QString::number(score)+")");
    query.exec("SELECT MAX(id) FROM profil");

    if(query.next()){
        lastId = query.value(0).toInt();
    }

    Profil* newProfil = new Profil(lastId,name,score);

    return newProfil;

}

/** Update a profile in database
 * @brief ManagerBdd::updateProfile
 * @param profil
 */
void ManagerBdd::updateProfile(Profil& profil) const
{

    createTables();

    QSqlQuery query(m_db);
    query.exec("UPDATE profil SET score="+QString::number(profil.getScore())+" WHERE id="+QString::number(profil.getId()));

}

/** Delete a profile in database
 * @brief ManagerBdd::deleteProfile
 * @param profil
 */
void ManagerBdd::deleteProfile(Profil& profil) const
{

    createTables();

    QSqlQuery query(m_db);
    query.exec("DELETE from profil WHERE id="+QString::number(profil.getId()));

}

/** Select all profiles which are in database and return them in a list
 * @brief ManagerBdd::selectAllProfiles
 * @return List of all profiles
 */
QList<Profil*> ManagerBdd::selectAllProfiles()
{
    QList<Profil*> lesProfils;

    int id;
    QString name;
    int score;

    QSqlQuery query(m_db);
    query.exec("SELECT * FROM profil");

    while(query.next()){

        id =query.value(0).toInt();
        name =query.value(1).toString();
        score =query.value(2).toInt();

        lesProfils.append(new Profil(id,name,score));
    }

    return lesProfils;
}

