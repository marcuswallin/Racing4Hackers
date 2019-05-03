#include "HighScore.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

HighScore::HighScore(string f) : fileName{f}
{
    readHighScore();
}

void HighScore::printHighScore() const
{
    cout << fileName << endl;
    cout << setfill('-') << left << setw(29) << '-' << endl;
    cout << setfill(' ') << setw(12) << "Time" << "Name" << endl;
    cout << setfill('-') << setw(29) << '-' << endl;

    for (int i = 0; i < scoreList.size(); ++i)
    {
        cout << setfill(' ') << setw(12) << GetTimeString(scoreList.at(i).hundreds) << scoreList.at(i).name << endl;
    }

    cout << setfill('-') << setw(29) << '-' << endl;
    cout << endl;
}

bool HighScore::updateHighScore(Vehicle* vehicle)
{
    bool result{false};
    Score score{vehicle->getName(), vehicle->getTime()};

    for (int i = 0; i < 10; ++i)
    {
        if (score.hundreds < scoreList.at(i).hundreds && score.hundreds != 0)
        {
            Score tmpScore = scoreList.at(i);
            scoreList.at(i) = score;
            score = tmpScore;
            result = true;
        }
    }

    return result;
}

void HighScore::readHighScore()
{
    ifstream in{fileName};

    if(!in.is_open())
    {
        in.close();
        throw invalid_argument("The .hs file does not exist");
    }

    string name;
    int hundreds;

    while (in.good())
    {
        if (in >> name && in >> hundreds)
        {
            Score tmpScore{name, hundreds};
            scoreList.emplace_back(tmpScore);
        }
        else
        {
            throw invalid_argument(
                    "The .hs file does not have the correct format");
        }
    }

    in.close();
}

void HighScore::writeHighScore()
{
    ofstream out{fileName};

    if(!out.is_open())
    {
        out.close();
        throw invalid_argument("The .hs file does not exist");
    }
    for (int i = 0; i < scoreList.size(); ++i)
    {
        out << scoreList.at(i).name << " " << scoreList.at(i).hundreds;
        if(i != scoreList.size() - 1)
        {
            out << '\n';
        }
    }


    out.close();

}

string HighScore::GetTimeString(int hundreds) const
{
    stringstream ss;
    ss << setfill('0') << setw(2) << (hundreds / 6000)
       << ":" << setw(2) << (hundreds / 100 % 60)
       << "." << setw(2) << (hundreds % 100);
    return ss.str();
}