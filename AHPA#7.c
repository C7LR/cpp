/*Cesar Lozada*/

#include<stdio.h>

float FahtoCel(float Ftemp){
    return (Ftemp - 32) / 1.8;
}

float CeltoFah(float Ctemp){
    return (Ctemp * 1.8) + 32;
}


int main(){
    
    char tempType;
    float temp;

    printf("What type of temperature will you be entering (c/f)\n");
    tempType=getchar();

    printf("What temperature value should be converted?\n");
    scanf("%f",&temp);

    float convertedTemp;
    switch(tempType){
        case('c'):
            convertedTemp = CeltoFah(temp);
            printf("Given a Celsius temperature of %.2f,\n the equivalent Fahrenheit temperature is %.2f\n", 
            temp, convertedTemp);
            break;

        case('f'):
            convertedTemp = FahtoCel(temp);
            printf("Given a Fahrenheit temperature of %.2f,\n the equivalent Celsius temperature is %.2f\n",
            temp, convertedTemp);
            break;

        default:
            printf("Error, please input temperature type for conversion.\n");
            break;
    }


    return 0;
}