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
    QObject(0)
{
    QTextStream(stdout) << "Charger les profils" << endl;

    this->q_view = q_view;
    /*this->q_application = q_application;*/

    //Profil par defaut
    createProfil("François");
    playingGame = 0;
}

/** Default destructor
 * @brief MainApplication::~MainApplication
 */
MainApplication::~MainApplication()
{
    if(playingGame != 0)
    {
        delete(playingGame);
    }
    qDeleteAll(profils);

    //A vérifier
    delete(q_view);
}

/** Getter of actif profil's name
 * @brief MainApplication::getNameProfil
 * @return the name of actif profil
 */
const QString MainApplication::getNameProfil()const
{
    QString nameProfil = "undefined";
    if(profilActif != 0)
    {
        nameProfil = profilActif->getNom();
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
    if(profilActif != 0)
    {
        if(playingGame != 0)
        {
            delete(playingGame);
        }
        playingGame = new Game(profilActif);
        q_view->rootContext()->setContextProperty("game", playingGame);
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
void MainApplication::createProfil(QString name)
{
    Profil *newProfil = new Profil(name);
    profils.append(newProfil);

    changeActifProfil(newProfil);
}

/** Change actif profil by the profil in parameter
 * @brief MainApplication::changeActifProfil
 * @param newProfilActif the new actif profil
 */
void MainApplication::changeActifProfil(Profil *newProfilActif)
{
    profilActif = newProfilActif;
    emit nameProfilChanged();
}
