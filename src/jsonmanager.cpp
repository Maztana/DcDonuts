#include "jsonmanager.h"
#include <QFile>
#include <QJsonParseError>
#include <QTextStream>
#include <QJsonObject>
#include <QDir>
#include "ressources.h"

//Variable statique
JsonManager JsonManager::s_instance= JsonManager();

/** Default constructor which load all config
 * @brief JsonManager::JsonManager
 */
JsonManager::JsonManager()
{
    loadConfig();
}

/** Default destructor
 * @brief JsonManager::~JsonManager
 */
JsonManager::~JsonManager()
{

}

/** Load all config
 * @brief JsonManager::loadConfig
 */
void JsonManager::loadConfig()
{
    QString path(PATH_CONFIG);
    path.append(QDir::separator()).append("config.json");
    path = QDir::toNativeSeparators(path);

    QFile file(path);

    if(file.open(QIODevice::ReadOnly))
    {
        QJsonParseError jerror;
        QJsonDocument jdoc= QJsonDocument::fromJson(file.readAll(),&jerror);

        if(!(jerror.error != QJsonParseError::NoError)){
            QJsonObject config = jdoc.object();

            m_idProfile = config["profile"].toDouble();
            m_language = config["language"].toString();
            m_soundState = config["sound"].toBool();
        }
    }
}

/** Return JsonManager's instance
 * @brief JsonManager::getInstance
 * @return JsonManager instance
 */
JsonManager& JsonManager::getInstance()
{
    return s_instance;
}


/** Save configurations of the appli in /home/nemo/.config/harbour-dr-donut/config.json
 * @brief JsonManager::saveConfig
 * @param idProfile last profle used
 * @param language last language used
 */
void JsonManager::saveConfig(int idProfile,QString language, bool soundState)
{
    QJsonObject config;

    config["profile"] = idProfile ;
    config["language"] = language;
    config["sound"] = soundState;

    QString path(PATH_CONFIG);
    path = QDir::toNativeSeparators(path);

    QDir dir;
    dir.mkpath(path);

    path.append(QDir::separator()).append("config.json");
    path = QDir::toNativeSeparators(path);

    QFile file(path);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << QJsonDocument(config).toJson(QJsonDocument::Compact) << endl;
    }
}

/** Return id of profile saved
 * @brief JsonManager::getIdProfile
 * @return id of last profile saved
 */
int JsonManager::getIdProfile()
{
    return m_idProfile;
}

/** Return language saved
 * @brief JsonManager::getLanguage
 * @return last language saved
 */
QString JsonManager::getLanguage()
{
    return m_language;
}

bool JsonManager::getSoundState()
{
    return m_soundState;
}
