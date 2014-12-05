#include "language.h"
#include "mainapplication.h"
#include "ressources.h"

#include <sailfishapp.h>
#include <QGuiApplication>
#include <QtQml>

QString Language::s_isoCurrentLanguage = "en";

/** Constructor of Language, a representation of a language
 * @brief Language::Language
 * @param qlocale
 */
Language::Language(const QLocale qlocale) : QObject(0), m_iso(), m_label()
{
    m_iso = qlocale.name().left(2);

    QString labelOrig(qlocale.nativeLanguageName());
    m_label = (labelOrig.left(1).toUpper());
    m_label += labelOrig.right(labelOrig.size()-1);
}

/** Getter of the iso code of the language (ex : "en" for English)
 * @brief Language::getIso
 * @return the iso code of the language
 */
const QString Language::getIso() const
{
    return m_iso;
}

/** Getter of the label of the language
 * @brief Language::getLabel
 * @return the label of the language
 */
const QString Language::getLabel() const
{
    return m_label;
}

/** Getter of the iso code of the current language (ex : "en" for English)
 * @brief Language::getIsoCurrentLanguage
 * @return the iso code of the current language
 */
const QString Language::getIsoCurrentLanguage()
{
    return s_isoCurrentLanguage;
}

/** Setter of the iso code of the current language (ex : "en" for English)
 * Change the language of the application at the next start.
 * @brief Language::setIsoCurrentLanguage
 * @param iso
 */
void Language::setIsoCurrentLanguage(const QString iso)
{
    s_isoCurrentLanguage = iso;
}
