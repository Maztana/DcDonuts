#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "game.h"
#include "managerbdd.h"
#include <QQuickView>
#include <QGuiApplication>

class MainApplication : public QObject
{
    Q_OBJECT


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

    /** Getter of score profile
     * @brief getScore
     * @return the profile score
     */
    inline int getScore(){return m_currentProfile->getScore();}

    /** View of the application */
    static QQuickView *s_view;
    /** Default profile application */
    static Profile* s_defaultProfile;

    const QList<int> getAllId() const;

    ///////////////////////////////////////
    Profile* getCurrentProfile(){return m_currentProfile;}
    ///////////////////////////////////////

private:
    const QString getNameProfile()const;
    void loadProfiles();
    void deleteGame();

signals:

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
