#include "educationalquiz.h"
#include <QtQml>
#include <QThread>
#include "mainapplication.h"

/** Constructor
 * @brief EducationalQuiz::EducationalQuiz
 */
EducationalQuiz::EducationalQuiz():
    GameType(), m_isMixed(false)
{
    qsrand(QDateTime::currentDateTime().toTime_t());
}

/** Destructor
 * @brief EducationalQuiz::~EducationalQuiz
 */
EducationalQuiz::~EducationalQuiz()
{
    m_currentQuestion = nullptr;
}

/** Method to emit new question
 * @brief EducationalQuiz::newQuestion
 */
void EducationalQuiz::newQuestion()
{
    emit propositionsChanged();
    emit textQuestionChanged();
    emit questionChanged();
}

/**  Getter propositions
 * @brief EducationalQuiz::getPropositions
 * @return the m_listPropositions.
 */
const QList<QString> EducationalQuiz::getPropositions()
{
    return m_listPropositions;
}

/** Roll a dice between nbMin and nbMax include
 * @brief EducationalQuiz::rollDice
 * @param nbMax number max
 * @param nbMin number min
 * @return a random number between nbMin and nbMax
 */
int EducationalQuiz::rollDice(int nbMin, int nbMax)const
{
    return qrand() % (((nbMax) + 1) - nbMin) + nbMin;
}

/** Treat response for classic quiz
 * @brief EducationalQuiz::treatmentAnswer
 * @param indexAnswer the index of answer
 */
void EducationalQuiz::treatmentAnswer(const int indexAnswer)
{
    if(m_listPropositions.at(indexAnswer-1).toInt() == getResult().toInt())
    {
        emit answerRight(indexAnswer);
        emit incrementScore(this->m_incremental_score * m_levelGame->getIndex());
    }
    else
    {
        emit answerWrong(indexAnswer);
        emit decrementScore((this->m_incremental_score * m_levelGame->getIndex())/2);
    }
}

/** Setter of list propositions, autogenerated with the question operand
 * @brief EducationalQuiz::setListPropositions
 */
void EducationalQuiz::setListPropositions()
{
    m_listPropositions.clear();

    QString result = getResult();
    QString propo = result;

    int index = qrand() % ((getNumberPropositions()) - 0) + 0;

    for(int i=1; i < getNumberPropositions(); i++)
    {
        while(!propo.compare(result) || m_listPropositions.contains(propo))
        {
            propo = getProposition();
        }
        m_listPropositions.append(propo);
    }
    m_listPropositions.insert(index, result);
}

/** Setter of new current question
 * @brief EducationalQuiz::setQuestion
 * @param question the new question
 */
void EducationalQuiz::setQuestion(Question* question)
{
    m_currentQuestion = question;
}

/** Launcher of game
 * @brief EducationalQuiz::launchGame
 */
void EducationalQuiz::launchGame()
{
    launchQuestion();
}

/** Launcher of question
 * @brief EducationalQuiz::launchQuestion
 */
void EducationalQuiz::launchQuestion()
{
    setNumberPropositions();

    setQuestion(this->buildQuestion());
    setListPropositions();
    newQuestion();
}

/** Treat response if right or wrong
 * @brief EducationalQuiz::treatAnswer
 * @param indexAnswer the index of answer
 */
void EducationalQuiz::treatAnswer(const int indexAnswer)
{
    emit answerGiven();
    treatmentAnswer(indexAnswer);
}

/** Method for emit correct answers
 * @brief EducationalQuiz::answersCorrected
 */
void EducationalQuiz::answersCorrected()
{
    emit correctedAnswer(m_listPropositions.indexOf(getResult()) + 1);
}
