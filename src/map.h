#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include <windows.h>

#include "../utils/constants.h"
#include "snake.h"
#include "food.h"

using namespace constants;

class Map {
private:
    char previousMap[MAP_HEIGHT][MAP_WIDTH];
    char currentMap[MAP_HEIGHT][MAP_WIDTH];

public:
    Map();
    ~Map();

    void SetCursorPosition(size_t x, size_t y);
    void Update(const std::shared_ptr<Snake> snake, const std::shared_ptr<Food> food);
    void Draw();

private:
    void Initialize();
    void SetupConsole();
};