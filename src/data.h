#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "csvreader.h"
#include "equipe.h"
#include "match.h"

class Data
{
private:
    std::map<std::string, Equipe> m_listeEquipe;
    std::vector<Match> m_listeMatch;
    std::vector<std::string> m_listeNom;

    Equipe getEquipeFromLine(const std::vector<std::string> &line);
    Match getMatchFromLine(const std::vector<std::string> &line);

public:
    Data();

    const std::map<std::string, Equipe> &getEquipes() const;
    const std::vector<std::string> &getNoms() const;
};

#endif