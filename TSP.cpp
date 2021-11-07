//
// Created by 15471 on 2021/11/7.
//

#include "TSP.h"
#include <iostream>
TSP::TSP(const std::vector<std::pair<int, int>> citys){
    this->citys = citys;
}
std::vector<std::pair<int, int>> TSP::getCitys() {
    return citys;
}
void TSP::printCitys() {
    int len = citys.size();
    for(int i = 0; i<len; i++){
        std::cout<<i<<"号城市坐标："<<citys[0].first<<", "<<citys[0].second<<std::endl;
    }
}