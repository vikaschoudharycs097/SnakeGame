# Snake Game
## Introduction
In this project, A grid based snake game is designed using C++ language and SDL(Simple Directmedia Library). It is three levels having three different diffculty level. To move the snake we can use arrows(Left, Right, Up, and Down). Space key is used to pause and resume the game.

## Game Structure(Only for Developer)
1. Point class uses template to define Point a point in 2-D
2. Animal class is Abstract class that is inherited by Snake and Rat class
3. Snake class represent the snake in Game
4. Rat class represent the food for snake in Game
5. Renderer class is used to render figures and texts
6. Game class contains main logic of the game, It contain mainLoop and levels of the game

                   Animal(Abstract class)
                   /    \
                  /      \
              Snake      Rat
              
 ## Image
![](images/im3.png)

## Instruction(for Linux)
<pre>
git clone https://github.com/vikaschoudharycs097/SnakeGame
make  # command to install snake game
snake  # command to run snake game
</pre>

## License
See the [LICENSE](LICENSE) file for license rights and limitations (MIT).
