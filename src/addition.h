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

protected:
    virtual const QString getProposition()const;
    virtual const QString getResult()const;
    virtual const QString makeTextQuestion(QList<QString> values)const;

private:

signals:

public slots:

};

#endif // ADDITION_H
