#include "settings.h"

// Game Colors
Color playgroundColor = {63, 98, 18, 255}; // Background color of the playground
Color foodColor = {67, 20, 7, 255};        // Color of the food
Color headColor = {251, 191, 36, 255};     // Color of the snake's head
Color bodyColor = {255, 0, 0, 255};

// Game Matrix Constants
const int columns = 30;  // Number of columns in the game grid
const int rows = 30;     // Number of rows in the game grid
const int cellSize = 25; // Size of each cell in the grid
const int screenWidth = columns * cellSize; // Width of the game screen
const int screenHeight = rows * cellSize;   // Height of the game screen

// Snake Constants
const int initialSnakeLength = 5; // Initial length of the snake
const int maxBodyLength = 100;

const Direction direction = RIGHT;

Snake snake;          // The snake object
Vector2 foodPosition; // Position of the food
Vector2 headPosition; // Position of the snake's head

// Game Variables
float speed = 0.2f;
