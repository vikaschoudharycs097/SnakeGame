#include "game.h"
#include "point.h"
#include <iostream>


Game::Game(int grid_x, int grid_y):
snake(new Snake(Point<double>(grid_x / 2.0, grid_y / 2.0), 0.1, grid_x, 
grid_y, MoveDirection::UP)), rat(new Rat(Point<double>(0.0, 0.0), grid_x, grid_y, 1.0)),
_GRID_X(grid_x), _GRID_Y(grid_y)
{

}

void Game::run(Renderer renderer, unsigned target_time)
{
    level1(renderer, target_time, 200);


    if (snake->isAlive() && _running)
    {
        renderer.renderFont("../fonts/EvilEmpire.ttf", "You Win!", 30);   
    }
    return;
}

void Game::inputHandler(void)
{
    SDL_Event e;
    while (SDL_PollEvent(&e) && _running)
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
                    snake->updateDir(MoveDirection::UP);
                    break;
                case SDLK_DOWN:
                    snake->updateDir(MoveDirection::DOWN);
                    break;
                case SDLK_LEFT:
                    snake->updateDir(MoveDirection::LEFT);
                    break;
                case SDLK_RIGHT:
                    snake->updateDir(MoveDirection::RIGHT);
                    break;
                case SDLK_SPACE:
                    while (true)
                    {
                        if (SDL_PollEvent(&e))
                        {
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
                            {
                                std::cout << "yes\n";
                                break;
                            }
                            else if (e.type == SDL_QUIT) 
                            {
                                std::cout << "no\n";
                                _running = false;
                                break;
                            }
                        }
                        SDL_Delay(10);
                    }   
            }
        }
    }
}

void Game::update(void)
{
    // Updating snake position
    snake->update(obstacle);
    
    auto head = snake->getHead();
    
    if (static_cast<int>(head.x) == rat->getX() && static_cast<int>(head.y) == rat->getY())
    {
        _score += rat->getAmount();
        validRatHead();
        rat->updateAmount(0.3);
        
        snake->updateSpeed(0.04 * _speed_factor);
        // Small decrease in _speed_factor for dynamic speed 
        // After peek this function decreases but it will serve required purpose
        _speed_factor = _speed_factor * _speed_factor - 0.0001;
        snake->growBody();
    }
}

void Game::level1(Renderer &renderer, unsigned target_time, int score_limit)
{
    validRatHead();
    renderer.renderFont("../fonts/EvilEmpire.ttf", "LEVEL 1", 30);
    gameLoop(renderer, target_time, score_limit);

    // Winner or loser
    if (!_running)
    {

    }
    else if (snake->isAlive())
    {
        _speed_factor = 1.0;
        snake->reset();  // Resetting snake
        rat->setAmount(1.0);
        level2(renderer, target_time, 500);   
    }
    else
    {
        renderer.renderFont("../fonts/EvilEmpire.ttf", "You Lose!", 30);
    }
}

void Game::level2(Renderer &renderer, unsigned target_time, int score_limit)
{
    // Adding obstacle
    for (int i = 0; i < _GRID_X; i++)
    {
        obstacle.push_back(Point<int>(i, 0));
        obstacle.push_back(Point<int>(i, _GRID_Y - 1));
    }
    for (int i = 1; i < _GRID_Y - 1; i++)
    {
        obstacle.push_back(Point<int>(0, i));
        obstacle.push_back(Point<int>(_GRID_X - 1, i));
    }

    validRatHead();

    renderer.renderFont("../fonts/EvilEmpire.ttf", "LEVEL 2", 30);
    gameLoop(renderer, target_time, score_limit);

    if (!_running)
    {

    }
    else if (snake->isAlive())
    {
        _speed_factor = 1.0;
        snake->reset();  // Resetting snake
        rat->setAmount(1.0);
        level3(renderer, target_time, 1000); 
    }
    else 
    {
        renderer.renderFont("../fonts/EvilEmpire.ttf", "You Lose!", 30);
    }
}

void Game::level3(Renderer &renderer, unsigned target_time, int score_limit)
{
    // Adding more obstacle
    for (int i = 10; i < _GRID_X - 11; i++)
    {
        obstacle.push_back(Point<int>(i, _GRID_Y / 4));
        obstacle.push_back(Point<int>(i, 3 * _GRID_Y / 4));
    }

    validRatHead();

    renderer.renderFont("../fonts/EvilEmpire.ttf", "LEVEL 3", 30);
    gameLoop(renderer, target_time, score_limit);

    if (!snake->isAlive())
    {
        renderer.renderFont("../fonts/EvilEmpire.ttf", "You Lose!", 30);
    }
}

void Game::gameLoop(Renderer &renderer, unsigned target_time, int score_limit)
{
    Uint32 title_time = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    while (_running && snake->isAlive() && _score < score_limit)
    {
        frame_start = SDL_GetTicks();
        
        // Check user input
        inputHandler();
        
        // Update snake and food
        update();
    
        // Render snake and food
        renderer.renderWindow(snake.get(), rat.get(), obstacle);

        frame_end = SDL_GetTicks();

        frame_duration = frame_end - frame_start;

        if (frame_end - title_time >= 100)
        {
            renderer.updateWindowTitle(_score);
            title_time = SDL_GetTicks();
        }

        if (frame_duration < target_time)
        {
            SDL_Delay(target_time - frame_duration);
        }
    }
}

int Game::getScore(void)
{
    return _score;
}

void Game::validRatHead(void)
{
    Point<int> t_head(0, 0);
    do
    {
        rat->updateHead();
        t_head.x = rat->getX();
        t_head.y = rat->getY();
    } while (snake->snakeCell(t_head) || rat->checkCollision(obstacle));
}
