#include <SDL.h>
#include <iostream>
#include <string>
#include "renderer.h"
#include "snake.h"
#include "rat.h"

// Constructor
Renderer::Renderer(int w_width, int w_height, int g_width, int g_height):
_window_width(w_width), _window_height(w_height), _grid_width(g_width), _grid_height(g_height)
{
    // Initilizating all subsystem of SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL Error: " << SDL_GetError() << "\n";
    }

    // Creating SDL window
    _window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              w_width, w_height, 0);
    if (_window == nullptr)
    {
        std::cerr << "SDL Error: " << SDL_GetError() << "\n";
    }

    // Creating SDL renderer
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if (_renderer == nullptr)
    {
        std::cerr << "SDL Error: " << SDL_GetError() << "\n";
    }
}

// Copy Constructor
Renderer::Renderer(const Renderer &renderer):
_window_width(renderer._window_width), _window_height(renderer._window_height),
_grid_width(renderer._grid_width), _grid_height(renderer._grid_height)
{
    // Creating SDL window
    _window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              _window_width, _window_height, SDL_GetWindowFlags(renderer._window));
    if (_window == nullptr)
    {
        std::cerr << "SDL Error: " << SDL_GetError() << "\n";
    }

    // Creating SDL renderer
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if (_renderer == nullptr)
    {
        std::cerr << "SDL Error: " << SDL_GetError() << "\n";
    }
}

// Move Constructor
Renderer::Renderer(Renderer &&renderer):
_window_width(renderer._window_width), _window_height(renderer._window_height),
_grid_width(renderer._grid_width), _grid_height(renderer._grid_height)
{
    _window = renderer._window;
    _renderer = renderer._renderer;

    // Setting nullptr to dynamic part of renderer
    renderer._window = nullptr;
    renderer._renderer = nullptr;
}

// Destructor
Renderer::~Renderer()
{
    // Destorying window
    SDL_DestroyWindow(_window);

    // Cleaning all subsystem
    SDL_Quit();
}

void Renderer::renderWindow(Snake *snake, Rat *rat)
{
    SDL_Rect rect; 
    rect.w = _grid_width;
    rect.h = _grid_height;

    // Clearing window
    SDL_SetRenderDrawColor(_renderer, 0X1E, 0X1E, 0X1E, 0XFF);
    SDL_RenderClear(_renderer);

    // Render the food
    rect.x = rat->getX() * rect.w;  // Converting grid number into pixel
    rect.y = rat->getY() * rect.h;
    SDL_SetRenderDrawColor(_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    SDL_RenderFillRect(_renderer, &rect);

    // Render the snake body
    SDL_SetRenderDrawColor(_renderer, 0XFF, 0XFF, 0XFF, 0XFF);
    for (auto &point: snake->getBody())
    {
        rect.x = point.x * rect.w;
        rect.y = point.y * rect.h;
        SDL_RenderFillRect(_renderer, &rect);
    }

    // Render the snake head
    auto head = snake->getHead();
    rect.x = static_cast<int>(head.x) * rect.w;
    rect.y = static_cast<int>(head.y) * rect.h;
    if (snake->isAlive())
    {
        SDL_SetRenderDrawColor(_renderer, 0X0, 0x7A, 0xCC, 0xFF);
    }
    else 
    {
        SDL_SetRenderDrawColor(_renderer, 0XFF, 0X0, 0X0, 0XFF);
    }
    SDL_RenderFillRect(_renderer, &rect);

    // Update screen
    SDL_RenderPresent(_renderer);
}

void Renderer::updateWindowTitle(int score)
{
    std::string title{"Score: " + std::to_string(score)};
    SDL_SetWindowTitle(_window, title.c_str());
}

// Copy assignment operator
Renderer& Renderer::operator=(const Renderer &renderer)
{
    _window_width = renderer._window_width;
    _window_height = renderer._window_height;
    _grid_width = renderer._grid_width;
    _grid_height = renderer._grid_height;

    // Creating SDL window
    _window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              _window_width, _window_height, SDL_GetWindowFlags(renderer._window));
    if (_window == nullptr)
    {
        std::cerr << "SDL Error: " << SDL_GetError() << "\n";
    }

    // Creating SDL renderer
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if (_renderer == nullptr)
    {
        std::cerr << "SDL Error: " << SDL_GetError() << "\n";
    }

    return *this;
}

// Move assignment operator
Renderer& Renderer::operator=(Renderer &&renderer)
{
    _window_width = renderer._window_width;
    _window_height = renderer._window_height;
    _grid_width = renderer._grid_width;
    _grid_height = renderer._grid_height;

    _window = renderer._window;
    _renderer = renderer._renderer;

    renderer._window = nullptr;
    renderer._renderer = nullptr;

    return *this; 
}