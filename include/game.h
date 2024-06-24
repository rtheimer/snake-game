#ifndef GAME_H
#define GAME_H
#include "snake.h"
#include <raylib.h>

// Generate a random position on the grid based on cell size and grid dimensions
Vector2 getPosition(int cellSize, int cols, int rows);

// check for Border collision
bool borderCollision(Node *head, int screenWidth, int screenHeight,
                     int cellSize);

// check Food Collision
bool foodCollision(Node *head, Rectangle *rect);

// check Body Collision
bool bodyCollision(Node *head);

#endif
