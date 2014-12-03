#include "jsonmanager.h"
#include <QFile>
#include <QJsonParseError>
#include <QTextStream>
#include <QJsonObject>

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

    QFile file("config.json");

    if(file.open(QIODevice::ReadOnly))
    {
        QJsonParseError jerror;
        QJsonDocument jdoc= QJsonDocument::fromJson(file.readAll(),&jerror);

        if(!(jerror.error != QJsonParseError::NoError)){
            QJsonObject config = jdoc.object();

            m_idProfile = config["profile"].toDouble();
            m_language = QString::number(config["language"].toDouble());
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


/** Save appli's config
 * @brief JsonManager::saveConfig
 * @param idProfile last profle used
 * @param language last language used
 */
void JsonManager::saveConfig(int idProfile,QString language)
{
    QJsonObject config;

    config["profile"] = idProfile ;
    config["language"] = language;
    config["sound"] = false;

    QFile file("config.json");



    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << QJsonDocument(config).toJson(QJsonDocument::Compact) << endl;
    }
}

/** Return profile saved
 * @brief JsonManager::getIdProfile
 * @return last profile saved
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
