#ifndef SETTINGS_H
#define SETTINGS_H
#include "snake.h"
#include <raylib.h>

// Game Colors
extern Color playgroundColor;
extern Color foodColor;
extern Color headColor;
extern Color bodyColor;

// Game Matrix Constants
extern const int columns;
extern const int rows;
extern const int cellSize;
extern const int screenWidth;
extern const int screenHeight;

// Snake Constants
extern const int initialSnakeLength;
extern const int maxBodyLength;
extern const Direction direction;

extern Snake snake;          // The snake object
extern Vector2 foodPosition; // Position of the food
extern Vector2 headPosition; // Position of the snake's head

// Game Variables
extern float speed;
#endif
