#include "food.h"

Food::Food() {
}

Food::~Food() {
}

void Food::GenerateNewPosition(std::vector<std::pair<int, int>>& bodyPartPositions) {
    do {
        this->position.first = rand() % MAP_WIDTH - 1;
        this->position.second = rand() % MAP_HEIGHT - 1;

        if (this->position.first == 0) this->position.first++;
        if (this->position.second == 0) this->position.second++;
    } while (std::find(bodyPartPositions.begin(), bodyPartPositions.end(), this->position) != bodyPartPositions.end());
}