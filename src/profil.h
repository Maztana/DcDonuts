#ifndef PROFIL_H
#define PROFIL_H

#include <QObject>

class Profil : public QObject
{
    Q_OBJECT

    QString nom;
    int score;

public:
    explicit Profil(QString nom);
    ~Profil();

    const QString getNom()const;
    int getScore()const;

    void incrementScore(int nbPoints);

signals:

public slots:


};

#endif // PROFIL_H
