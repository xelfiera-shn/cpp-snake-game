#include "game_manager.h"

GameManager::GameManager() {
    this->map = std::make_unique<Map>();
    this->snake = std::make_shared<Snake>();
    this->food = std::make_shared<Food>();
}

GameManager::~GameManager() {
}

void GameManager::StartGame() {
    food->GenerateNewPosition(snake->bodyPartPositions);
    map->Update(snake, food);
    map->Draw();

    GameLoop();
}

void GameManager::GameLoop() {
    while (true) {
        HandleUserInput();
        snake->Move();

        if (IsSnakeFeeded()) {
            food->GenerateNewPosition(snake->bodyPartPositions);
            score++;
        } else {
            snake->bodyPartPositions.erase(snake->bodyPartPositions.begin());
        }

        if (IsGameOver()) break;

        map->Update(snake, food);
        map->Draw();

        map->SetCursorPosition(0, MAP_HEIGHT);
        std::cout << "Score: " << score << std::endl;

        Sleep(GAME_SPEED);
    }

    map->SetCursorPosition(0, MAP_HEIGHT + 1);
    std::cout << "GAME OVER!" << std::endl;
    std::cout << "Press any key to exit...";
    _getch();
}

void GameManager::HandleUserInput()
{
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
            if (snake->direction != Direction::Down) snake->direction = Direction::Up;
            break;
        case 'd':
            if (snake->direction != Direction::Left) snake->direction = Direction::Right;
            break;
        case 's':
            if (snake->direction != Direction::Up) snake->direction = Direction::Down;
            break;
        case 'a':
            if (snake->direction != Direction::Right) snake->direction = Direction::Left;
            break;
        }
    }
}

bool GameManager::IsSnakeFeeded() {
    const auto& snakeHeadPosition = snake->bodyPartPositions.back();
    return snakeHeadPosition == food->position;
}

bool GameManager::IsGameOver() {
    const auto& snakeHeadPosition = snake->bodyPartPositions.back();
    if (snakeHeadPosition.first <= 0 || snakeHeadPosition.first >= MAP_WIDTH) return true;
    else if (snakeHeadPosition.second <= 0 || snakeHeadPosition.second >= MAP_HEIGHT) return true;

    for (size_t i = 0; i < snake->bodyPartPositions.size() - 1; i++) {
        const auto& bodyPartPosition = snake->bodyPartPositions[i];
        if (snakeHeadPosition == bodyPartPosition) return true;
    }

    return false;
}