#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define WIDTH 40
#define HEIGHT 20
#define PACMAN 'C'
#define WALL '#'
#define FOOD '.'
#define DEMON 'X'
#define EMPTY ' '

int res = 0;
int pacman_x, pacman_y;
char board[HEIGHT][WIDTH];
int score = 0;
int food = 0;

// Function to initialize the game board
void initialize() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Creating border walls
            if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1) {
                board[i][j] = WALL;
            } else {
                board[i][j] = EMPTY;  // Place food on all empty cells
            }
        }
    }
     
    // Place random walls
    for (int count = 50; count > 0; count--) { 
        int i = rand() % HEIGHT;  // Correcting to rand() % HEIGHT
        int j = rand() % WIDTH;   // Correcting to rand() % WIDTH
        if (board[i][j] == EMPTY) { 
            board[i][j] = WALL; 
        } 
    }

    // Place horizontal walls
    for (int val = 5; val != 0; val--) { 
        int i = rand() % HEIGHT;
        for (int j = 3; j < WIDTH - 3; j++) { 
            if (board[i][j] == EMPTY) {  
                board[i][j] = WALL;
            }
        }
    }

    // Place demons
    int demonsPlaced = 0;
    while (demonsPlaced < 10) { 
        int i = rand() % HEIGHT; 
        int j = rand() % WIDTH; 
        if (board[i][j] == EMPTY) { 
            board[i][j] = DEMON; 
            demonsPlaced++;  
        }
    }

    // Place food
     for (int i = 0; i < HEIGHT; i++) { 
        for (int j = 0; j < WIDTH; j++) { 
            if (i % 2 == 0 && j % 2 == 0 && board[i][j] != WALL && board[i][j] != DEMON && board[i][j] != PACMAN) { 
  
                board[i][j] = FOOD; 
                food++; 
            } 
        } 
     }
    // Place Pac-Man
    pacman_x = HEIGHT / 2;
    pacman_y = WIDTH / 2;
    board[pacman_x][pacman_y] = PACMAN;
}

// Function to display the game board
void draw() {
    system("cls"); // Clear the screen (Windows only)
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

// Function to move Pac-Man
void movePacman(int dx, int dy) {
    int new_x = pacman_x + dx;
    int new_y = pacman_y + dy;

    // Check for collision with walls
    if (board[new_x][new_y] != WALL) { 
        if (board[new_x][new_y] == FOOD) { 
            score++; 
            food--;  
            if (food == 0) { 
                res = 2; 
                return; 
            } 
        } else if (board[new_x][new_y] == DEMON) { 
            res = 1; 
            return; // Stop the game immediately after colliding with a demon
        }

        // Clear the old position and move Pac-Man
        board[pacman_x][pacman_y] = EMPTY;
        pacman_x = new_x;
        pacman_y = new_y;
        board[pacman_x][pacman_y] = PACMAN;
    }
}

// Main function
int main() {
    initialize();

    char input;
    printf("Use W (up), S (down), A (left), D (right). Press Q to quit.\n");
    printf("Press any key to start!\n");
    getch();

    while (1) {
        draw();

        // Getting user input using getch() for instant response
        input = getch();

        switch (input) {
            case 'w': movePacman(-1, 0); break;
            case 's': movePacman(1, 0); break;
            case 'a': movePacman(0, -1); break;
            case 'd': movePacman(0, 1); break;
            case 'q': 
                printf("Game Over! Final Score: %d\n", score);
                return 0; // Exit the game
        }

        if (res == 1) { 
            printf("Game Over! Dead by Demon\nYour Score: %d\n", score); 
            break; 
        } 
        if (res == 2) { 
            printf("You Win! Your Score: %d\n", score); 
            break; 
        } 
    }

    return 0;
}
