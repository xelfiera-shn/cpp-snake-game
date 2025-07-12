cmake_minimum_required(VERSION 3.10)
project(CppSnakeGame)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
    src/map.cpp
    src/snake.cpp
    src/food.cpp
    src/game_manager.cpp
)

set(HEADERS
    src/map.h
    src/snake.h
    src/food.h
    src/game_manager.h
    utils/constants.h
    utils/enums.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})