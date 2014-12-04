#include "educationalquiz.h"
#include <QtQml>
#include <QThread>
#include "mainapplication.h"
#include "ressources.h"

/** Constructor with level game
 * @brief EducationalQuiz::EducationalQuiz
 * @param niveauDuJeu the level game
 */
EducationalQuiz::EducationalQuiz():
    GameType()
{
    qsrand(QDateTime::currentDateTime().toTime_t());
}

/** Destructor
 * @brief EducationalQuiz::~EducationalQuiz
 */
EducationalQuiz::~EducationalQuiz()
{
    m_currentQuestion = NULL;
    qDeleteAll(m_questionsAsked);
}

/**  Getter proposition1
 * @brief EducationalQuiz::getProposition1
 * @return the proposition1 in the m_listPropositions.
 */
const QString EducationalQuiz::getProposition1()
{
    return m_listPropositions.at(0);
}

/**  Getter proposition2
 * @brief EducationalQuiz::getProposition2
 * @return the proposition2 in the m_listPropositions.
 */
const QString EducationalQuiz::getProposition2()
{
    return m_listPropositions.at(1);
}

/**  Getter proposition3
 * @brief EducationalQuiz::getProposition3
 * @return the proposition3 in the m_listPropositions.
 */
const QString EducationalQuiz::getProposition3()
{
    return m_listPropositions.at(2);
}

/**  Getter proposition4
 * @brief EducationalQuiz::getProposition4
 * @return the proposition4 in the m_listPropositions.
 */
const QString EducationalQuiz::getProposition4()
{
    return m_listPropositions.at(3);
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
    m_currentQuestion = this->buildQuestion();
    m_questionsAsked.append(m_currentQuestion);

    setListPropositions();
    newQuestion();
}

/** Method to emit new question
 * @brief EducationalQuiz::newQuestion
 */
void EducationalQuiz::newQuestion()
{
    emit proposition1Changed();
    emit proposition2Changed();
    emit proposition3Changed();
    emit proposition4Changed();
    emit textQuestionChanged();
    emit questionChanged();
}

/****************************************************************************************************/
/*              Faire une fonction protected pour treatAnswer de chaque classe fille                */
/****************************************************************************************************/
/** Treat response if right or wrong
 * @brief EducationalQuiz::treatAnswer
 * @param indexAnswer the index of answer
 */
void EducationalQuiz::treatAnswer(const int indexAnswer)
{
    emit answerGiven();

    m_listResetAnswers.clear();

    treatmentAnswer(indexAnswer);
}
/*******************************************************************************************************/

/** Method for emit correct answers
 * @brief EducationalQuiz::answersReset
 */
void EducationalQuiz::answersCorrected()
{
    emit correctedAnswer(m_listPropositions.indexOf(getResult()) + 1);
}

/** Method for emit reset answers
 * @brief EducationalQuiz::answersReset
 */
void EducationalQuiz::answersReset()
{
    emit resetAnswer();
}
