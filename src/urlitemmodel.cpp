#include "urlitemmodel.h"

#include <sailfishapp.h>
#include <QtQml>

/** Constructor of urlItemModel, representation of a QUrl used in ListModel
 * @brief urlItemModel::urlItemModel
 * @param parent
 */
UrlItemModel::UrlItemModel(QString url) : QObject(0), m_url(url)
{
}

/** Getter of the url of the file
 * @brief UrlItemModel::getUrl
 * @return the url of the file
 */
const QString UrlItemModel::getUrl() const
{
    return m_url;
}

/** Getter of the name of the file
 * @brief UrlItemModel::getName
 * @return the name of the file
 */
const QString UrlItemModel::getName() const
{
    QRegExp regexp ("^.*/([^/]*).db$");
    regexp.indexIn(m_url);

    return regexp.cap(1);
}
