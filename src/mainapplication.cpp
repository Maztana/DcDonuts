#include "mainapplication.h"
#include "questionnaireeducatif.h"
#include "ressources.h"
#include <QtQml>

#include <QTextStream>

QQuickView* MainApplication::q_view = NULL;

/** Default constructor
 * @brief MainApplication::MainApplication
 * @param q_view the view of application
 */
MainApplication::MainApplication(QQuickView *q_view) :
    QObject(0), managerBDD(ManagerBdd::getInstance())
{

    bool isOpen = managerBDD.openDB();

    if(isOpen)
    {
        loadProfiles();
    }

    currentGame = 0;
    this->q_view = q_view;

}

/** Default destructor
 * @brief MainApplication::~MainApplication
 */
MainApplication::~MainApplication()
{
    if(currentGame != 0)
    {
        deleteGame();
    }
    qDeleteAll(profiles);

    //A vérifier
    delete(q_view);

    managerBDD.closeDB();
}

/** Load all profils from the data base
 * @brief MainApplication::loadProfils
 */
void MainApplication::loadProfiles()
{
    profiles=managerBDD.selectAllProfiles();

    if(profiles.size()<1)
    {
        // si aucun profil en BDD
        createProfile("François",0); //Profil par defaut
    }
    else
    {
        changeCurrentProfile(profiles.value(0)); // on prend le premier par défaut pour le moment
    }

}
/** Save profile and delete currentGame after
 * @brief MainApplication::deleteGame
 */
void MainApplication::deleteGame()
{ 
    managerBDD.updateProfile(*currentProfile);

    delete(currentGame);
}

/** Getter of actif profil's name
 * @brief MainApplication::getNameProfil
 * @return the name of actif profil
 */
const QString MainApplication::getNameProfile()const
{
    QString nameProfil = "undefined";
    if(currentProfile != 0)
    {
        nameProfil = currentProfile->getNom();
    }
    return nameProfil;
}

/**
 * @brief MainApplication::getAllId
 * @return all id of profiles
 */
const QList<int> MainApplication::getAllId() const
{
    QList<int> allId;

    for(int i = 0; i < profiles.size();i++){
        allId.append(profiles.value(i)->getId());
    }
    return allId;
}


/** Launcher of game
 * @brief MainApplication::lancerGame
 * @return if we have actif profil en game return true,
 *         else return false and no launch game.
 */
bool MainApplication::launchGame()
{
    if(currentProfile != 0)
    {
        if(currentGame != 0)
        {
            delete(currentGame);
        }
        currentGame = new Game(currentProfile);
        q_view->rootContext()->setContextProperty("game", currentGame);
        return true;
    }
    else {
        // ERREUR BESOIN DE SELECTION JOUEUR
        // OUVRIR SELECTION JOUEUR
        return false;
    }
}

/** Create a profil with a name
 * @brief MainApplication::createProfil
 * @param nom the name of new profil
 */
void MainApplication::createProfile(QString name,int score)
{
    Profil* newProfil;

    newProfil = managerBDD.insertProfile(name,score);

    profiles.append(newProfil);
    changeCurrentProfile(newProfil);
}

/** Change actif profil by the profil in parameter
 * @brief MainApplication::changeActifProfil
 * @param newProfilActif the new actif profil
 */
void MainApplication::changeCurrentProfile(Profil *newProfilActif)
{
    currentProfile = newProfilActif;
    emit nameProfileChanged();
}


/**
 * @brief MainApplication::getNameProfileById
 * @param id of the profile
 * @return the name of the profile selected by id
 */
QString MainApplication::getNameProfileById(int id)
{

    Profil* p=NULL;

    for(int i=0; i<profiles.size();i++){
        if(profiles.value(i)->getId()==id){
            p=profiles.value(i);
        }
    }

    return p->getNom();

}

/**
 * @brief MainApplication::getScoreProfileById
 * @param id of the profile
 * @return the score of the profile selected by id
 */
int MainApplication::getScoreProfileById(int id)
{

    Profil* p=NULL;

    for(int i=0; i<profiles.size();i++){
        if(profiles.value(i)->getId()==id){
            p=profiles.value(i);
        }
    }

    return p->getScore();

}

int MainApplication::getNbProfiles()
{
    return profiles.size();
}
