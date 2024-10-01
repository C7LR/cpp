/*Cesar Lozada*/

#include<stdio.h>

int arraySum(int array[], int arrayLngth){
    /**/
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
    printf("\n");

}

int main(){
    /**/
    int theArray[10]={0,1,1,1,1,1,1,1,1,1};
    theArray[0]=arraySum(theArray,10);
    printf("Original array contents:\n");
    arrayPrinter(theArray,10);
    


    return 0;
}