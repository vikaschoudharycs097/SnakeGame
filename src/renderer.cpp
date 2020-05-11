#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "renderer.h"
#include "snake.h"
#include "food.h"

// Constructor
Renderer::Renderer(const int WINDOW_WIDTH, const int WINDOW_HEIGHT, const int GRID_WIDTH, const int GRID_HEIGHT):
_WINDOW_WIDTH(WINDOW_WIDTH), _WINDOW_HEIGHT(WINDOW_HEIGHT), _GRID_WIDTH(GRID_WIDTH), _GRID_HEIGHT(GRID_HEIGHT)
{
    // Initilizating all subsystem of SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL Error: " << SDL_GetError() << "\n";
    }

    // Creating SDL window
    _window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (_window == nullptr)
    {
        std::cerr << "SDL Error: " << SDL_GetError() << "\n";
    }

    // Creating SDL renderer
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr)
    {
        std::cerr << "SDL Error: " << SDL_GetError() << "\n";
    }
}

// Destructor
Renderer::~Renderer()
{
    // Destorying window
    SDL_DestroyWindow(_window);

    // Cleaning all subsystem
    SDL_Quit();
}

void Renderer::renderWindow(Snake &snake, Food &food)
{
    SDL_Rect rect; 
    rect.w = _GRID_WIDTH;
    rect.h = _GRID_HEIGHT;

    // Clearing window
    SDL_SetRenderDrawColor(_renderer, 0X1E, 0X1E, 0X1E, 0XFF);
    SDL_RenderClear(_renderer);

    // Render the food
    rect.x = food.getX() * rect.w;  // Converting grid number into pixel
    rect.y = food.getY() * rect.h;
    SDL_SetRenderDrawColor(_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    SDL_RenderFillRect(_renderer, &rect);

    // Render the snake body
    SDL_SetRenderDrawColor(_renderer, 0XFF, 0XFF, 0XFF, 0XFF);
    for (auto &point: snake.getBody())
    {
        rect.x = point.x * rect.w;
        rect.y = point.y * rect.h;
        SDL_RenderFillRect(_renderer, &rect);
    }

    // Render the snake head
    auto head = snake.getHead();
    rect.x = static_cast<int>(head.x) * rect.w;
    rect.y = static_cast<int>(head.y) * rect.h;
    if (snake.isAlive())
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