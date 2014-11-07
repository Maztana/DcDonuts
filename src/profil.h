#ifndef PROFIL_H
#define PROFIL_H

#include <QObject>
#include <QDate>

class Profil : public QObject
{
    Q_OBJECT

    QString nom;
    QDate *dateDeNaissance;

public:
    explicit Profil(QString nom, QDate *dateDeNaissance);
    ~Profil();

    QString getNom();
    QDate* getDateDeNaissance();

signals:

public slots:

};

#endif // PROFIL_H
