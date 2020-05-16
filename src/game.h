#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <memory>
#include <string>
#include "snake.h"
#include "rat.h"
#include "renderer.h"

class Game
{
private:
    std::unique_ptr<Snake> snake;
    std::unique_ptr<Rat> rat;
    const int _GRID_X;
    const int _GRID_Y;
    bool _running{true};
    int _score{0};
    std::vector<Point<int>> obstacle;

    // Use to determine dynamic change in speed of snake with each new food consumption
    double _speed_factor{1.0};

    // Helper functions
    void inputHandler(void);
    void update(void);

public:
    Game(int grid_x, int grid_y);
    void run(Renderer renderer, unsigned target_time);
    void gameLoop(Renderer &render, unsigned target_time, int score_limit);
    void level1(Renderer &renderer, unsigned target_time, int score_limit);
    void level2(Renderer &renderer, unsigned target_time, int score_limit);
    void level3(Renderer &renderer, unsigned target_time, int score_limit);
    int getScore(void);
    void validRatHead(void);
};

#endif