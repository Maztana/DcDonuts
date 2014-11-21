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
    loadProfiles();
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
        delete(currentGame);
    }
    qDeleteAll(profiles);

    //A vérifier
    delete(q_view);
}

/** Load all profils from the data base
 * @brief MainApplication::loadProfils
 */
void MainApplication::loadProfiles()
{
    bool isOpen = managerBDD.openDB();

    if(isOpen)
    {
        profiles=managerBDD.selectAllProfils();

        if(profiles.size()<1)
        {
            // si aucun profil en BDD
            //Profil par defaut
            createProfile("François");
        }
        else
        {
            changeCurrentProfile(profiles.value(0)); // on prend le premier par défaut pour le moment
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
    if(currentProfile != 0)
    {
        nameProfil = currentProfile->getNom();
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
void MainApplication::createProfile(QString name)
{
    Profil *newProfil = new Profil(name);
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
