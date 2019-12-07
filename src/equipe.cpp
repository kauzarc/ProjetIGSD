#include "equipe.h"

using namespace std;

Equipe::Equipe(const string &name) { m_name = name; }

void Equipe::addMatch(int id) { m_matchs.push_back(id); }

void Equipe::setClassement(const vector<int> &classements) { m_classements = classements; }
void Equipe::setScore(const vector<int> &scores) { m_scores = scores; }

const string &Equipe::getName() const { return m_name; }
const vector<int> &Equipe::getClassements() const { return m_classements; }
const vector<int> &Equipe::getScores() const { return m_scores; }
const int Equipe::getMatch(int id) const { return m_matchs[id]; }