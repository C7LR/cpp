/*Cesar Lozada*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    //Prints a multiplication table from 1-12.
    //It first initializes x as int variable and assigns it the value 1.
    //Then 12 x varibales are printed with one x value staying unmodified,
    //while the other x values are each multiplied by a value ranging from 2 to 12.
    //For each loop, x is increased till it becomes 13 or greater,
    //at which point the loop will stop.
    printf("Multiplication Table:\n");
    for (int x = 1; x<13 ; x++){
        printf("%3d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n",
        x,x*2,x*3,x*4,x*5,x*6,x*7,x*8,x*9,x*10,x*11,x*12);
    }

    //Initiallizes a int variable for guessAnswer that is
    //then assigned a random number from 1-10.
    //Then initializes a int varaiable for guess.
    //Then it prompt's user to enter a guess from 1-10.
    //If guess is higher than guessAnswer it will print message
    //saying guess number is to high.
    //If guess is lower than guessAnswer it will print message
    //saying guess number is to low.
    //If guess is equal to guessAnswer it will print message
    //saying user guessed the guessAnswer.
    //Loop will continue till the guess is equal to the guessAnswer.
    int guessAnswer = (rand()%10)+1;
    int guess;
    do {
        printf("\nEnter your guess (1-10):\n");
        scanf("%d", &guess);

        if(guess < guessAnswer){
            printf("Too low!");
        }
        if (guess > guessAnswer){
            printf("Too high!");
        }
        if(guess == guessAnswer){
            printf("You guessed it!\n");
        }
    } while (guess != guessAnswer);
    return 0;
}
