//
// Created by 15471 on 2021/11/7.
//

#ifndef TSPQUESTION_TSP_H
#define TSPQUESTION_TSP_H
#include <vector>
#include <utility>
class TSP{
    private:
        std::vector<std::pair<int, int>> citys;
    public:
        TSP(const std::vector<std::pair<int, int>> citys);
        std::vector<std::pair<int, int>> getCitys();
        void printCitys();
};

#endif //TSPQUESTION_TSP_H
