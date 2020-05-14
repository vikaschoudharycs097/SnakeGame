#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include "snake.h"
#include "rat.h"

class Renderer
{
private:
    int _window_width;
    int _window_height;
    int _grid_width;
    int _grid_height;
    SDL_Window *_window;
    SDL_Renderer *_renderer;

public:
    // Constructor and Destructor
    Renderer(const int WINDOW_WIDTH, const int WINDOW_HEIGHT, const int GRID_WIDTH, const int GRID_HEIGHT);
    Renderer(const Renderer &renderer);  // Copy constructor for deep copy
    Renderer(Renderer &&renderer);   // Move Constructor
    ~Renderer();  // Destructor

    void renderWindow(Snake *snake, Rat *rat);
    void updateWindowTitle(int score);

    // Operator Overloading
    Renderer& operator=(const Renderer &renderer);
    Renderer& operator=(Renderer &&renderer);
};

#endif