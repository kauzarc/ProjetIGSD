#include "match.h"

using namespace std;

Match::Match()
{
}

void Match::setHomeTeamName(const string &homeTeamName) { m_homeTeamName = homeTeamName; }
void Match::setAwayTeamName(const string &awayTeamName) { m_awayTeamName = awayTeamName; }
void Match::setHomeTeamScore(int homeTeamScore) { m_homeTeamScore = homeTeamScore; }
void Match::setAwayTeamScore(int awayTeamScore) { m_awayTeamScore = awayTeamScore; }

const string &Match::getHomeTeamName() const { return m_homeTeamName; }
const string &Match::getAwayTeamName() const { return m_awayTeamName; }
int Match::getHomeTeamScore() const { return m_homeTeamScore; }
int Match::getAwayTeamScore() const { return m_awayTeamScore; }