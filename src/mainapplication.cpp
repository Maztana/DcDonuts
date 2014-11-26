#include "mainapplication.h"
#include "educationalquiz.h"
#include "ressources.h"
#include <QtQml>

QQuickView* MainApplication::s_view = NULL;

/** Default constructor
 * @brief MainApplication::MainApplication
 * @param q_view the view of application
 */
MainApplication::MainApplication(QQuickView *q_view) :
    QObject(0), m_managerBDD(ManagerBdd::getInstance())
{
    if(m_managerBDD.openDB())
    {
        loadProfiles();
    }

    m_currentGame = 0;
    this->s_view = q_view;

}

/** Default destructor
 * @brief MainApplication::~MainApplication
 */
MainApplication::~MainApplication()
{
    deleteGame();
    qDeleteAll(m_profiles);
    delete(s_view);
    m_managerBDD.closeDB();
}

/** Load all profils from the data base
 * @brief MainApplication::loadProfils
 */
void MainApplication::loadProfiles()
{
    m_profiles = m_managerBDD.selectAllProfiles();

    if(m_profiles.size()<1)
    {
        createProfile("François",0); //Profil par defaut
    }
    else
    {
        changeCurrentProfile(m_profiles.value(0)); // on prend le premier par défaut pour le moment
    }

}
/** Save profile and delete currentGame after
 * @brief MainApplication::deleteGame
 */
void MainApplication::deleteGame()
{ 
    m_managerBDD.updateProfile(*m_currentProfile);
    delete(m_currentGame);
}

/** Getter of actif profil's name
 * @brief MainApplication::getNameProfil
 * @return the name of actif profil
 */
const QString MainApplication::getNameProfile()const
{
    QString nameProfil = "undefined";
    if(m_currentProfile != 0)
    {
        nameProfil = m_currentProfile->getName();
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

    for(int i = 0; i < m_profiles.size();i++){
        allId.append(m_profiles.value(i)->getId());
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
    if(m_currentProfile != 0)
    {
        delete(m_currentGame);
        m_currentGame = new Game(m_currentProfile);
        s_view->rootContext()->setContextProperty("game", m_currentGame);
        return true;
    }
    return false;
}

/** Create a profil with a name
 * @brief MainApplication::createProfil
 * @param nom the name of new profil
 */
void MainApplication::createProfile(QString name,int score)
{
    Profile* newProfile;

    newProfile = m_managerBDD.insertProfile(name,score);
    m_profiles.append(newProfile);
    changeCurrentProfile(newProfile);
}

/** Change actif profil by the profil in parameter
 * @brief MainApplication::changeActifProfil
 * @param newProfilActif the new actif profil
 */
void MainApplication::changeCurrentProfile(Profile *newProfilActif)
{
    m_currentProfile = newProfilActif;
    emit nameProfileChanged();
}


/**
 * @brief MainApplication::getNameProfileById
 * @param id of the profile
 * @return the name of the profile selected by id
 */
QString MainApplication::getNameProfileById(int id)
{

    Profile* p = NULL;

    for(int i=0; i<m_profiles.size();i++){
        if(m_profiles.value(i)->getId()==id){
            p = m_profiles.value(i);
        }
    }
    return p->getName();
}

/**
 * @brief MainApplication::getScoreProfileById
 * @param id of the profile
 * @return the score of the profile selected by id
 */
int MainApplication::getScoreProfileById(int id)
{

    Profile* p = NULL;

    for(int i=0; i<m_profiles.size();i++){
        if(m_profiles.value(i)->getId()==id){
            p = m_profiles.value(i);
        }
    }

    return p->getScore();

}

int MainApplication::getNbProfiles()
{
    return m_profiles.size();
}
