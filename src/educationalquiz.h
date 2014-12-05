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
    Q_PROPERTY(QString proposition1 READ getProposition1 NOTIFY proposition1Changed)
    Q_PROPERTY(QString proposition2 READ getProposition2 NOTIFY proposition2Changed)
    Q_PROPERTY(QString proposition3 READ getProposition3 NOTIFY proposition3Changed)
    Q_PROPERTY(QString proposition4 READ getProposition4 NOTIFY proposition4Changed)

public:
    explicit EducationalQuiz();
    virtual ~EducationalQuiz();

    virtual inline bool isQuiz()const{return true;}


    const QString getProposition1();
    const QString getProposition2();
    const QString getProposition3();
    const QString getProposition4();
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
    void proposition1Changed();
    void proposition2Changed();
    void proposition3Changed();
    void proposition4Changed();

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
