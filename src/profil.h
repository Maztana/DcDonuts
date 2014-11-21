#ifndef PROFIL_H
#define PROFIL_H

#include <QObject>

class Profil : public QObject
{
    Q_OBJECT

    int id;
    QString nom;
    int score;


public:
    explicit Profil(QString nom);
    Profil(int id, QString name, int score);
    ~Profil();

    const QString getNom()const;
    int getScore()const;
    int getId()const;

    void incrementScore(int nbPoints);

signals:

public slots:


};

#endif // PROFIL_H
