#pragma once

#include <vector>
#include <utility>

#include "../utils/constants.h"

using namespace constants;

class Food {
public:
    std::pair<int, int> position;

public:
    Food();
    ~Food();

    void GenerateNewPosition(std::vector<std::pair<int, int>>& snakeBodyPartPositions);
};