#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "game.h"
#include "managerbdd.h"
#include <QQuickView>
#include <QGuiApplication>

class MainApplication : public QObject
{
    Q_OBJECT

    /** Name of current profil property */
    Q_PROPERTY(QString nameProfile READ getNameProfile NOTIFY nameProfileChanged)
    /** List of all profile's id */
    Q_PROPERTY(QList<int> allId READ getAllId)


    /** List all profiles */
    QList<Profile*> m_profiles;
    /** Current profile */
    Profile *m_currentProfile;
    /** Current game */
    Game *m_currentGame;
    /** Data base manager */
    ManagerBdd &m_managerBDD;



public:
    explicit MainApplication(QQuickView *q_view);
    ~MainApplication();

    /** View of the application */
    static QQuickView *s_view;
    const QString getNameProfile()const;
    const QList<int> getAllId() const;


private:

    void loadProfiles();
    void deleteGame();

signals:
    void nameProfileChanged();
    void profileChanged();

public slots:
    bool launchGame();
    void createProfile(QString nom, int score = 0);
    void changeCurrentProfile(Profile *newCurrentProfile);
    void changeCurrentProfile(int id);

    Profile* getProfileById(int id);
    QString getNameProfileById(int id);
    int getScoreProfileById(int id);
    int getNbProfiles();
    void resetProfile(int id);
    void deleteProfile(int id);

};

#endif // MAINAPPLICATION_H
