#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int min, max, number, guess, guesses;
    srand(time(NULL));
    guesses = 0;
    min = 0;
    max = 250;
    number = rand() % max + 1;
    
    do{
        printf("Enter a number between %d and %d: ", min, max);
        scanf("%d", &guess);

        guesses++;

        if (guess < number){
            printf("The number is bigger then %d\n", guess);
        }
        else if (guess > number) {
            printf("The number is smaller then %d\n", guess);
        }
        else{
            printf("Congratulations! The number is %d\n it took you %d guesses!", guess, guesses);
        }
            
    } while (guess != number);
}
