#pragma once

namespace constants {
    constexpr int MAP_WIDTH = 102;
    constexpr int MAP_HEIGHT = 52;
    constexpr char MAP_BORDER_CHAR = '#';

    constexpr int SNAKE_START_POSITION_X = MAP_WIDTH / 2;
    constexpr int SNAKE_START_POSITION_Y = MAP_HEIGHT / 2;
    constexpr char SNAKE_HEAD_UP_CHAR = '^';
    constexpr char SNAKE_HEAD_RIGHT_CHAR = '>';
    constexpr char SNAKE_HEAD_DOWN_CHAR = 'v';
    constexpr char SNAKE_HEAD_LEFT_CHAR = '<';
    constexpr char SNAKE_BODY_CHAR = '0';

    constexpr char FOOD_CHAR = '*';

    constexpr int GAME_SPEED = 100; // Miliseconds
}