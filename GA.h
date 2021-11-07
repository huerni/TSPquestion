//
// Created by 15471 on 2021/11/7.
//

#ifndef TSPQUESTION_GA_H
#define TSPQUESTION_GA_H
#include "life.h"
#include "TSP.h"
#include <vector>
class GA{
    private:
        double crossRate;
        double mutationRate;
        int lifeCount;
        int geneLength;
        std::vector<Life> lives;
        Life best;
        int generation = 1;
        int crossCount = 0;
        int mutationCount = 0;
        double bounds = 0.0;
        std::vector<std::pair<int, int>> citys;
    public:
        GA(int crossRate, int mutationRate, int lifeCount, int geneLength, const std::vector<std::pair<int, int>>& citys);
        void initPopulation();
        double matchFun(Life life);
        void judge();
        std::vector<int> cross(Life* parent1, Life* parent2);
        std::vector<int> mutation(const std::vector<int>& gene);
        Life getOne();
        Life newChild();
        void next();
};

#endif //TSPQUESTION_GA_H
