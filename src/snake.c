#include "snake.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the snake with given parameters
void initSnake(Snake *snake, int cellSize, int length, int maxBodyLength,
               Direction direction) {
    snake->head = NULL;                   // Start with no segments
    snake->direction = direction;         // Initial direction of the snake
    snake->maxBodyLength = maxBodyLength; // Maximum allowed length of the snake
    snake->bodyLength = length;           // Current length of the snake
    snake->cellSize = cellSize;           // Size of each cell in the grid
}

// Create a new node for the snake
Node *createNode(Vector2 *pos, Direction direction, Node *prev, Node *next,
                 int cellSize) {
    Node *newNode =
        (Node *)malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode == NULL) {
        fprintf(stderr,
                "Failed to create Node"); // Error handling if allocation fails
        return NULL;
    }
    newNode->direction = direction; // Set node direction
    newNode->position = *pos;       // Set node position
    newNode->previous = prev;       // Link to previous node
    newNode->next = next;           // Link to next node
    newNode->rect = (Rectangle){pos->x, pos->y, cellSize, cellSize};
    return newNode;
}

// Print the details of each node in the snake (for debugging purposes)
void printNode(Node *head) {
    Node *helpptr = head;
    while (helpptr != NULL) {
        printf("ptr: %p\n", helpptr);             // Print current node address
        printf("NEXT: %p\n", helpptr->next);      // Print next node address
        printf("PREVV: %p\n", helpptr->previous); // Print previous node address
        helpptr = helpptr->next;                  // Move to next node
    }
}

// Add a new body node at the end of the snake
void addBodyNode(Node *head, int cellSize) {
    Node *helpptr = head;
    Node *newNode = NULL;

    // Traverse to the end of the snake
    while (helpptr->next != NULL) {
        helpptr = helpptr->next;
    }
    Vector2 new = {-(float)cellSize, 0.0}; // Offset for the new node position
    Vector2 res = Vector2Add(helpptr->position, new); // Calculate new position
    newNode = createNode(&res, helpptr->direction, helpptr, NULL,
                         cellSize); // Create the new node
    helpptr->next = newNode;        // Link the new node to the snake
}

// Update the snake's position and handle movement
void updateSnake(Node **head, Direction direction, Vector2 *moveDirection,
                 int cellSize) {
    Node *helpptr = *head;
    Node *helpptrTail = *head;

    // Traverse to the tail of the snake
    while (helpptrTail->next != NULL) {
        helpptrTail = helpptrTail->next;
    }
    // Set the previous node as the new tail and free the old tail
    Node *newTail = helpptrTail->previous;
    newTail->next = NULL;
    free(helpptrTail);

    // Create a new head node with updated position
    Vector2 newPosition = Vector2Add(*moveDirection, helpptr->position);
    Node *newNode =
        createNode(&newPosition, direction, NULL, helpptr, cellSize);
    helpptr->previous = newNode;
    *head = newNode;
}

// Draw the snake on the screen
void drawSnake(Node *head, int cellSize, Color headColor, Color bodyColor) {
    Node *current = head;
    while (current != NULL) {
        // Draw the head in a different color
        if (current == head) {
            DrawRectangleRec(head->rect, headColor);
        } else {
            // Draw the rest of the body
            DrawRectangle(current->position.x, current->position.y, cellSize,
                          cellSize, bodyColor);
        }
        current = current->next; // Move to the next node
    }
}

// Build the Snake
void buildSnake(Node **head, int length, Vector2 *headPosition, int cellSize) {

    for (int i = 0; i < length; i++) {
        if (i == 0) {
            // Create the head node
            *head = createNode(headPosition, UP, NULL, NULL, cellSize);
        } else {
            // Add body nodes
            addBodyNode(*head, cellSize);
        }
    }
};
// Free all nodes in the snake and release memory
void deleteSnake(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next; // Store the next node
        free(current);              // Free the current node
        current = next;             // Move to the next node
    }
}
