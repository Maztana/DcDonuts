#include "profile.h"

/** Constructor complet
 * @brief Profile::Profile
 * @param id Identifiant in data base
 * @param name name for profile
 * @param score score for profile
 */
Profile::Profile(int id, QString name, int score)
{
    this->m_id=id;
    this->m_nom=name;
    this->m_score=score;
}

/** Destructor
 * @brief Profile::~Profile
 */
Profile::~Profile()
{

}

/** Getter name profile
 * @brief Profile::getName
 * @return the name of profile
 */
const QString Profile::getName() const
{
    return m_nom;
}

/** Getter score profile
 * @brief Profile::getScore
 * @return the score of profile
 */
int Profile::getScore()const
{
    return m_score;
}

/** Getter identifiant profile
 * @brief Profile::getId
 * @return the identifiant of profile
 */
int Profile::getId()const
{
    return m_id;
}

/** Method for increment score
 * @brief Profile::incrementScore
 * @param nbPoints the number of increment score
 */
void Profile::incrementScore(int nbPoints)
{
    m_score += nbPoints;
}

/** Method for decrement score
 * @brief Profile::decrementScore
 * @param nbPoints the number of decrement score
 */
void Profile::decrementScore(int nbPoints)
{
    m_score -= nbPoints;
    if(m_score < 0)
    {
        m_score = 0;
    }
}

