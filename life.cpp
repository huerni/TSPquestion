//
// Created by 15471 on 2021/11/7.
//

#include "life.h"

Life::Life(const std::vector<int>& gene) {
        this->gene = gene;
        this->score = -1;
}

void Life::setScore(int score) {
    this->score = score;
}

int Life::getScore() {

    return score;
}

std::vector<int> Life::getGene() {
    return gene;
}