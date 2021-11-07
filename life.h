//
// Created by 15471 on 2021/11/7.
//

#ifndef TSPQUESTION_LIFE_H
#define TSPQUESTION_LIFE_H

#include <vector>
class Life{
    private:
        std::vector<int> gene;
        int score;
    public:
        Life(const std::vector<int>& gene);
        void setScore(int score);
        int getScore();
        std::vector<int> getGene();
};

#endif //TSPQUESTION_LIFE_H
