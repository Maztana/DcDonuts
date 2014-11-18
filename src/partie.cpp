#include "partie.h"
#include "mainapplication.h"
#include <QtQml>

#include <QTextStream>

//test
#include "addition.h"

Partie::Partie(Profil *profilJeu):
    QObject(0)
{
    setProfilPartie(profilJeu);

    //Implémentation en dur pour test
    setNiveauDeLaPartie(new Niveau());
    setTypeJeu(new Addition(niveauDeLaPartie));

    connect(typeJeuActif, SIGNAL(incrementScore(int)), this,SLOT(scoreIncrement(int)));

    if(typeJeuActif->isQuestionnaire())
    {
        MainApplication::q_view->rootContext()->setContextProperty("questionnaireEducatif", (QuestionnaireEducatif*)typeJeuActif);
    }
    else
    {
        // A VOIR
    }

    lancerJeu();
}

Partie::~Partie()
{
    QTextStream(stdout) << "Enregistrement du profil" << endl;
    delete(typeJeuActif);
    delete(niveauDeLaPartie);
}

void Partie::lancerJeu()
{
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
