#ifndef PROFILE_H
#define PROFILE_H

#include <QObject>

class Profile : public QObject
{
    Q_OBJECT

    /** Profile identifiant */
    int m_id;
    /** Profile name */
    QString m_nom;
    /** Profile score */
    int m_score;


public:
    explicit Profile(int id, QString name, int score);
    ~Profile();

    const QString getName()const;
    int getScore()const;
    int getId()const;

    void incrementScore(int nbPoints);
    void decrementScore(int nbPoints);

signals:

public slots:


};

#endif // PROFILE_H
