#include <iostream>
#include <memory>

#include "src/game_manager.h"

int main(int argc, char const *argv[])
{
    std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
    gameManager->StartGame();
    return 0;
}