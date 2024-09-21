/*Cesar Lozada*/

#include<stdio.h>

//Initializes custom function FahtoCel.
//Function takes a float input.
//Function then converts input into Celsius measurement.
//Celsius measurement is then returned.
float FahtoCel(float Ftemp){
    return (Ftemp - 32) / 1.8;
}

//Initializes custom function CeltoFah.
//Function takes a float input.
//Function then converts input into Fahrenheit measurement.
//Fahrenheit measurement is then returned.
float CeltoFah(float Ctemp){
    return (Ctemp * 1.8) + 32;
}


int main(){
    //Initialized char tempType variable and float temp variable.
    char tempType;
    float temp;

    //Asks user for temperature measurement's type between c-Celsius and f-Fahrenheit.
    //Assigns user's answer to tempType.
    //Then Asks user for temperature measurement.
    //Assigns measurement into temp.
    printf("What type of temperature will you be entering (c/f)\n");
    tempType=getchar();
    printf("What temperature value should be converted?\n");
    scanf("%f",&temp);

    //Initializes the float convertedTemp variable.
    //Then it checks the value of tempType inputed.
    //If tempType matches 'c', then the measurement will be converted from CeltoFah.
    //Then it will show meassage showing original temp and convertedTemp.
    //If tempType matches 'f', then the measurement will be converted from FahtoCel.
    //Then it will show meassage showing original temp and convertedTemp.
    //If tempType has no value or value is not c or f, then it will print error message.
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