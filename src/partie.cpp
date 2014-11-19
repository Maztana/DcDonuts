#include "partie.h"
#include "mainapplication.h"
#include "Ressources.h"
#include <QtQml>

#include <QTextStream>

#include "addition.h"
#include "soustraction.h"
#include "division.h"
#include "multiplication.h"

Partie::Partie(Profil *profilJeu):
    QObject(0), profilActif(profilJeu)
{
    typeJeuActif = 0;
    niveauDeLaPartie = 0;
    //lancerJeu();
}

Partie::~Partie()
{
    QTextStream(stdout) << "Enregistrement du profil" << endl;
    if(typeJeuActif != 0)
    {
        delete(typeJeuActif);
    }
    delete(niveauDeLaPartie);
}

void Partie::lancerJeu()
{
    //Implémentation en dur pour test
    setNiveauDeLaPartie(new Niveau());
    ///////////////////////////////////////////

    if(typeJeuActif != 0 && niveauDeLaPartie != 0)
    {
        typeJeuActif->lancerJeu();
    }
}

void Partie::setProfilPartie(Profil *profilJeu)
{
    profilActif = profilJeu;
}

void Partie::initTypeJeu(QString nameTypeJeu)
{
    if(typeJeuActif != 0)
    {
        delete(typeJeuActif);
    }

    if(!nameTypeJeu.compare(MODE_ADDITION))
    {
        setTypeJeu(new Addition(niveauDeLaPartie));
    }
    else if(!nameTypeJeu.compare(MODE_SOUSTRACTION))
    {
        setTypeJeu(new Soustraction(niveauDeLaPartie));
    }
    else if(!nameTypeJeu.compare(MODE_MULTIPLICATION))
    {
        setTypeJeu(new Multiplication(niveauDeLaPartie));
    }
    else if(!nameTypeJeu.compare(MODE_DIVISION))
    {
        setTypeJeu(new Division(niveauDeLaPartie));
    }

    connect(typeJeuActif, SIGNAL(incrementScore(int)), this,SLOT(scoreIncrement(int)));
}

void Partie::setTypeJeu(TypeDeJeu *typeJeu)
{
    typeJeuActif = typeJeu;

    if(typeJeuActif->isQuestionnaire())
    {
        MainApplication::q_view->rootContext()->setContextProperty("questionnaireEducatif", (QuestionnaireEducatif*)typeJeuActif);
    }
    else
    {
        // A VOIR pour le jeu supplémentaire
    }
}

void Partie::setNiveauDeLaPartie(Niveau *niveauPartie)
{
    niveauDeLaPartie = niveauPartie;
    emit niveauChanged();
}

void Partie::scoreIncrement(int nbPoints){
    profilActif->incrementScore(nbPoints);
    emit scoreChanged();
}
