#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "partie.h"

class MainApplication : public QObject
{
    Q_OBJECT

    QList<Profil*> profils;
    Profil *profilActif;
    Partie *partieEnCours;

public:
    explicit MainApplication(QObject *parent = 0);
    ~MainApplication();

    //test
    inline Partie* getPartie(){return partieEnCours;}
    //

signals:

public slots:
    void lancerPartie();
    void creerProfils(QString nom, QDate* date);
    void changerProfilActif(Profil *newProfilActif);

};

#endif // MAINAPPLICATION_H
