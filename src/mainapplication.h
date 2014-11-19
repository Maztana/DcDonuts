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

    const QString getNameProfil()const;

signals:
    void nameProfilChanged();

public slots:
    bool lancerPartie();
    void creerProfils(QString nom);
    void changerProfilActif(Profil *newProfilActif);

};

#endif // MAINAPPLICATION_H
