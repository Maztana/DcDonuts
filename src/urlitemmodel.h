#ifndef URLITEMMODEL_H
#define URLITEMMODEL_H

#include <QObject>

class UrlItemModel : public QObject
{
    Q_OBJECT
public:
    UrlItemModel(QString url);

private:
    /** Url of the file */
    QString m_url;

public slots:
    const QString getUrl() const;
    const QString getName() const;
};

#endif // URLITEMMODEL_H
