#include "mainapplication.h"
#include "questionnaireeducatif.h"
#include "ressources.h"
#include <QtQml>

#include <QTextStream>

QQuickView* MainApplication::s_view = NULL;

/** Default constructor
 * @brief MainApplication::MainApplication
 * @param q_view the view of application
 */
MainApplication::MainApplication(QQuickView *q_view) :
    QObject(0), m_managerBDD(ManagerBdd::getInstance())
{
    loadProfiles();
    m_currentGame = 0;
    this->s_view = q_view;
}

/** Default destructor
 * @brief MainApplication::~MainApplication
 */
MainApplication::~MainApplication()
{
    if(m_currentGame != 0)
    {
        delete(m_currentGame);
    }
    qDeleteAll(m_profiles);

    //A vérifier
    delete(s_view);
}

/** Load all profils from the data base
 * @brief MainApplication::loadProfils
 */
void MainApplication::loadProfiles()
{
    bool isOpen = m_managerBDD.openDB();

    if(isOpen)
    {
        m_profiles=m_managerBDD.selectAllProfils();

        if(m_profiles.size()<1)
        {
            // si aucun profil en BDD
            //Profil par defaut
            createProfile("François");
        }
        else
        {
            changeCurrentProfile(m_profiles.value(0)); // on prend le premier par défaut pour le moment
        }
    }
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

/** Launcher of game
 * @brief MainApplication::lancerGame
 * @return if we have actif profil en game return true,
 *         else return false and no launch game.
 */
bool MainApplication::launchGame()
{
    if(m_currentProfile != 0)
    {
        if(m_currentGame != 0)
        {
            delete(m_currentGame);
        }
        m_currentGame = new Game(m_currentProfile);
        s_view->rootContext()->setContextProperty("game", m_currentGame);
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
void MainApplication::createProfile(QString name)
{
    Profile *newProfil = new Profile(0, name, 0);
    m_profiles.append(newProfil);

    changeCurrentProfile(newProfil);
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
