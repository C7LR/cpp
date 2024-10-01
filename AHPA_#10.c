/*Cesar Lozada*/

#include<stdio.h>
#include<stdlib.h>

int theArray[10]={0,1,1,1,1,1,1,1,1,1};

void theArraySum(){
    int arrayLnght = 10;
    int arraySum = 0;
    for (int i=1; i<arrayLnght; ++i){
        arraySum+=theArray[i];
    }
    theArray[0]=arraySum;
}

int main(){
    /**/
    theArraySum();
    int *array;
    printf("Original array contents:\n");
    for(int i=0; i<10; ++i){
        *array = theArray[i];
        printf("%d ", *array);
    }

    
    int userInput1, userInput2, userInput3;
    printf("\n\nEnter first value: ");
    scanf("%d",&userInput1);
    printf("Enter second value: ");
    scanf("%d",&userInput2);
    printf("Enter third value: ");
    scanf("%d",&userInput3);


    printf("Updated array contents:\n");
    for(int i=0; i<10; ++i){
        *array = theArray[i];
        if(i == 3){
            *array = userInput1;
        }
        if(i == 6){
            *array = userInput2;
        }
        if(i == 8){
            *array = userInput3;
        }
    }
    for(int i=0; i<10; ++i){
        *array = theArray[i];
        printf("%d ", *array);
    }
    theArraySum();

    return 0;
}