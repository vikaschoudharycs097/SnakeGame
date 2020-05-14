#include <utility>
#include <iostream>
#include "game.h"
#include "renderer.h"

int main(void)
{
    constexpr unsigned FRAME_PER_SECOND = 30;
    constexpr unsigned FRAME_PER_MILLISECOND = 1000 / FRAME_PER_SECOND;
    constexpr unsigned WINDOW_WIDTH = 960;
    constexpr unsigned WINDOW_HEIGHT = 600;
    constexpr unsigned GRID_WIDTH = 20;
    constexpr unsigned GRID_HEIGHT = 20;

    Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, GRID_WIDTH, GRID_HEIGHT);
    Game game(WINDOW_WIDTH / GRID_WIDTH, WINDOW_HEIGHT / GRID_HEIGHT);
    game.run(std::move(renderer), FRAME_PER_MILLISECOND);
    std::cout << "Score is: " << game.getScore() << "\n"; 

    return 0;
}