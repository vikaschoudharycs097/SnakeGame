#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <memory>
#include "snake.h"
#include "rat.h"
#include "renderer.h"

class Game
{
private:
    std::unique_ptr<Snake> snake;
    std::unique_ptr<Rat> rat;
    bool _running{true};
    int _score{0};

    // Use to determine dynamic change in speed of snake with each new food consumption
    double _speed_factor{1.0};

    // Helper functions
    void inputHandler(void);
    void update(void);

public:
    Game(int grid_x, int grid_y);
    void run(Renderer renderer, unsigned target_time);
    int getScore(void);
};

#endif