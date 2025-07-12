#pragma once

#include <iostream>

#include "../utils/constants.h"

using namespace constants;

class Map {
public:
    char map[MAP_HEIGHT][MAP_WIDTH];

public:
    Map();
    ~Map();

    void Draw();

private:
    void Initialize();
};