#ifndef ADDITION_H
#define ADDITION_H

#include "calcul.h"

class Addition : public Calcul
{
    Q_OBJECT
public:
    explicit Addition();
    ~Addition();

    virtual Question* buildQuestion();
    virtual const QString makeTextQuestion(QList<QString> values)const;

public slots:
    virtual const QString getResult()const;

};

#endif // ADDITION_H
