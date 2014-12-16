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

    void newQuestion();

    const QList<QString> getPropositions();

    /** Build a new question, according to the game mode.
     * @brief buildQuestion
     * @return a new question build
     */
    virtual Question* buildQuestion() = 0;

    virtual const QString getProposition()const = 0;
    virtual const QString getTextQuestion(){return m_currentQuestion->getTextQuestion();}
    virtual const QString makeTextQuestion(QList<QString> values)const = 0;

protected:
    /** List of propositions */
    QList<QString> m_listPropositions;
    /** current question asked */
    Question* m_currentQuestion;
    /** if the game type is mixed */
    bool m_isMixed;

    int rollDice(int nbMin, int nbMax)const;

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

public slots:
    virtual const QString getResult()const = 0;
    virtual inline bool isQuiz()const{return true;}
    virtual inline bool isFlashcard(){return false;}
    virtual inline bool isCounting(){return false;}
    virtual void launchGame();
    virtual void launchQuestion();
    void treatAnswer(const int indexAnswer);
    void answersCorrected();

};

#endif // EDUCATIONALQUIZ_H
