#include "game_manager.h"

GameManager::GameManager() {
    this->gameMap = std::make_unique<Map>();
    this->snake = std::make_unique<Snake>();
    this->food = std::make_unique<Food>();
}

GameManager::~GameManager() {
}

void GameManager::StartGame() {
    UpdateMap();
    gameMap->Draw();
}

void GameManager::UpdateMap() {
    for (size_t i = 0; i < snake->bodyPartPositions.size(); i++) {
        if (i == snake->bodyPartPositions.size() - 1) {
            gameMap->map[snake->bodyPartPositions[i].second][snake->bodyPartPositions[i].first] = snake->directionChars[snake->direction];
        } else {
            gameMap->map[snake->bodyPartPositions[i].second][snake->bodyPartPositions[i].first] = SNAKE_BODY_CHAR;
        }
    }

    food->GenerateNewPosition(snake->bodyPartPositions);
    gameMap->map[food->position.second][food->position.first] = FOOD_CHAR;
}