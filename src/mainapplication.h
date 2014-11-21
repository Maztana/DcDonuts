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
    Game *playingGame;

public:
    explicit MainApplication(QQuickView *q_view);
    ~MainApplication();

    static QQuickView *q_view;

    const QString getNameProfil()const;

signals:
    void nameProfilChanged();

public slots:
    bool launchGame();
    void createProfil(QString nom);
    void changeActifProfil(Profil *newProfilActif);

};

#endif // MAINAPPLICATION_H
