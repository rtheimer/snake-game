#include "food.h"
#include <raylib.h>
#include <stdlib.h>

Rectangle *createFood(Vector2 position, int cellSize) {
    Rectangle *food = (Rectangle *)malloc(sizeof(Rectangle));

    food->x = position.x;
    food->y = position.y;
    food->width = cellSize;
    food->height = cellSize;

    return food;
}
