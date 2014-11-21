#include "managerbdd.h"
#include <QDir>
#include <QSqlQuery>
#include <QTextStream>
#include <QSqlError>

// les ifdef proviennent du site http://developer.nokia.com/community/wiki/Creating_an_SQLite_database_in_Qt

//Variable statique
ManagerBdd ManagerBdd::instance= ManagerBdd();

ManagerBdd::ManagerBdd(){

}

ManagerBdd::~ManagerBdd(){

}

ManagerBdd& ManagerBdd::getInstance(){

    return instance;
}


bool ManagerBdd::openDB()
{
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");

#ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("drdonut.db.sqlite");
    path = QDir::toNativeSeparators(path);
    db.setDatabaseName(path);

    QTextStream(stdout) << path << endl;

#else
    // NOTE: File exists in the application private folder, in Symbian Qt implementation
    db.setDatabaseName("drdonut.db.sqlite");
#endif

    // Open database
    return db.open();
}


void ManagerBdd::closeDB()
{
    db.close();
}


void ManagerBdd::creerTables()const{

    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS profil (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(20), score INTEGER)");

    // AJOUTER TABLE QUESTION
}


void ManagerBdd::insererProfil(Profile& profil) const{

    creerTables();

    QSqlQuery query(db);

    query.exec("INSERT INTO profil(name,score) VALUES('"+profil.getName()+"',"+QString::number(profil.getScore())+")");

}

void ManagerBdd::modifierProfil(Profile& profil) const{

    creerTables();

    QSqlQuery query(db);
    query.exec("UPDATE profil SET score="+QString::number(profil.getScore())+" WHERE id="+QString::number(profil.getId()));

}

void ManagerBdd::supprimerProfil(Profile& profil) const{

    creerTables();

    QSqlQuery query(db);
    query.exec("DELETE from profil WHERE id="+QString::number(profil.getId()));

}

QList<Profile*> ManagerBdd::selectAllProfils(){
    QList<Profile*> lesProfils;

    int id;
    QString name;
    int score;

    QSqlQuery query(db);
    query.exec("SELECT * FROM profil");

    while(query.next()){

        id =query.value(0).toInt();
        name =query.value(1).toString();
        score =query.value(2).toInt();

        lesProfils.append(new Profile(id,name,score));
    }

    return lesProfils;
}

