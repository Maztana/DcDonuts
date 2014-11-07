#include "question.h"

Question::Question(QString mode, int operande1, int operande2) :
    QObject(0), mode(mode)
{
    //trie des operandes!
    if(operande1 < operande2)
    {
        this->operande1 = operande2;
        this->operande2 = operande1;
    }
    else
    {
        this->operande1 = operande1;
        this->operande2 = operande2;
    }
}

int Question::getResult()
{
    int result = 0;

    if(!mode.compare("ADDITION"))
    {
        result = operande1 + operande2;
    }
    else if (!mode.compare("SOUSTRACTION"))
    {
        result = operande1 - operande2;
    }
    else if(!mode.compare("DIVISION"))
    {
        result = operande1 / operande2;
    }
    else if(!mode.compare("MULTIPLICATION"))
    {
        result = operande1 * operande2;
    }

    return result;
}

int Question::getProposition()
{
    ////////////////////////////////////////////////////////////////////////////////////
    /// \brief propo
    ///
    ///         REVOIR LES RANDOMS DE CHAQUE PROPOSITION
    ///
    /////////////////////////////////////////////////////////////////////////////////////
    int propo = 0;

    if(!mode.compare("ADDITION"))
    {
        propo = qrand() % (((operande1 +(operande2*2)) + 1) - operande2) + operande2;
    }
    else if (!mode.compare("SOUSTRACTION"))
    {
        propo = qrand() % (((operande1 -(operande2*2)) + 1) - operande2) + operande2;
    }
    else if(!mode.compare("DIVISION"))
    {
        propo = qrand() % (((operande1 +(operande2*2)) + 1) - operande2) + operande2;
    }
    else if(!mode.compare("MULTIPLICATION"))
    {
        propo = qrand() % (((operande1 +(operande2*2)) + 1) - operande2) + operande2;
    }

    return propo;
}

/*QString Question::toString()
{
    QString question = "";

    if(!mode.compare("ADDITION"))
    {
        question =  QString(operande1) + " + " + QString(operande2) + " = ";
    }
    else if (!mode.compare("SOUSTRACTION"))
    {
        question = QString(operande1) + " - " + QString(operande2) + " = ";
    }
    else if(!mode.compare("DIVISION"))
    {
        question = QString(operande1) + " / " + QString(operande2) + " = ";
    }
    else if(!mode.compare("MULTIPLICATION"))
    {
        question = QString(operande1) + " x " + QString(operande2) + " = ";
    }

    return question;
}*/
