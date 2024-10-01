/*Cesar Lozada*/

#include<stdio.h>
#include<stdlib.h>

//Initializes the int theArray variable and assigns it's values.
int theArray[10]={0,1,1,1,1,1,1,1,1,1};

/*
Name: theArraySum
Purpose: Store the sum of theArray values in within [0] index of theArray.
Has no parameter.
Has no return value.
It only alters theArraySum.
*/
void theArraySum(){
    int arraySum = 0;
    for (int i=1; i<10; ++i){
        arraySum+=theArray[i];
    }
    theArray[0]=arraySum;
}

/*
Name: theArrayPrinter
Purpose: Calls on theArraySum() function and prints theArray values.
Has no parameter.
Has no return value.
It only prints the values of the array.
*/
void theArrayPrinter(){
    theArraySum();
    for(int i=0; i<10; ++i){
        printf("%d ",theArray[i]);
    }
    printf("\n\n");
}

/*
Name: updateArray
Purpose: Alters the array through use of pointers to add the user values 101, 63, 21 into indexes, 3,6, and 9
of theArray. Once finished it calls on theArrayPrinter function.
Has no parameter.
Has no return value.
It only alters theArraySum and prints it values.
*/
void updateArray(){
    int userInput1 = 101, userInput2 = 63, userInput3 = 21;
    int *update = &theArray[3];
    *update = userInput1;
    update = &theArray[6];
    *update = userInput2;
    update = &theArray[9];
    *update = userInput3;
    theArrayPrinter();
}

int main(){
    /*
    Prints the unaltered array(theArray) via function call to the theArrayPrinter() function.
    Then prints the altered array via function call to the updateArray() function with its argument being the value 10.
    */
    printf("Original array contents:\n");
    theArrayPrinter();
    printf("Updated array contents:\n");
    updateArray();
    return 0;
}