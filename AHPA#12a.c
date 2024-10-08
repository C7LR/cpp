/*Cesar Lozada*/

#include<stdio.h>

//Prints score of an array.
void gradePrinter(int *gradeScores, int listLength){
    for(int i=0; i<listLength; ++i){
        printf("%d ", gradeScores[i]);
    }
    printf("\n\n");
}

int main(){
    int finalExams[10]={0};
    int *startPtr = &finalExams[0];
    int *endPtr = &finalExams[4];
    int *testPtr;

    int *pv = finalExams;
    gradePrinter(pv,10);

    int scores[5]={90,82,65,79,67};
    for(int s = 0; s<5; ++s){
        finalExams[s] = scores[s];
    }
    gradePrinter(pv,10);

    finalExams[5]=81;
    finalExams[6]=72;
    gradePrinter(pv,10);

    //testPtr = startPtr - endPtr;
    printf("%d\n",testPtr);
    //testPtr = 5;
    printf("%d\n",testPtr);



    return 0;
}