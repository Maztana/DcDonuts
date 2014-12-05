#include "language.h"
#include "mainapplication.h"
#include "ressources.h"

#include <sailfishapp.h>
#include <QGuiApplication>
#include <QtQml>

QString Language::s_isoCurrentLanguage = "en";

Language::Language(const QLocale qlocale) : QObject(0), m_iso(), m_label()
{
    m_iso = qlocale.name().left(2);

    QString labelOrig(qlocale.nativeLanguageName());
    m_label = (labelOrig.left(1).toUpper());
    m_label += labelOrig.right(labelOrig.size()-1);
}

const QString Language::getIso() const
{
    return m_iso;
}

const QString Language::getLabel() const
{
    return m_label;
}

const QString Language::getIsoCurrentLanguage()
{
    return s_isoCurrentLanguage;
}

void Language::setIsoCurrentLanguage(const QString iso)
{
    s_isoCurrentLanguage = iso;
}
