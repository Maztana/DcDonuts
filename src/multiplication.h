#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "calcul.h"

class Multiplication : public Calcul
{
    Q_OBJECT
public:
    explicit Multiplication();
    ~Multiplication();

    virtual Question* buildQuestion();

protected:
    virtual const QString getProposition()const;
    virtual const QString makeTextQuestion(QList<QString> values)const;

private:

signals:

public slots:
    virtual const QString getResult()const;

};

#endif // MULTIPLICATION_H
