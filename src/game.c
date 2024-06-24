#include "game.h"
#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Generate a random position on the grid based on cell size and grid dimensions
Vector2 getPosition(int cellSize, int cols, int rows) {
    int posX = GetRandomValue(0, cols - 1); // Random X position within grid
    int posY = GetRandomValue(0, rows - 1); // Random Y position within grid
    Vector2 randomPosition = {(float)posX * cellSize,
                              (float)posY * cellSize}; // Scale to cell size
    return randomPosition;
}

// check for Border Collisions
bool borderCollision(Node *head, int screenWidth, int screenHeight,
                     int cellSize) {
    if (head->position.x <= -5 ||
        head->position.x >= screenWidth - cellSize + 5 ||
        head->position.y <= -5 ||
        head->position.y >= screenHeight - cellSize + 5) {
        return true;
    }
    return false;
}

// check for Food Collisions
bool foodCollision(Node *head, Rectangle *rect) {
    if (CheckCollisionRecs(head->rect, *rect)) {
        return true;
    }
    return false;
}

// check Body Collisions
bool bodyCollision(Node *head) {
    Node *helpptr = head;
    helpptr = helpptr->next;
    while (helpptr->next != NULL) {
        if (CheckCollisionRecs(head->rect, helpptr->rect)) {
            return true;
        }
        helpptr = helpptr->next;
    }
    return false;
}
