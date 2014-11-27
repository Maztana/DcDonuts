#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject
{
    Q_OBJECT

    /** Description of the question */
    Q_PROPERTY(QString description READ getTextQuestion NOTIFY descriptionChanged)

    /** The game mode for this question */
    const QString& m_gameMode;
    /** All values for this question */
    QList<QString> m_listValues;
    /** The first operande */
    //int m_firstOperande;
    /** The second operand */
    //int m_secondOperande;

public:
    explicit Question(const QString& gameMode, QList<QString> listValues);

    QString getProposition()const;
    QString getResult()const;
    QString getTextQuestion()const;

private:
    int rollDice(int nbMax, int nbMin)const;
    int getResultCalcul()const;
    QString getPropositionCalcul()const;

signals:
    /** When text question changed */
    void descriptionChanged();

public slots:

};

#endif // QUESTION_H
