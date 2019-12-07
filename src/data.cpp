#include "data.h"

using namespace std;

Data::Data()
{
    CSVReader csvReaderR("data/rankspts.csv", ",");
    vector<vector<string>> tableauRankspts = csvReaderR.getData();
    for (unsigned int i = 0; i < tableauRankspts.size(); i++)
    {
        Equipe current = getEquipeFromLine(tableauRankspts[i]);
        m_listeEquipe[current.getName()] = current;
    }

    CSVReader csvReaderE("data/englishR.csv", ",");
    vector<vector<string>> tableauEnglishR = csvReaderE.getData();
    for (unsigned int i = 1; i < tableauEnglishR.size(); i++)
    {
        Match current = getMatchFromLine(tableauEnglishR[i]);
        m_listeMatch.push_back(current);
    }

    for (unsigned int i = 0; i < m_listeMatch.size(); i++)
    {
        Equipe &equipe1 = m_listeEquipe[m_listeMatch[i].getHomeTeamName()];
        Equipe &equipe2 = m_listeEquipe[m_listeMatch[i].getAwayTeamName()];

        equipe1.addMatch(i);
        equipe2.addMatch(i);
    }
}

Equipe Data::getEquipeFromLine(const vector<string> &line)
{
    m_listeNom.push_back(line[0]);
    Equipe result(line[0]);
    vector<int> classement;
    vector<int> score;
    //std::cout << result.getName() << std::endl;

    unsigned int stop = (line.size() - 1) / 6;
    for (unsigned int i = 0; i < stop; i++)
    {
        classement.push_back(stoi(line[6 * i + 1]));
        score.push_back(stoi(line[6 * i + 2]));
    }

    result.setClassement(classement);
    result.setScore(score);

    return result;
}

Match Data::getMatchFromLine(const vector<string> &line)
{
    Match result;
    result.setHomeTeamName(line[2]);
    result.setAwayTeamName(line[3]);
    result.setHomeTeamScore(stoi(line[4]));
    result.setAwayTeamScore(stoi(line[5]));

    return result;
}

const map<string, Equipe> &Data::getEquipes() const { return m_listeEquipe; }
const vector<string> &Data::getNoms() const { return m_listeNom; }