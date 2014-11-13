#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "partie.h"
#include <QQuickView>

class MainApplication : public QObject
{
    Q_OBJECT

    //Q_PROPERTY(Partie partie READ getPartie)
    Q_PROPERTY(QString nameProfil READ getNameProfil)



    QList<Profil*> profils;
    Profil *profilActif;
    Partie *partieEnCours;

public:
    explicit MainApplication(QQuickView *q_view);
    ~MainApplication();

    static QQuickView *q_view;

    //inline const Partie* getPartie()const{return partieEnCours;}
    inline const QString getNameProfil()const{return profilActif->getNom();}


signals:

public slots:
    void lancerPartie();
    void creerProfils(QString nom, QDate* date);
    void changerProfilActif(Profil *newProfilActif);

};

#endif // MAINAPPLICATION_H
