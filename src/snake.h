#pragma once

#include <vector>
#include <utility>
#include <map>

#include "../utils/constants.h"
#include "../utils/enums.h"

using namespace constants;

class Snake {
public:
    Direction direction;
    std::map<Direction, char> directionChars;
    std::vector<std::pair<int, int>> bodyPartPositions;

public:
    Snake();
    ~Snake();

    void UpdateBodyPartPositions();

private:
    void Initialize();
    void InitializeDirectionCharsMap();
    void InitializeBodyPartPositions();
};