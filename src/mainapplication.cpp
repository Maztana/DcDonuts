#include "mainapplication.h"
#include "educationalquiz.h"
#include "ressources.h"
#include <QtQml>
#include "jsonmanager.h"

QQuickView* MainApplication::s_view = nullptr;
Profile* MainApplication::s_defaultProfile = new Profile(-1, "", 0);

/** Default constructor
 * @brief MainApplication::MainApplication
 * @param q_view the view of application
 */
MainApplication::MainApplication(QQuickView *q_view) :
    QObject(0), m_managerBDD(ManagerBdd::getInstance())
{
    this->s_view = q_view;
    changeCurrentProfile(s_defaultProfile);
    m_currentGame = nullptr;

    if(m_managerBDD.openDB())
    {
        loadProfiles();
    }

    loadCurrentProfile();
}

/** Default destructor
 * @brief MainApplication::~MainApplication
 */
MainApplication::~MainApplication()
{
    JsonManager::getInstance().saveConfig(m_currentProfile->getId(),"fr");
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
}
/** Save profile and delete currentGame after
 * @brief MainApplication::deleteGame
 */
void MainApplication::deleteGame()
{ 
    m_managerBDD.updateProfile(*m_currentProfile);
    delete(m_currentGame);
}


/** Load all configurations which are save in a json file
 * @brief MainApplication::loadConfigurations
 */
void MainApplication::loadCurrentProfile()
{
    int saveid = JsonManager::getInstance().getIdProfile();

    bool isInProfiles = false;

    for(int i=0; i<m_profiles.size();i++){
        if(m_profiles.value(i)->getId()==saveid)
        {
            isInProfiles = true;
        }
    }

    if(isInProfiles)
    {
        changeCurrentProfile(saveid);
    }
}


/** Getter of actif profil's name
 * @brief MainApplication::getNameProfil
 * @return the name of actif profil
 */
const QString MainApplication::getNameProfile()const
{
    return m_currentProfile->getName();
}

/** List all of profiles id available
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
 * @brief MainApplication::launchGame
 * @return if we have actif profil en game return true,
 *         else return false and no launch game.
 */
bool MainApplication::launchGame()
{
    if(m_currentProfile != s_defaultProfile)
    {
        delete(m_currentGame);
        m_currentGame = new Game(m_currentProfile);
        s_view->rootContext()->setContextProperty("game", m_currentGame);
        return true;
    }
    return false;
}

/** Create a profil with a name and a score. The default value for score is 0
 * @brief MainApplication::createProfile
 * @param name the name of new profile
 * @param score of the profile
 */
void MainApplication::createProfile(QString name,int score)
{
    Profile* newProfile;

    newProfile = m_managerBDD.insertProfile(name,score);
    m_profiles.append(newProfile);
    changeCurrentProfile(newProfile);
}

/** Change active profile by the profile in parameter
 * @brief MainApplication::changeActifProfil
 * @param newProfilActif the new actif profil
 */
void MainApplication::changeCurrentProfile(Profile *newProfilActif)
{
    m_currentProfile = newProfilActif;
    s_view->rootContext()->setContextProperty("currentProfile", m_currentProfile);
    m_currentProfile->profileChanged();
}

/** Change active profile by the profile which have is id in parameter
 * @brief MainApplication::changeCurrentProfile
 * @param id of the new current profile
 */
void MainApplication::changeCurrentProfile(int id){

    changeCurrentProfile(getProfileById(id));
}

/** Get a profile which is selected by is id
 * @brief MainApplication::getProfileById
 * @param id of the profile
 * @return profile
 */
Profile* MainApplication::getProfileById(int id)
{
    Profile* p=nullptr;

    for(int i=0; i<m_profiles.size();i++){
        if(m_profiles.value(i)->getId()==id){
            p=m_profiles.value(i);
        }
    }
    return p;
}

/**
 * @brief MainApplication::getNameProfileById
 * @param id of the profile
 * @return the name of the profile selected by id
 */
QString MainApplication::getNameProfileById(int id)
{
    Profile* p = nullptr;

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
    Profile* p = nullptr;

    for(int i=0; i<m_profiles.size();i++){
        if(m_profiles.value(i)->getId()==id){
            p = m_profiles.value(i);
        }
    }
    return p->getScore();
}

/**
 * @brief MainApplication::getNbProfiles
 * @return number of available profiles
 */
int MainApplication::getNbProfiles()
{
    return m_profiles.size();
}

/** Reset score and stats of a profile
 * @brief MainApplication::resetProfile
 * @param id of the profile to reset
 */
void MainApplication::resetProfile(int id)
{
    Profile* p = getProfileById(id);
    m_managerBDD.resetProfile(*p);
    p->resetScore();
}


/** Delete one profile and after put the first profile in current profile
 * @brief MainApplication::deleteProfile
 * @param id of the profile to delete
 */
void MainApplication::deleteProfile(int id)
{
    Profile* profileDeleted = m_profiles.takeAt(m_profiles.indexOf(getProfileById(id)));
    m_managerBDD.deleteProfile(*profileDeleted);

    if(profileDeleted == m_currentProfile)
    {
        delete(m_currentProfile);
        changeCurrentProfile(s_defaultProfile);
    }
    else
    {
        delete(profileDeleted);
    }
}
