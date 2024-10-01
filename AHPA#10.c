/*Cesar Lozada*/

#include<stdio.h>
#include<stdlib.h>


int arraySum(int array[], int arrayLngth){
    int arraySum = 0;
    for (int i=1; i<arrayLngth; ++i){
        arraySum+=array[i];
    }
    return arraySum;
}

void arrayPrinter(int array[], int arrayLnght){
    /**/
    for(int i=0; i<arrayLnght; ++i){
        printf("%d ",array[i]);
    }
    printf("\n\n");
}

void updateArray(int array[], int arrayLnght){
    /**/
    int userInput1, userInput2, userInput3;
    printf("Enter first value: ");
    scanf("%d",&userInput1);
    printf("Enter second value: ");
    scanf("%d",&userInput2);
    printf("Enter third value: ");
    scanf("%d",&userInput3);
    if (arrayLnght>=10){
        int *update = &array[3];
        *update = userInput1;
        update = &array[6];
        *update = userInput2;
        update = &array[9];
        *update = userInput3;
        update = &array[0];
        *update=arraySum(array,arrayLnght);
    }
    printf("Updated array contents:\n");
    arrayPrinter(array, arrayLnght);
}

int main(){
    /**/
    int theArray[10]={0,1,1,1,1,1,1,1,1,1};
    theArray[0]=arraySum(theArray,10);
    printf("Original array contents:\n");
    arrayPrinter(theArray,10);
    updateArray(theArray,10);

    return 0;
}