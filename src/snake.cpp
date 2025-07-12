#include "snake.h"

Snake::Snake() {
    this->Initialize();
}

Snake::~Snake() {
}

void Snake::Initialize() {
    this->direction = Direction::Right;
    this->InitializeDirectionCharsMap();
    this->InitializeBodyPartPositions();
}

void Snake::InitializeDirectionCharsMap() {
    directionChars = {
        { Direction::Up, SNAKE_HEAD_UP_CHAR },
        { Direction::Right, SNAKE_HEAD_RIGHT_CHAR },
        { Direction::Down, SNAKE_HEAD_DOWN_CHAR },
        { Direction::Left, SNAKE_HEAD_LEFT_CHAR }
    };
}

void Snake::InitializeBodyPartPositions() {
    bodyPartPositions = {
        { SNAKE_START_POSITION_X - 2, SNAKE_START_POSITION_Y },
        { SNAKE_START_POSITION_X - 1, SNAKE_START_POSITION_Y },
        { SNAKE_START_POSITION_X, SNAKE_START_POSITION_Y }
    };
}

void Snake::UpdateBodyPartPositions() {
    auto headPosition = bodyPartPositions.back();
    switch (direction) {
    case Direction::Up:
        bodyPartPositions.push_back({ headPosition.first, headPosition.second - 1 });
        break;

    case Direction::Right:
        bodyPartPositions.push_back({ headPosition.first + 1, headPosition.second });
        break;

    case Direction::Down:
        bodyPartPositions.push_back({ headPosition.first, headPosition.second + 1 });
        break;

    case Direction::Left:
        bodyPartPositions.push_back({ headPosition.first - 1, headPosition.second });
        break;
    }
}