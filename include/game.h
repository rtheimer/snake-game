#ifndef GAME_H
#define GAME_H
#include "snake.h"
#include <raylib.h>

// Generate a random position on the grid based on cell size and grid dimensions
Vector2 getPosition(int cellSize, int cols, int rows);

// check for Snake Border collision
bool borderCollision(Node *head, int screenWidth, int screenHeight,
                     int cellSize);

// check Snake Head Food Collision
bool foodCollision(Node *head, Rectangle *rect);

// check Snake Head Body Collision
bool bodyCollision(Node *head);

// check Food placed on Snake
bool foodOnSnake(Node *head, Rectangle *rect);

#endif
