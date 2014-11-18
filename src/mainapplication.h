#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "partie.h"
#include <QQuickView>
#include <QGuiApplication>

class MainApplication : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString nameProfil READ getNameProfil NOTIFY nameProfilChanged)

    QList<Profil*> profils;
    Profil *profilActif;
    Partie *partieEnCours;

public:
    explicit MainApplication(QGuiApplication *q_application,QQuickView *q_view);
    ~MainApplication();

    static QGuiApplication *q_application;
    static QQuickView *q_view;

    //inline const Partie* getPartie()const{return partieEnCours;}
    inline const QString getNameProfil()const{return profilActif->getNom();}


signals:
    void nameProfilChanged();

public slots:
    void lancerPartie();
    void creerProfils(QString nom);
    void changerProfilActif(Profil *newProfilActif);

};

#endif // MAINAPPLICATION_H
