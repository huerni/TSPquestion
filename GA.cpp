//
// Created by 15471 on 2021/11/7.
//

#include "GA.h"
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ctime>
GA::GA(int crossRate, int mutationRate, int lifeCount, int geneLength, const std::vector<std::pair<int, int>>& citys) {
    this->crossRate = crossRate;
    this->mutationRate = mutationRate;
    this->lifeCount = lifeCount;
    this->geneLength = geneLength;
    this->citys = citys;

    initPopulation();
}

void GA::initPopulation() {
    lives.clear();
    for(int i = 0; i < lifeCount; i++){
        std::vector<int> gene;
        for(int k = 0; k<geneLength; k++) gene.push_back(k);
        std::random_shuffle(gene.begin(), gene.end());
        lives.push_back(gene);
    }
}

double GA::matchFun(Life life) {
    std::vector<int> gene = life.getGene();
    double distance = 0;
    for(int i = 0; i<geneLength-1; i++){
        std::pair<int, int> city1 = citys[i];
        std::pair<int, int> city2 = citys[i+1];
        distance += sqrt(pow((city1.first - city2.first), 2)*1.0 + pow((city1.second-city2.second), 2)*1.0);
    }
    return distance;
}

void GA::judge() {
    bounds = 0.0;
    best = lives[0];
    for (auto& life : lives){
        life.setScore(matchFun(life));
        bounds += life.getScore();
        if(best.getScore() < life.getScore()) best = life;
    }
}

std::vector<int> GA::cross(Life *parent1, Life *parent2) {
    std::srand(std::time(nullptr));
    int index1 = std::rand() % geneLength;
    int index2 = 0;
    do{
        index2 = std::rand() % geneLength;
    }while(index2 > index1);
    std::vector<int> tempGene = parent2->getGene();
    std::vector<int> newGene;
    int len = parent1->getGene().size();
    for(int i = 0; i<len; i++){
        if(i == index1){
            for(;i<index2; i++){
                newGene.push_back(tempGene[i]);
            }
        }
        newGene.push_back(parent1->getGene()[i]);
    }

    return newGene;
}

std::vector<int> GA::mutation(const std::vector<int> &gene) {
    std::srand(std::time(nullptr));
    int index1 = std::rand() % geneLength;
    int index2 = std::rand() % geneLength;

    std::vector<int> newGene = gene;
    int t = newGene[index1];
    newGene[index1] = newGene[index2];
    newGene[index2] = t;

    return newGene;
}

Life GA::getOne() {
    std::srand(std::time(nullptr));
    int r = std::rand() % (int)bounds;
    for(auto& life : lives){
        r -= life.getScore();
        if(r <= 0) return life;
    }
}

Life GA::newChild() {
    Life parent1 = getOne();
    std::srand(std::time(nullptr));
    int rate = std::rand() % 1;
    std::vector<int> gene;
    if(rate < crossRate){
        Life parent2 = getOne();
        gene = cross(&parent1, &parent2);
    }
    else {
        gene = parent1.getGene();
    }

    rate = std::rand() % 1;
    if(rate < mutationRate){
        gene = mutation(gene);
    }

    return Life(gene);
}

void GA::next() {
    judge();
    std::vector<Life> newLives;
    newLives.push_back(best);
    while(newLives.size() < lifeCount){
        newLives.push_back(newChild());
    }
    lives = newLives;
    generation += 1;

}