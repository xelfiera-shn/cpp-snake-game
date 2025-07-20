#pragma once

#include <memory>
#include <conio.h>
#include <windows.h>

#include "../utils/constants.h"
#include "map.h"
#include "snake.h"
#include "food.h"

using namespace constants;

class GameManager {
private:
    std::unique_ptr<Map> map;
    std::shared_ptr<Snake> snake;
    std::shared_ptr<Food> food;

    int score = 0;

public:
    GameManager();
    ~GameManager();

    void StartGame();

private:
    void Initialize();
    void GameLoop();
    void HandleUserInput();
    bool IsSnakeFeeded();
    void UpdateScore();
    bool IsGameOver();
};