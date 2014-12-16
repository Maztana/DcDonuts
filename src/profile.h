#ifndef PROFILE_H
#define PROFILE_H

#include <QObject>

class Profile : public QObject
{
    Q_OBJECT

    /** Name of current profil property */
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
    /** Score of current profile */
    Q_PROPERTY(int score READ getScore NOTIFY scoreChanged)
    /** id of current profile */
    Q_PROPERTY(int id READ getId)

    /** Profile identifiant */
    int m_id;
    /** Profile name */
    QString m_name;
    /** Profile score */
    int m_score;


public:
    explicit Profile(int id, QString name, int score);
    ~Profile();

    void profileChanged();

    const QString getName()const;
    int getScore()const;
    int getId()const;

    void resetScore();

private:
    void setScore(int nbPoints);

signals:
    /** When the name profile changed */
    void nameChanged();
    /** When the score changed */
    void scoreChanged();

public slots:
    void scoreIncrement(int nbPoints);
    void scoreDecrement(int nbPoints);
};

#endif // PROFILE_H
