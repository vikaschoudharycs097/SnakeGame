#ifndef GAME_H
#define GAME_H

#include <random>
#include <SDL.h>
#include "snake.h"
#include "food.h"
#include "renderer.h"

class Game
{
private:
    Snake snake;
    Food food;
    bool _running{true};
    int score{0};

    // Use to determine dynamic change in speed of snake with each new food consumption
    double _speed_factor{1.0};

    // Helper functions
    void inputHandler(void);
    void update(void);
    void placeFood(void);
    
    // For random position generation
    std::random_device _rd;
    std::mt19937 _mt{_rd()};
    std::uniform_int_distribution<int> _random_x;
    std::uniform_int_distribution<int> _random_y;

public:
    Game(int grid_count_x, int grid_count_y);
    void run(Renderer renderer, unsigned target_time);
};

#endif