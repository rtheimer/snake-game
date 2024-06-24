#ifndef SNAKE_H
#define SNAKE_H
#include <raylib.h>

// Food
Vector2 getPosition(int cellSize, int cols, int rows);

// Moving Directions
typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

typedef struct Node {
    Vector2 position;
    Direction direction;
    struct Node *previous;
    struct Node *next;
    int cellSize;
    Rectangle rect;
} Node;
// the SNAKE
typedef struct {
    Node *head;
    Direction direction;
    Vector2 moveDirection;
    int maxBodyLength;
    int bodyLength;
    int cellSize;
} Snake;

void printNode(Node *head);

void initSnake(Snake *snake, int cellsize, int lenght, int maxBodyLength,
               Direction direction);

Node *createNode(Vector2 *pos, Direction direction, Node *prev, Node *next,
                 int cellSize);

void addBodyNode(Node *head, int cellSize);

void updateSnake(Node **head, Direction direction, Vector2 *moveDirection,
                 int cellSize);

void drawSnake(Node *snakeNode, int cellSize, Color headColor, Color bodyColor);

void buildSnake(Node **head, int length, Vector2 *headposition, int cellSize);

void deleteSnake(Node *head);

#endif
