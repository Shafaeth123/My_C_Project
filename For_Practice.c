#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store question, answer, and difficulty
typedef struct {
    char question[256];
    char options[4][100];
    char correctAnswer;
    int difficulty; // 1 = Easy, 2 = Moderate, 3 = Hard
} Question;

// Function to display questions and options
void askQuestion(Question q) {
    printf("\n%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i+1, q.options[i]);
    }
    printf("Your answer (1-4): ");
}

// Function to start the quiz game
void startQuiz(int level) {
    Question questions[] = {
        // Easy questions
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, '3', 1},
        {"Which planet is closest to the sun?", {"Venus", "Earth", "Mercury", "Mars"}, '3', 1},
        // Moderate questions
        {"Who won the FIFA World Cup in 2018?", {"Brazil", "France", "Germany", "Argentina"}, '2', 2},
        {"Which company developed Windows OS?", {"Apple", "Microsoft", "Google", "IBM"}, '2', 2},
        // Hard questions
        {"What is the largest desert in the world?", {"Sahara", "Gobi", "Arctic", "Kalahari"}, '3', 3},
        {"Who invented the theory of relativity?", {"Newton", "Einstein", "Tesla", "Galileo"}, '2', 3}
    };
    
    int totalQuestions = sizeof(questions) / sizeof(questions[0]);
    int score = 0;
    int qCount = 0;

    // Ask questions based on selected level
    for (int i = 0; i < totalQuestions; i++) {
        if (questions[i].difficulty == level) {
            askQuestion(questions[i]);
            char userAnswer;
            scanf(" %c", &userAnswer);

            // Check the answer
            if (userAnswer - '0' == questions[i].correctAnswer - '0') {
                score += 10; // Award 10 points for correct answer
                printf("Correct! You earned 10 points.\n");
            } else {
                printf("Wrong answer. The correct answer is %c.\n", questions[i].correctAnswer);
            }
            qCount++;
        }
    }

    printf("\nYou answered %d questions with a score of %d points.\n", qCount, score);
}

int main() {
    int level;
    printf("Welcome to the Quiz Game!\n");
    printf("Select difficulty level:\n");
    printf("1. Easy\n2. Moderate\n3. Hard\n");
    printf("Enter your choice: ");
    scanf("%d", &level);

    if (level < 1 || level > 3) {
        printf("Invalid choice, exiting game.\n");
        return 0;
    }

    startQuiz(level);
    return 0;
}
