#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject
{
    Q_OBJECT

    /** Description of the question */
    Q_PROPERTY(QString description READ getDescription NOTIFY descriptionChanged)

    /** The game mode for this question */
    const QString& m_gameMode;
    /** The first operande */
    int m_firstOperande;
    /** The second operand */
    int m_secondOperande;

public:
    explicit Question(const QString& gameMode, int firstOperande, int secondOperande);

    QString getProposal()const;
    QString getResult()const;
    QString getDescription()const;

private:
    QString getProposalCalculation()const;

signals:
    void descriptionChanged();

public slots:

};

#endif // QUESTION_H
