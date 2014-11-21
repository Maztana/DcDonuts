#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "partie.h"
#include "managerbdd.h"
#include <QQuickView>
#include <QGuiApplication>

class MainApplication : public QObject
{
    Q_OBJECT

    /** Name profil property */
    Q_PROPERTY(QString nameProfile READ getNameProfile NOTIFY nameProfileChanged)

    /** List all profiles */
    QList<Profil*> profiles;
    /** Current profile */
    Profil *currentProfile;
    /** Current game */
    Game *currentGame;
    /** Data base manager */
    ManagerBdd &managerBDD;

public:
    explicit MainApplication(QQuickView *q_view);
    ~MainApplication();

    static QQuickView *q_view;
    const QString getNameProfile()const;

private:
    void loadProfiles();
    void deleteGame();

signals:
    void nameProfileChanged();

public slots:
    bool launchGame();
    void createProfile(QString nom, int score);
    void changeCurrentProfile(Profil *newCurrentProfile);

};

#endif // MAINAPPLICATION_H
