#include "partie.h"
#include "mainapplication.h"
#include <QtQml>

//test
#include "addition.h"

Partie::Partie(Profil *profilJeu):
    QObject(0), profilActif(profilJeu)
{
    lancerJeu();
}

Partie::~Partie()
{
    delete(typeJeuActif);
    delete(niveauDeLaPartie);
}

void Partie::lancerJeu()
{
    //Implémentation en dur pour test
    setNiveauDeLaPartie(new Niveau());
    setTypeJeu(new Addition(niveauDeLaPartie));
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

void Partie::setTypeJeu(TypeDeJeu *typeJeu)
{
    typeJeuActif = typeJeu;

    if(typeJeuActif->isQuestionnaire())
    {
        MainApplication::q_view->rootContext()->setContextProperty("questionnaireEducatif", (QuestionnaireEducatif*)typeJeuActif);
    }
    else
    {
        // A VOIR
    }
}

void Partie::setNiveauDeLaPartie(Niveau *niveauPartie)
{
    niveauDeLaPartie = niveauPartie;
}
