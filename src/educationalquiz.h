#ifndef EDUCATIONALQUIZ_H
#define EDUCATIONALQUIZ_H

#include "gametype.h"
#include "question.h"

class EducationalQuiz : public GameType
{
    Q_OBJECT

    Q_PROPERTY(QString proposal1 READ getProposal1 NOTIFY proposal1Changed)
    Q_PROPERTY(QString proposal2 READ getProposal2 NOTIFY proposal2Changed)
    Q_PROPERTY(QString proposal3 READ getProposal3 NOTIFY proposal3Changed)
    Q_PROPERTY(QString proposal4 READ getProposal4 NOTIFY proposal4Changed)

    /** List of proposals */
    QList<QString> m_listProposals;
    /** List of questions asked in this game */
    QList<Question*> m_questionsAsked;
    /** current question asked */
    Question* m_currentQuestion;

    /** list of response who must be reset */
    QList<int> m_listResetAnswers;


public:
    explicit EducationalQuiz(Level* gameLevel);
    ~EducationalQuiz();

    virtual inline bool isQuiz()const{return true;}

    const QString getProposal1();
    const QString getProposal2();
    const QString getProposal3();
    const QString getProposal4();

    /** Build a new question, according to the game mode.
     * @brief buildQuestion
     * @return a new question build
     */
    virtual Question* buildQuestion() = 0;
    Question* getCurrentQuestion();
    //const QString& getGameMode();

protected:
    /** number of proposals, according to the level */
    static int s_number_proposals;

private:
    void setListProposals();
    void traitAnswerCalculation(int indexAnswer);

signals:
    void proposal1Changed();
    void proposal2Changed();
    void proposal3Changed();
    void proposal4Changed();

    void answerTrait();
    void answerRight(int index);
    void answerWrong(int index);
    void resetAnswer(int index);

public slots:
    virtual void launchGame();
    void launchQuestion();
    void newQuestion();
    void traitAnswer(int indexAnswer);
    void answersReset();

};

#endif // EDUCATIONALQUIZ_H
