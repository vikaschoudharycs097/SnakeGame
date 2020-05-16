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

## C++ features used in the game design(Not for user)
1. for, while, if-else if-else, switch, do-while - Used in may files and many places(i.e. Game.cpp have do-while in line 217)
2. User input - Game.cpp function - inputHandler
3. OOP - Game.h, Point.h, Snake.h etc.
4. Constructor with Member initilization list - Game.cpp, Snake.cpp etc.
5. Abstract class - Animal.h
6. Inheritance - Animal class is inherited by Snake and Rat classes
7. Unique_ptr - Game.h for data member snake and rat line 14 and 15
8. Template - Point.h
9. Rule of 5 - Renderer.h
10. Derived class functions override virtual base class functions - Snake.cpp and Rat.cpp
And many more features are used in this program
