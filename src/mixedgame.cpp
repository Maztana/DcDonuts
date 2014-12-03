#include "mixedgame.h"

MixedGame::MixedGame()
    :EducationalQuiz()
{
}

/** Add type Quiz in the mixed mode
 * @brief MixedGame::addGameType
 * @param typeQuiz the new quiz type
 */
void MixedGame::addGameType(EducationalQuiz* typeQuiz)
{
    m_listEducationalQuiz.append(typeQuiz);
}

/** Build question with current type game
 * @brief MixedGame::buildQuestion
 * @return the new current question
 */
Question* MixedGame::buildQuestion()
{
    return m_listEducationalQuiz[m_indexCurrentGameType]->buildQuestion();
}

/** Getter of the proposition of current question of current type game
 * @brief MixedGame::getProposition
 * @return the proposition question
 */
const QString MixedGame::getProposition()const
{
    return m_listEducationalQuiz[m_indexCurrentGameType]->getProposition();
}

/** Getter of the result of current question of current type game
 * @brief MixedGame::getResult
 * @return the result question
 */
const QString MixedGame::getResult()const
{
    return m_listEducationalQuiz[m_indexCurrentGameType]->getResult();
}

/** Getter of the text of current question of current type game
 * @brief MixedGame::getTextQuestion
 * @return the text question
 */
const QString MixedGame::getTextQuestion()const
{
    return m_listEducationalQuiz[m_indexCurrentGameType]->getTextQuestion();
}

/** Treat response for classic quiz (no flascard)
 * @brief MixedGame::treatmentAnswer
 * @param indexAnswer the index of answer
 */
void MixedGame::treatmentAnswer(const int indexAnswer)
{
    m_listEducationalQuiz[m_indexCurrentGameType]->treatmentAnswer(indexAnswer);
}

/** Setter of list levels selectable
 * @brief MixedGame::setLevelsSelectable
 */
void MixedGame::setLevelsSelectable()
{
    bool isFirst = true;
    for(EducationalQuiz* quiz : m_listEducationalQuiz)
    {
        if(isFirst)
        {
            m_listLevelsSelectable.append(quiz->getLevelsSelectable());
            isFirst = false;
        }
        else
        {
            for(int levelIndex : quiz->getLevelsSelectable())
            {
                if(!m_listLevelsSelectable.contains(levelIndex))
                {
                    m_listLevelsSelectable.removeAt(m_listLevelsSelectable.indexOf(levelIndex));
                }
            }
        }
    }
    emit levelsSelectableChanged();
}

/** Setter for the level game
 * @brief MixedGame::initLevelGame
 * @param indexLevel the level game index
 */
void MixedGame::initLevelGame(int indexLevel)
{
    delete(m_levelGame);
    Level* level = new Level(indexLevel);
    m_listEducationalQuiz[m_indexCurrentGameType]->initLevelGame(level->getIndex());

    m_levelGame = level;
    setNumberPropositions(m_listEducationalQuiz[m_indexCurrentGameType]->getNumberPropositions());
    //emit levelChanged();
}
