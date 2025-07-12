#pragma once

#include <memory>

#include "map.h"
#include "snake.h"
#include "food.h"

class GameManager {
private:
    std::unique_ptr<Map> gameMap;
    std::unique_ptr<Snake> snake;
    std::unique_ptr<Food> food;

public:
    GameManager();
    ~GameManager();

    void StartGame();

private:
    void Initialize();
    void UpdateMap();
};