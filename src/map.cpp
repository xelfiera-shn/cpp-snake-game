#include "map.h"

Map::Map() {
    this->Initialize();
}

Map::~Map() {
}

void Map::Initialize() {
    for (size_t i = 0; i < MAP_HEIGHT; i++) {
        for (size_t j = 0; j < MAP_WIDTH; j++) {
            if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) {
                map[i][j] = MAP_BORDER_CHAR;
            } else {
                map[i][j] = ' ';
            }
        }
    }
}

void Map::Draw() {
    for (size_t i = 0; i < MAP_HEIGHT; i++) {
        for (size_t j = 0; j < MAP_WIDTH; j++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}