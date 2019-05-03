#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>
#include <vector>

#include "../Vehicle/Vehicle.h"

class HighScore
{
public:
    HighScore(std::string fileName);

    void printHighScore() const;
    void writeHighScore();
    bool updateHighScore(Vehicle* vehicle);

private:
    void readHighScore();

    std::string GetTimeString(int hundreds) const;

    std::string fileName;
    struct Score
    {
        std::string name;
        int hundreds;
    };
    std::vector<Score> scoreList;
};

#endif
