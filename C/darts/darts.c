#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define SMALL 1
#define MEDIUM 5
#define LARGE 10

void calculateDistance(float x, float y, float *distance) {
    *distance = x * x + y * y;
    *distance = sqrt(*distance); //Pythagoras Theorem 
}

int main(void) {
    printf("Type \"Ctrl + D\" to end program\n");
    float x, y;
    float distance;
    int totalScore = 0;

    while (1) {
        int resultX, resultY;
        int bufferCleaner;
        
        printf("Enter 'x' coordinate of the dart: ");
        resultX = scanf("%f", &x); //validation happens at input
        while((bufferCleaner = getchar()) != '\n' && bufferCleaner != EOF); //This line cleans hanging characters left in input buffer if parsing was unsuccessful. For instance, if user types 't', parsing fails and 't' gets left in input (scanf expects a number since we wrote "%f"), which for the next input the 't' will already be there (in input buffer) and make the next input fail.

        if (resultX == EOF) break;
        if (resultX != 1) {
            fprintf(stderr, "Please enter real numbers.\n");
            continue;
        }  

        printf("Enter 'y' coordinate of the dart: ");
        resultY = scanf("%f", &y);
        while((bufferCleaner = getchar()) != '\n' && bufferCleaner != EOF);

        if (resultY == EOF) break;
        if (resultY != 1) {
            fprintf(stderr, "Please enter real numbers.\n");
            continue;
        }

        calculateDistance(x, y, &distance);
        if (distance > LARGE) {
            printf("Your score is 0.\n");
        } else if (distance <= LARGE && distance > MEDIUM) {
            totalScore += SMALL;
            printf("Your score is 1.\n");
        } else if (distance <= MEDIUM && distance > SMALL) {
            totalScore += MEDIUM;
            printf("Your score is 5.\n");
        } else {
            totalScore += LARGE;
            printf("Your score is 10.\n");
        }
    }
    printf("\nTotal score is: %d", totalScore);
    return 0;
}


//Instructions
// Calculate the points scored in a single toss of a Darts game.

// Darts is a game where players throw darts at a target.

// In our particular instance of the game, the target rewards 4 different amounts of points, depending on where the dart lands:

// If the dart lands outside the target, player earns no points (0 points).
// If the dart lands in the outer circle of the target, player earns 1 point.
// If the dart lands in the middle circle of the target, player earns 5 points.
// If the dart lands in the inner circle of the target, player earns 10 points.
// The outer circle has a radius of 10 units (this is equivalent to the total radius for the entire target), the middle circle a radius of 5 units, and the inner circle a radius of 1. Of course, they are all centered at the same point — that is, the circles are concentric defined by the coordinates (0, 0).

// Given a point in the target (defined by its Cartesian coordinates x and y, where x and y are real), calculate the correct score earned by a dart landing at that point.