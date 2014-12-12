#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include<QString>

class JsonManager
{
private:

    /** JsonManager instance */
    static JsonManager s_instance;

    /** id of last current profile saved */
    int m_idProfile;
    /** last language saved */
    QString m_language;
    /** sound state saved */
    bool m_soundState;

    explicit JsonManager();

    void loadConfig();

public:
    ~JsonManager();
    static JsonManager& getInstance();

    void saveConfig(int m_idProfile, QString m_language, bool m_soundState);

    int getIdProfile();
    QString getLanguage();
    bool getSoundState();

};

#endif // JSONMANAGER_H
