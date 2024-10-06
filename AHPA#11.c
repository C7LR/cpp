/*Cesar Lozada*/

#include<stdio.h>
#include<stdlib.h>

/*
Name: gradePrinter
Purpose: Prints the scores given to it by a gradeScore array.
Has 2 parameters:
    1)int *gradeScores: 
        -Declares int gradeScores pointer parameter.
        -Takes arguments for an array of a gradeList.
    2)int listLenght:
        -Declares int listLenght variable parameter.
        -Contains the lenght of an array.
Has no return value.
It only prints the value of an array.
*/
void gradePrinter(int *gradeScores, int listLength){
    for(int i=0; i<listLength; ++i){
        printf("%d ", gradeScores[i]);
    }
    printf("\n\n");
}

/*
Name: switcher
Purpose: Switches the D scores of a gradeScore to C scores by adding 10 points to the score.
Has 2 parameters:
    1)int *gradeScores: 
        -Declares int gradeScores pointer parameter.
        -Takes arguments for an array of a gradeScores.
    2)int listLenght:
        -Declares int listLenght variable parameter.
        -Contains the lenght of an array.
Has no return value.
It only modifies the value of an array through pointers.
*/
void switcher(int *gradeScores, int listLength){
    for(int i=0; i<listLength; ++i){
        if((gradeScores[i]<70)&&(gradeScores[i]>59)){
            gradeScores[i] += 10;
        }
    }
}

int main(){
    //Initializes int finalExam array.
    int finalExam[15]={90,82,65,79,67,82,94,64,88,78,92,61,96,83,74};

    /*
    Prints the unaltered finalExam array scores via the gradePrinter() function.
    Then alters the scores in the finalExam array with the switcher() function.
    Finally, it then prints the altered finalExam array scores via the gradePrinter() function.
    */
    printf("Scores before changing:\n");
    gradePrinter(finalExam,15);
    switcher(finalExam,15);
    printf("Scores after changing:\n");
    gradePrinter(finalExam,15);

    return 0;
}