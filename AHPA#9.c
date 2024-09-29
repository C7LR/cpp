/*Cesar Lozada*/

#include<stdio.h>
#include<stdlib.h>

//Initializes four int pump#Tank variables as global variable.
//Also assigns each tank their max capacity of gas(in gallons).
int pump1Tank=100, pump2Tank=75, pump3Tank=50, pump4Tank=150;

/*
Intializes carArrived function.
When called will add value one to static int carsInStation.
Depending on value of carsInSation will result in function returning a value from 1-4.
Represents car entering station and that it goes to a specific pump.
When carsInStation has value of 4, it will reset it's counter.
Represents Car has left one of the pumps.
*/
int carArrived(){
    static int carsInStation=0;
    carsInStation+=1;
    if(carsInStation == 1){
        return(1);
    }
    if(carsInStation == 2){
        return(2);
    }
    if(carsInStation == 3){
        return(3);
    }
    if(carsInStation == 4){
        carsInStation = 0;
        return(4);
    }
}

/*
Initializes refillRequired function.
Function takes an int pump value that represents specific pump in need of refuiling.
Depending on value entered function will refill specific pump#Tank to its specific max capacity.
Will aslo print message stating request was heard as well as notify whne process of refuiling 
has began and been completed.
*/
int refillRequired(int pump){
    if(pump == 1){
        printf("Request suceessfull. Pump 1 tank is being refueled.\n");
        while(pump1Tank<100){
            pump1Tank+=1;
        }
        printf("Pump1 tank has been refuled.\n\n");
    }
    if(pump == 2){
        printf("Request sucessfull. Pump 2 tank is being refueled.\n");
        while(pump2Tank<100){
            pump2Tank+=1;
        }
        printf("Pump 2 tank has been refuled.\n\n");
    }
    if(pump == 3){
        printf("Request suceessfull. Pump 3 tank is being refueled.\n");
        while(pump3Tank<100){
            pump3Tank+=1;
        }
        printf("Pump 3 tank has been refuled.\n\n");
    }
    if(pump == 4){
        printf("Request suceessfull. Pump 4 tank is being refueled.\n");
        while(pump4Tank<100){
            pump4Tank+=1;
        }
        printf("Pump 4 tank has been refuled.\n\n");
    }
    return 1;
}


int main(){
    /*
    Initializes gasSationHours int variable.
    Then asks query regarding number of hours gas station will be opened and will
    then assign user's answer to gasSationHours.
    */
    int gasStationHours;
    printf("Enter number of hours gas station will be opened.\n");
    scanf("%d",&gasStationHours);

    /*
    Initializes the int hoursPassed variables.
    Then creates a while loop the continues till hoursPassed is equal or greater to
    gasStationHours.
    In each loop, a switch will call on the carArrived function and be given a speific value.
    Depeding on value(which ranges from 1-4) case, the pump#Tank related to that specific number value
    will lose 10 gallons and it willprint message regarding how much gas in gallons is remaning in specific pump#Tank.
    If value that is not 1-4 is given to switch, default will trigger error message.
    If at any point a specific pump#Tank has less than 20 gallons of fuel remaining,
    it will print message requesting refuiling for specific pump#Tank.
    At which point it will call the refillRequired function and refill specific pump#Tank to its specific maximum.
    */
    int hoursPassed;
    while(hoursPassed < gasStationHours){
        switch (carArrived()){
            case(1):
                pump1Tank-=10;
                printf("Pump 1 tank has %d gallons of gas remaining.\n\n", pump1Tank);
                if(pump1Tank<20){
                    printf("Pump 1 tank is low, requesting refill truck...\n");
                    refillRequired(1);
                }
                break;
            case(2):
                pump2Tank-=10;
                printf("Pump 2 tank has %d gallons of gas remaining.\n\n", pump2Tank);
                if(pump2Tank<20){
                    printf("Pump 2 tank is low, requesting refill truck...\n");
                    refillRequired(2);
                }
                break;
            case(3):
                pump3Tank-=10;
                printf("Pump 3 tank has %d gallons of gas remaining.\n\n", pump3Tank);
                if(pump3Tank<20){
                    printf("Pump 3 tank is low, requesting refill truck...\n");
                    refillRequired(3);
                }
                break;
            case(4):
                pump4Tank-=10;
                printf("Pump 4 tank has %d gallons of gas remaining.\n\n", pump4Tank);
                if(pump4Tank<20){
                    printf("Pump 4 tank is low, requesting refill truck...\n");
                    refillRequired(4);
                }
                break;
            default:
                printf("Error: System Misconfiguration.\n\n");
                break;
        }
        hoursPassed+=1;
    }
    return(0);
}