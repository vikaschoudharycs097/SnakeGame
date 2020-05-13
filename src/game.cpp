#include "game.h"
#include "point.h"
#include <iostream>


Game::Game(int grid_count_x, int grid_count_y):
 _random_x(0, grid_count_x - 1), _random_y(0, grid_count_y - 1),
snake(grid_count_x, grid_count_y, Point<double>(grid_count_x / 2.0, grid_count_y / 2.0), 
0.1, MoveDirection::UP), food(_random_x(_mt), _random_y(_mt), FoodType::NORMAL)
{

}

void Game::run(Renderer renderer, unsigned target_time)
{
    Uint32 title_time = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;

    while (_running && snake.isAlive())
    {
        frame_start = SDL_GetTicks();
        // Check user input
        inputHandler();

        // Update snake and food
        update();

        // Render snake and food
        renderer.renderWindow(snake, food);

        frame_end = SDL_GetTicks();

        frame_duration = frame_end - frame_start;

        if (frame_end - title_time >= 1000)
        {
            renderer.updateWindowTitle(score);
            title_time = SDL_GetTicks();
        }

        if (frame_duration < target_time)
        {
            SDL_Delay(target_time - frame_duration);
        }
    }
}

void Game::inputHandler(void)
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            _running = false;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            switch(e.key.keysym.sym)
            {
                case SDLK_UP:
                    snake.updateDir(MoveDirection::UP);
                    break;
                case SDLK_DOWN:
                    snake.updateDir(MoveDirection::DOWN);
                    break;
                case SDLK_LEFT:
                    snake.updateDir(MoveDirection::LEFT);
                    break;
                case SDLK_RIGHT:
                    snake.updateDir(MoveDirection::RIGHT);
                    break;   
            }
        }
    }
}

void Game::placeFood(void)
{
    int x, y;
    do
    {
        x = _random_x(_mt);
        y = _random_y(_mt);
    } while (snake.snakeCell(Point<int>(x, y)));

    food.setX(x);
    food.setY(y);
}

void Game::update(void)
{
    // Updating snake position
    snake.update();

    auto head = snake.getHead();
    
    if (static_cast<int>(head.x) == food.getX() && static_cast<int>(head.y) == food.getY())
    {
        score += food.getAmount();
        placeFood();
        snake.updateSpeed(0.01 * _speed_factor);
        // Small decrease in _speed_factor for dynamic speed
        _speed_factor = _speed_factor * _speed_factor - 0.2;
        snake.growBody();
    }
}
