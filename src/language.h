#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QObject>

class Language : public QObject
{
    Q_OBJECT

public:
    Language(const QLocale qlocale);
    Language(const QString iso, const QString label);

    static void changeLanguage(QString const &iso);
    static const QString getIsoCurrentLanguage();
    static void setIsoCurrentLanguage(const QString iso);
    static const QString getDefaultLanguage();

private:
    /** ISO-639 Representation of the language (ex: "en" for English) */
    QString m_iso;
    /** Entire name of the language*/
    QString m_label;

    /** ISO-639 Representation of the language (ex: "en" for English) */
    static QString s_isoCurrentLanguage;

public slots:
    const QString getIso() const;
    const QString getLabel() const;
};

#endif // LANGUAGE_H
