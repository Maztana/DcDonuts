#include "educationalquiz.h"
#include <QtQml>
#include <QThread>
#include "mainapplication.h"
#include "ressources.h"

int EducationalQuiz::s_number_propositions = 4;

/** Constructor with level game
 * @brief QuestionnaireEducatif::QuestionnaireEducatif
 * @param niveauDuJeu the level game
 */
EducationalQuiz::EducationalQuiz(Level* niveauDuJeu):
    GameType(niveauDuJeu)
{
    qsrand(QDateTime::currentDateTime().toTime_t());
}

/** Destructor
 * @brief QuestionnaireEducatif::~QuestionnaireEducatif
 */
EducationalQuiz::~EducationalQuiz()
{
    m_currentQuestion = NULL;
    qDeleteAll(m_questionsAsked);
}

/**  Getter proposition1
 * @brief QuestionnaireEducatif::getProposition1
 * @return the proposition1 in the m_listPropositions.
 */
const QString EducationalQuiz::getProposition1()
{
    return m_listPropositions.at(0);
}

/**  Getter proposition2
 * @brief QuestionnaireEducatif::getProposition2
 * @return the proposition2 in the m_listPropositions.
 */
const QString EducationalQuiz::getProposition2()
{
    return m_listPropositions.at(1);
}

/**  Getter proposition3
 * @brief QuestionnaireEducatif::getProposition3
 * @return the proposition3 in the m_listPropositions.
 */
const QString EducationalQuiz::getProposition3()
{
    return m_listPropositions.at(2);
}

/**  Getter proposition4
 * @brief QuestionnaireEducatif::getProposition4
 * @return the proposition4 in the m_listPropositions.
 */
const QString EducationalQuiz::getProposition4()
{
    return m_listPropositions.at(3);
}

/** Getter of the current question
 * @brief QuestionnaireEducatif::getCurrentQuestion
 * @return the current question
 */
Question* EducationalQuiz::getCurrentQuestion()
{
    return m_currentQuestion;
}

/** Setter of list propositions, autogenerated with the question operand
 * @brief QuestionnaireEducatif::setListPropositions
 */
void EducationalQuiz::setListPropositions()
{
    m_listPropositions.clear();

    QString result = m_currentQuestion->getResult();
    QString propo = m_currentQuestion->getResult();

    int index = qrand() % ((s_number_propositions) - 0) + 0;

    for(int i=1; i < s_number_propositions; i++)
    {
        while(!propo.compare(result) || m_listPropositions.contains(propo))
        {
            propo = m_currentQuestion->getProposition();
        }
        m_listPropositions.append(propo);
    }
    m_listPropositions.insert(index, result);
}

/** Launcher of game
 * @brief QuestionnaireEducatif::launchGame
 */
void EducationalQuiz::launchGame()
{
    launchQuestion();
}

/** Launcher of question
 * @brief QuestionnaireEducatif::launchQuestion
 */
void EducationalQuiz::launchQuestion()
{
    m_currentQuestion = this->buildQuestion();
    m_questionsAsked.append(m_currentQuestion);
    MainApplication::s_view->rootContext()->setContextProperty("question", m_currentQuestion);

    setListPropositions();
    newQuestion();
}

/** Method to emit new question
 * @brief QuestionnaireEducatif::newQuestion
 */
void EducationalQuiz::newQuestion()
{
    emit proposition1Changed();
    emit proposition2Changed();
    emit proposition3Changed();
    emit proposition4Changed();
    emit questionChanged();
}

/** Treat response if right or wrong
 * @brief QuestionnaireEducatif::treatAnswer
 * @param indexAnswer the index of answer
 */
void EducationalQuiz::treatAnswer(int indexAnswer)
{
    emit answerGiven();

    m_listResetAnswers.clear();

    //si questionnaire
    if(this->isQuiz())
    {
        treatAnswerQuiz(indexAnswer);
    }
    else //si flashcard
    {
        //faire autre traitement.
    }
}

/** Treat response if right or wrong
 * @brief QuestionnaireEducatif::treatAnswerQuiz
 * @param indexAnswer the index of answer
 */
void EducationalQuiz::treatAnswerQuiz(int indexAnswer)
{
    int result = m_currentQuestion->getResult().toInt();


    //Gestion du résultat
    if(m_listPropositions.at(indexAnswer-1).toInt() == result)
    {
        //Réponse correcte
        emit answerRight(indexAnswer);
        //add point au profil
        emit incrementScore(this->s_incremental_score * 2);
    }
    else
    {
        //Réponse fausse
        emit answerWrong(indexAnswer);
        emit decrementScore(this->s_incremental_score);
    }
    //add stat question
}

/** Method for emit correct answers
 * @brief QuestionnaireEducatif::answersReset
 */
void EducationalQuiz::answersCorrected()
{
    int indexResult = m_listPropositions.indexOf(m_currentQuestion->getResult());
    emit correctedAnswer(indexResult + 1);
}

/** Method for emit reset answers
 * @brief QuestionnaireEducatif::answersReset
 */
void EducationalQuiz::answersReset()
{
    emit resetAnswer();
}
