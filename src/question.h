#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString libelle READ getLibelle NOTIFY libelleChanged)
    Q_PROPERTY(int result READ getResult NOTIFY resultChanged)


    QString mode;
    int operande1;
    int operande2;

public:
    explicit Question(QString mode, int operande1, int operande2);

    int getProposition()const;
    int getResult()const;
    QString getLibelle()const;

signals:
    void libelleChanged();
    void resultChanged();

public slots:

};

#endif // QUESTION_H
