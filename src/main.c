#include "food.h"
#include "game.h"
#include "settings.h"
#include "snake.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Initialize the snake
    initSnake(&snake, cellSize, initialSnakeLength, maxBodyLength, direction);

    // Initialize the game window
    InitWindow(screenWidth, screenHeight, "Retro Snake");

    // Set the game to run at 60 frames-per-second
    SetTargetFPS(60);

    // Set initial position for the snake's
    headPosition = getPosition(cellSize, columns - 10, rows);

    // Create the initial snake nodes
    buildSnake(&snake.head, initialSnakeLength, &headPosition, cellSize);

    // create the food
    foodPosition = getPosition(cellSize, columns, rows);
    Rectangle *rect = createFood(foodPosition, cellSize);

    // check that foodPosition is not on the Snake else recreate
    while (foodOnSnake(snake.head, rect)) {
        free(rect);
        foodPosition = getPosition(cellSize, columns, rows);
        rect = createFood(foodPosition, cellSize);
    }
    // for debugging
    // printNode(snake.head);

    float countTime = 0; // Timer to control snake movement

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        float deltaTime =
            GetFrameTime(); // Get the time elapsed since the last frame
        countTime += deltaTime;

        // Handle keyboard input to change snake direction
        if (IsKeyPressed(KEY_RIGHT) && snake.direction != LEFT) {
            snake.direction = RIGHT;
        }
        if (IsKeyPressed(KEY_LEFT) && snake.direction != RIGHT) {
            snake.direction = LEFT;
        }
        if (IsKeyPressed(KEY_UP) && snake.direction != DOWN) {
            snake.direction = UP;
        }
        if (IsKeyPressed(KEY_DOWN) && snake.direction != UP) {
            snake.direction = DOWN;
        }

        // Update snake moveDirection based on the direction
        switch (snake.direction) {
        case UP:
            snake.moveDirection.y = cellSize * -1.0f;
            snake.moveDirection.x = 0.0f;
            break;
        case DOWN:
            snake.moveDirection.y = (float)cellSize;
            snake.moveDirection.x = 0.0f;
            break;
        case LEFT:
            snake.moveDirection.x = cellSize * -1.0;
            snake.moveDirection.y = 0.0f;
            break;
        case RIGHT:
            snake.moveDirection.x = (float)cellSize;
            snake.moveDirection.y = 0.0f;
            break;
        }

        // Move the snake periodically
        if (countTime >= speed) {
            updateSnake(&snake.head, snake.direction, &snake.moveDirection,
                        cellSize);
            countTime = 0.0f;
        }

        // Draw everything on the screen
        BeginDrawing();
        ClearBackground(
            playgroundColor); // Clear the screen with playground color
        DrawRectangleRec(*rect, foodColor);                    // Draw the food
        drawSnake(snake.head, cellSize, headColor, bodyColor); // Draw the snake
        EndDrawing();

        // check for collisions
        if (borderCollision(snake.head, screenWidth, screenHeight, cellSize) ||
            bodyCollision(snake.head)) {
            deleteSnake(snake.head);
            snake.head = NULL;
            snake.direction = RIGHT;
            headPosition = getPosition(cellSize, columns - 10, rows);
            // Create the initial snake nodes
            buildSnake(&snake.head, initialSnakeLength, &headPosition,
                       cellSize);
        };
        if (foodCollision(snake.head, rect)) {
            free(rect);
            foodPosition = getPosition(cellSize, columns, rows);
            rect = createFood(foodPosition, cellSize);
            // check that foodPosition is not on the Snake else recreate
            while (foodOnSnake(snake.head, rect)) {
                free(rect);
                foodPosition = getPosition(cellSize, columns, rows);
                rect = createFood(foodPosition, cellSize);
            }
            addBodyNode(snake.head, cellSize);
        }
    }

    // Clean up and free memory
    free(rect);
    deleteSnake(snake.head);
    snake.head = NULL;

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
