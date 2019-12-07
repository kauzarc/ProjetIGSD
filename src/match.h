#ifndef MATCH_H
#define MATCH_H

#include <string>

class Match
{
private:
    std::string m_homeTeamName;
    std::string m_awayTeamName;

    int m_homeTeamScore;
    int m_awayTeamScore;

public:
    Match();

    void setHomeTeamName(const std::string &HometeamName);
    void setAwayTeamName(const std::string &AwayteamName);
    void setHomeTeamScore(int homeTeamScore);
    void setAwayTeamScore(int awayTeamScore);

    const std::string &getHomeTeamName() const;
    const std::string &getAwayTeamName() const;
    int getHomeTeamScore() const;
    int getAwayTeamScore() const;
};

#endif