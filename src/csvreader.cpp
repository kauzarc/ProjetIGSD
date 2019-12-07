#include "csvreader.h"

using namespace std;

CSVReader::CSVReader(const string &fileName, const string &separator)
{
    m_fileName = fileName;
    m_separator = separator;
}

const vector<vector<string>> CSVReader::getData()
{
    vector<vector<string>> result;
    ifstream stream(m_fileName, ifstream::out);
    string str;

    while (getline(stream, str))
    {
        vector<string> subresult;
        stringstream ss(str);
        string substr;

        while (getline(ss, substr, m_separator[0]))
        {
            subresult.push_back(substr);
        }

        result.push_back(subresult);
    }

    stream.close();

    return result;
}