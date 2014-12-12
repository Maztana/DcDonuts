#ifndef EDUCATIONALQUIZ_H
#define EDUCATIONALQUIZ_H

#include "gametype.h"
#include "question.h"

class EducationalQuiz : public GameType
{
    Q_OBJECT

    /** Description of the question */
    Q_PROPERTY(QString textQuestion READ getTextQuestion NOTIFY textQuestionChanged)

    /** Proposition give to interface */
    Q_PROPERTY(QList<QString> propositions READ getPropositions NOTIFY propositionsChanged)

public:
    explicit EducationalQuiz();
    virtual ~EducationalQuiz();

    virtual inline bool isQuiz()const{return true;}

    const QList<QString> getPropositions();

    /** Build a new question, according to the game mode.
     * @brief buildQuestion
     * @return a new question build
     */
    virtual Question* buildQuestion() = 0;

    virtual const QString getProposition()const = 0;
    virtual const QString getResult()const = 0;
    virtual const QString getTextQuestion()const = 0;


protected:
    /** List of propositions */
    QList<QString> m_listPropositions;
    /** current question asked */
    Question* m_currentQuestion;
    /** List of questions asked in this game */
    QList<Question*> m_questionsAsked;
    /** if the game type is mixed */
    bool m_isMixed;

private:
    virtual void treatmentAnswer(const int indexAnswer) = 0;
    virtual void setListPropositions();
    virtual void setQuestion(Question* question);

signals:
    /** When text question changed */
    void textQuestionChanged();
    /** When proposition changed */
    void propositionsChanged();

    /** When new question */
    void questionChanged();
    /** When answer is gave */
    void answerGiven();
    /** When answer is right */
    void answerRight(int index);
    /** When answer is wrong */
    void answerWrong(int index);
    /** When answer is corrected */
    void correctedAnswer(int index);
    /** When question changed */
    void resetAnswer();

public slots:
    virtual void launchGame();
    virtual void launchQuestion();
    void newQuestion();
    void treatAnswer(const int indexAnswer);
    void answersCorrected();
    void answersReset();

};

#endif // EDUCATIONALQUIZ_H
