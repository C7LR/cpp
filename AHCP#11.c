/*Cesar Lozada*/

#include<stdio.h>
#include<stdlib.h>

void gradePrinter(int *gradeList, int listLength){
    for(int i=0; i<listLength; ++i){
        printf("%d ", gradeList[i]);
    }
    printf("\n\n");
}


void switcher(int *gradeList, int listLength){
    for(int i=0; i<listLength; ++i){
        if((gradeList[i]<70)&&(gradeList[i]>59)){
            gradeList[i] += 10;
        }
    }
}

int main(){
    int finalExam[15]={90,82,65,79,67,82,94,64,88,78,92,61,96,83,74};

    printf("Scores before changing:\n");
    gradePrinter(finalExam,15);
    switcher(finalExam,15);
    printf("Scores after changing:\n");
    gradePrinter(finalExam,15);

    return 0;
}