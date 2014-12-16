#ifndef DIVISION_H
#define DIVISION_H

#include "calcul.h"

class Division : public Calcul
{
    Q_OBJECT
public:
    explicit Division();
    ~Division();

    virtual Question* buildQuestion();
    virtual const QString makeTextQuestion(QList<QString> values)const;

public slots:
    virtual const QString getResult()const;

};

#endif // DIVISION_H
