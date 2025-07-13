#include "map.h"

Map::Map() {
    this->Initialize();
}

Map::~Map() {
}

void Map::Initialize() {
    for (size_t y = 0; y < MAP_HEIGHT; y++) {
        for (size_t x = 0; x < MAP_WIDTH; x++) {
            if (y == 0 || y == MAP_HEIGHT - 1 || x == 0 || x == MAP_WIDTH - 1) {
                currentMap[y][x] = MAP_BORDER_CHAR;
            } else {
                currentMap[y][x] = ' ';
            }

            previousMap[y][x] = ' ';
        }
    }

    SetupConsole();
}

void Map::SetupConsole() {
    HWND consoleWindow = GetConsoleWindow();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    COORD bufferSize = {static_cast<SHORT>(MAP_WIDTH), static_cast<SHORT>(MAP_HEIGHT + 2)};
    SetConsoleScreenBufferSize(hConsole, bufferSize);
    
    SMALL_RECT windowSize = {0, 0, static_cast<SHORT>(MAP_WIDTH), static_cast<SHORT>(MAP_HEIGHT + 2)};
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style &= ~WS_MAXIMIZEBOX & ~WS_THICKFRAME;
    SetWindowLong(consoleWindow, GWL_STYLE, style);
    
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    SetConsoleTitle("C++ Snake Game");
}

void Map::SetCursorPosition(size_t x, size_t y) {
    COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Map::Update(const std::shared_ptr<Snake> snake, const std::shared_ptr<Food> food) {
    for (size_t y = 0; y < MAP_HEIGHT; y++) {
        for (size_t x = 0; x < MAP_WIDTH; x++) {
            if (y == 0 || y == MAP_HEIGHT - 1 || x == 0 || x == MAP_WIDTH - 1) {
                currentMap[y][x] = MAP_BORDER_CHAR;
            } else {
                currentMap[y][x] = ' ';
            }
        }
    }

    for (size_t i = 0; i < snake->bodyPartPositions.size(); i++) {
        if (i == snake->bodyPartPositions.size() - 1) {
            currentMap[snake->bodyPartPositions[i].second][snake->bodyPartPositions[i].first] = snake->directionChars[snake->direction];
        } else {
            currentMap[snake->bodyPartPositions[i].second][snake->bodyPartPositions[i].first] = SNAKE_BODY_CHAR;
        }
    }

    currentMap[food->position.second][food->position.first] = FOOD_CHAR;
}

void Map::Draw() {
    for (size_t y = 0; y < MAP_HEIGHT; y++) {
        for (size_t x = 0; x < MAP_WIDTH; x++) {
            if (previousMap[y][x] != currentMap[y][x]) {
                SetCursorPosition(x, y);
                std::cout << currentMap[y][x];
                previousMap[y][x] = currentMap[y][x];
            }
        }
    }

    std::cout.flush();
}