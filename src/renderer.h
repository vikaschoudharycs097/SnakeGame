#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "snake.h"
#include "food.h"

class Renderer
{
private:
    const int _WINDOW_WIDTH;
    const int _WINDOW_HEIGHT;
    const int _GRID_WIDTH;
    const int _GRID_HEIGHT;
    SDL_Window *_window;
    SDL_Renderer *_renderer;

public:
    Renderer(const int WINDOW_WIDTH, const int WINDOW_HEIGHT, const int GRID_WIDTH, const int GRID_HEIGHT);
    ~Renderer();
    void renderWindow(Snake &snake, Food &food);
    void updateWindowTitle(int score);
};

#endif