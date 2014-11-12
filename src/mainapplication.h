#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "partie.h"

class MainApplication : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Partie partie READ partie)
    Q_PROPERTY(QString nameProfil READ nameProfil)
    Q_PROPERTY(QString niveau READ nameNiveau)

    Q_PROPERTY(bool runPartie READ runPartie WRITE setRunPartie NOTIFY runPartieChanged)

    QList<Profil*> profils;
    Profil *profilActif;
    Partie *partieEnCours;
    bool isPartieRunning;

public:
    explicit MainApplication();
    ~MainApplication();

    const Partie* partie() const;
    const QString nameProfil() const;
    const QString nameNiveau() const;

    bool runPartie();
    void setRunPartie(bool isRunPartie);

    //test
    inline Partie* getPartie(){return partieEnCours;}
    //

signals:
    void runPartieChanged();

public slots:
    void lancerPartie();
    void creerProfils(QString nom, QDate* date);
    void changerProfilActif(Profil *newProfilActif);

};

#endif // MAINAPPLICATION_H
