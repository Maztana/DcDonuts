#include "managerbdd.h"
#include "ressources.h"
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

/////////////////////////
#include<QTextStream>
////////////////////////

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

/** Return ManagerBDD's instance
 * @brief ManagerBdd::getInstance
 * @return ManagerBdd instance
 */
ManagerBdd& ManagerBdd::getInstance()
{
    return s_instance;
}

/** Create and open sqlite database in /home/nemo/.local/share/harbour-dr-donut/
 * @brief ManagerBdd::openDB
 * @return true if database is open, else return false
 */
bool ManagerBdd::openDB()
{
    // Find QSLite driver
    m_db = QSqlDatabase::addDatabase("QSQLITE");

#ifdef Q_OS_LINUX
    QString path(QDir::home().path());
    path.append(QDir::separator()).append(".local");
    path.append(QDir::separator()).append("share");
    path.append(QDir::separator()).append("harbour-dr-donut");
    path = QDir::toNativeSeparators(path);

    QDir dir;
    dir.mkpath(path);

    path.append(QDir::separator()).append(PATH_DATA_BASE);
    path = QDir::toNativeSeparators(path);
    m_db.setDatabaseName(path);

#else
    m_db.setDatabaseName(PATH_DATA_BASE);
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
    QString path(QDir::home().path());
    path.append(QDir::separator()).append(".local");
    path.append(QDir::separator()).append("share");
    path.append(QDir::separator()).append("harbour-dr-donut");
    path.append(QDir::separator()).append(PATH_DATA_BASE);
    path = QDir::toNativeSeparators(path);
    return QFile::remove(path);
#else
    return QFile::remove(PATH_DATA_BASE);
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





//////////////////////////////////////

bool ManagerBdd::openDBFlashcard(QString nomfichier)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    QString path(QDir::home().path());
    path.append(QDir::separator()).append(".local");
    path.append(QDir::separator()).append("share");
    path.append(QDir::separator()).append("harbour-dr-donut");
    path = QDir::toNativeSeparators(path);

    path.append(QDir::separator()).append(nomfichier);
    path = QDir::toNativeSeparators(path);
    m_db.setDatabaseName(path);

    bool ok = m_db.open();

    QStringList listeTables = m_db.tables();

    for(int i=0; i<listeTables.count(); i++){
        QTextStream(stdout) << listeTables.value(i) << endl;
    }

    QSqlQuery query(m_db);
    query.exec("SELECT _id, question, answer FROM dict_tbl");

    while(query.next()){
        QTextStream(stdout) << query.value(0).toInt() << "  " << query.value(1).toString() << "  " << query.value(2).toString() << endl;
    }

    return ok;
}

//////////////////////////////////////
