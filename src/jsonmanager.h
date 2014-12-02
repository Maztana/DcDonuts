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

    explicit JsonManager();

    void loadConfig();

public:
    ~JsonManager();
    static JsonManager& getInstance();

    void saveConfig(int m_idProfile,QString m_language);
    int getIdProfile();
    QString getLanguage();

};

#endif // JSONMANAGER_H
