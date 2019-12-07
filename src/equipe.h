#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>
#include <vector>

class Equipe
{
private:
    std::string m_name;
    std::vector<int> m_classements;
    std::vector<int> m_scores;
    std::vector<int> m_matchs;

public:
    Equipe() = default;
    Equipe(const std::string &name);

    void addMatch(int id);

    void setClassement(const std::vector<int> &classement);
    void setScore(const std::vector<int> &score);

    const std::string &getName() const;
    const std::vector<int> &getClassements() const;
    const std::vector<int> &getScores() const;
    const int getMatch(int id) const;
};

#endif