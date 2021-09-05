cmake_minimum_required(VERSION 3.6)
project(LodeRunner VERSION 0.0.1)

add_subdirectory(Framework)

include_directories(Framework/inc include data/menu)

set(SOURCES 
    sources/game.cpp
    sources/Player.cpp
    sources/Guard.cpp
    sources/SpritesLoad.cpp
    sources/Level.cpp)
    

set(HEADERS
    include/Player.h
    include/Guard.h
    include/SpritesLoad.h
    include/Level.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

find_library(SDL2 NAMES "SDL2")
find_library(SDL2main NAMES "SDL2main")
find_library(SDL2_image NAMES "SDL2_image")

target_link_libraries(${PROJECT_NAME} FrameworkRelease ${SDL2} ${SDL2main} ${SDL2_image})
