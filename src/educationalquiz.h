#ifndef EDUCATIONALQUIZ_H
#define EDUCATIONALQUIZ_H

#include "gametype.h"
#include "question.h"

class EducationalQuiz : public GameType
{
    Q_OBJECT

    Q_PROPERTY(QString proposition1 READ getProposition1 NOTIFY proposition1Changed)
    Q_PROPERTY(QString proposition2 READ getProposition2 NOTIFY proposition2Changed)
    Q_PROPERTY(QString proposition3 READ getProposition3 NOTIFY proposition3Changed)
    Q_PROPERTY(QString proposition4 READ getProposition4 NOTIFY proposition4Changed)

    /** List of propositions */
    QList<QString> m_listPropositions;
    /** List of questions asked in this game */
    QList<Question*> m_questionsAsked;
    /** current question asked */
    Question* m_currentQuestion;

    /** list of response who must be reset */
    QList<int> m_listResetAnswers;

public:
    explicit EducationalQuiz(Level* gameLevel);
    virtual ~EducationalQuiz();

    virtual inline bool isQuiz()const{return true;}

    const QString getProposition1();
    const QString getProposition2();
    const QString getProposition3();
    const QString getProposition4();

    /** Build a new question, according to the game mode.
     * @brief buildQuestion
     * @return a new question build
     */
    virtual Question* buildQuestion() = 0;
    Question* getCurrentQuestion();

protected:
    /** number of propositions, according to the level */
    static int s_number_propositions;

private:
    void setListPropositions();
    void treatAnswerQuiz(int indexAnswer);

signals:
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
    void answerWrong(int indexWrong, int indexRight);
    /** When question changed */
    void resetAnswer(int index);

public slots:
    virtual void launchGame();
    void launchQuestion();
    void newQuestion();
    void treatAnswer(int indexAnswer);
    void answersReset();

};

#endif // EDUCATIONALQUIZ_H
