#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject
{
    Q_OBJECT

    QString mode;
    //chiffre max
    int operande1;
    //chiffre min
    int operande2;

public:
    explicit Question(QString mode, int operande1, int operande2);

    int getResult()const;
    int getProposition()const;
    const QString toString()const;

signals:

public slots:

};

#endif // QUESTION_H
