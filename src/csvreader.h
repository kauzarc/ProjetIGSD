#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class CSVReader
{
private:
    std::string m_fileName;
    std::string m_separator;

public:
    CSVReader(const std::string &fileName, const std::string &separator);

    const std::vector<std::vector<std::string>> getData();
};

#endif