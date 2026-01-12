#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game settings
#define WIDTH 20
#define HEIGHT 15
#define MAX_SNAKE_LENGTH 100

// Direction constants
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Game structures
typedef struct {
    int x;
    int y;
} Position;

// Global variables
Position snake[MAX_SNAKE_LENGTH];
int snakeLength = 3;
Position fruit;
int direction = RIGHT;
int score = 0;
int gameOver = 0;

// Function to initialize the game
void initGame() {
    // Initialize snake in the middle
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;
    snake[1].x = WIDTH / 2 - 1;
    snake[1].y = HEIGHT / 2;
    snake[2].x = WIDTH / 2 - 2;
    snake[2].y = HEIGHT / 2;
    
    // Place first fruit randomly
    srand(time(NULL));
    fruit.x = rand() % WIDTH;
    fruit.y = rand() % HEIGHT;
}

// Function to draw the game board
void drawGame() {
    system("clear"); // Use "cls" on Windows, "clear" on Linux/Mac
    
    printf("\n===== SNAKE GAME =====\n");
    printf("Score: %d\n", score);
    printf("Controls: w=Up, s=Down, a=Left, d=Right, q=Quit\n\n");
    
    // Draw top border
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
    
    // Draw game area
    for (int y = 0; y < HEIGHT; y++) {
        printf("#"); // Left border
        
        for (int x = 0; x < WIDTH; x++) {
            int isSnake = 0;
            
            // Check if current position is snake head
            if (x == snake[0].x && y == snake[0].y) {
                printf("@"); // Snake head
                isSnake = 1;
            }
            // Check if current position is snake body
            else {
                for (int i = 1; i < snakeLength; i++) {
                    if (x == snake[i].x && y == snake[i].y) {
                        printf("*"); // Snake body
                        isSnake = 1;
                        break;
                    }
                }
            }
            
            // Check if current position is fruit
            if (!isSnake && x == fruit.x && y == fruit.y) {
                printf("O"); // Fruit
            }
            else if (!isSnake) {
                printf(" "); // Empty space
            }
        }
        
        printf("#\n"); // Right border
    }
    
    // Draw bottom border
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
}

// Function to handle user input
void getInput() {
    char input;
    printf("\nEnter move (w/a/s/d) or q to quit: ");
    scanf(" %c", &input);
    
    switch(input) {
        case 'w':
        case 'W':
            if (direction != DOWN) direction = UP;
            break;
        case 's':
        case 'S':
            if (direction != UP) direction = DOWN;
            break;
        case 'a':
        case 'A':
            if (direction != RIGHT) direction = LEFT;
            break;
        case 'd':
        case 'D':
            if (direction != LEFT) direction = RIGHT;
            break;
        case 'q':
        case 'Q':
            gameOver = 1;
            break;
    }
}

// Function to update game state
void updateGame() {
    // Move snake body (shift all segments)
    for (int i = snakeLength - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    
    // Move snake head based on direction
    switch(direction) {
        case UP:
            snake[0].y--;
            break;
        case DOWN:
            snake[0].y++;
            break;
        case LEFT:
            snake[0].x--;
            break;
        case RIGHT:
            snake[0].x++;
            break;
    }
    
    // Check collision with walls
    if (snake[0].x < 0 || snake[0].x >= WIDTH || 
        snake[0].y < 0 || snake[0].y >= HEIGHT) {
        gameOver = 1;
        return;
    }
    
    // Check collision with self
    for (int i = 1; i < snakeLength; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            gameOver = 1;
            return;
        }
    }
    
    // Check if snake ate fruit
    if (snake[0].x == fruit.x && snake[0].y == fruit.y) {
        score += 10;
        snakeLength++;
        
        // Place new fruit
        fruit.x = rand() % WIDTH;
        fruit.y = rand() % HEIGHT;
    }
}

// Main function
int main() {
    printf("Welcome to Snake Game!\n");
    printf("Press Enter to start...");
    getchar();
    
    initGame();
    
    // Main game loop
    while (!gameOver) {
        drawGame();
        getInput();
        updateGame();
    }
    
    // Game over screen
    printf("\n\n===== GAME OVER! =====\n");
    printf("Final Score: %d\n", score);
    printf("Snake Length: %d\n", snakeLength);
    printf("Thanks for playing!\n\n");
    
    return 0;
}