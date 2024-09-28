/*
*COP 3515-Fall Semester 2024
*
*Homework #1: Password Strenght Meter
*
*Cesar Lozada
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



int main(){
    char passwordFiles[3][30] = {"Proposed passwords #1.txt",
    "Proposed passwords #2.txt","Proposed passwords #3.txt"};

    int fileNumber = 1;
    for(int i=0;i<3;i++){
        FILE*fileContents;
        fileContents = fopen(passwordFiles[i],"r");
        if(fileContents == NULL){
            printf("Error opening file \"%s\"\n",passwordFiles[i]);
            return(1);
        }else printf("Processing password file #%d\n\n",fileNumber++);

        bool allowOpTest = true;
        bool allowPasPhrases = true;
        int maxLimit;
        int minLimit;
        int minPhraselnght;

        fscanf(fileContents,"%d",&maxLimit);
        printf("Maximum password lenght: %d\n",maxLimit);

        fscanf(fileContents,"%d",&minLimit);
        printf("Minimum password lenght: %d\n",minLimit);

        fscanf(fileContents,"%d",&allowPasPhrases);
        if (allowPasPhrases == true){
            printf("Pass pharases are allowed\n");
            fscanf(fileContents,"%d",&minPhraselnght);
            printf("Minimum phrase lenght: %d\n", minPhraselnght);
        } else printf("Pass pharases are NOT allowed\n");
        
        int numOpTest;
        fscanf(fileContents,"%d",&allowOpTest);
        if (allowOpTest == true){
            printf("Optional tests are allowed\n");
            fscanf(fileContents,"%d", &numOpTest);
            printf("Minimum number of optional tests to pass: %d\n\n", numOpTest);
        } else printf("Optional tests are NOT allowed\n\n");
        
        char newLineSkip;
        newLineSkip=fgetc(fileContents);
        char newLineSkip2;
        newLineSkip2=fgetc(fileContents);


        char password[100];
        while ((fgets(password, 80, fileContents)!=NULL)){
            printf("Potential password: %s",password);
            if (password[strlen(password)-1]!='\n'){
                printf("\n");
            }
            int passed = 0;
            int failed = 0;
            bool reqTest1=true;
            bool reqTest2=true;
            bool reqTest3=true;
            bool reqTest4=true;
            int numLetters=0;
            int numUppercase=0;
            int numLowercase=0;
            int numNumbers=0;
            int numSymbols=0;
            int numSpaces=0;
            int passLenght = strlen(password);
            bool isPassPhrase = false;
            int optionalPassed=0;
            bool opTest1=true;
            bool opTest2=true;
            bool opTest3=true;
            bool opTest4=true;

            if (passLenght > maxLimit){
                reqTest1 = false;
                failed+=1;
            }else passed+=1;

            if (passLenght < minLimit){
                reqTest2 = false;
                failed+=1;
            }else passed+=1;
            
            bool repeatedSeq = false;
            for (int w = 0; w<passLenght; w++){
                char letter = password[w];
                if(w < passLenght){
                    if ((letter == password[w+1])&&(letter == password[w+2])){
                        reqTest3 = false;
                        failed+=1;
                        repeatedSeq = true;
                        break;
                    }
                }
            }
            if(repeatedSeq == false){
                passed+=1;
            }

            for (int w = 0; w<passLenght; w++){
                char character= password[w];
                int chValue = (int)character;
                if((chValue >= 97)&&(chValue <=122)){
                    numLowercase+=1;
                }
                if((chValue >= 65)&&(chValue <= 90)){
                    numUppercase+=1;
                }
                if((chValue >= 48)&&(chValue<= 57)){
                    numNumbers+=1;
                }
                if(((chValue >= 32)&&(chValue <= 47))||((chValue >= 58)&&(chValue <= 64))||
                ((chValue >= 91)&&(chValue <= 96))||((chValue >= 123 )&&(chValue <= 126))){
                    numSymbols+=1;
                    if(chValue == 32){
                        numSpaces+=1;
                    }
                }
                    
            }
            numLetters = numLowercase + numUppercase;
            if((numLetters==0)||(numNumbers==0)||(numSymbols==0)){
                reqTest4=false;
                failed+=1;
            }else passed+=1;


            if ((allowPasPhrases == true)&&(numSpaces >= 1)){
                if(passLenght >= minPhraselnght){
                    isPassPhrase = true;
                }
            }

            if((allowOpTest == true)){
                if (numLowercase>=1){
                    optionalPassed+=1;
                    passed+=1;
                }else{
                    failed+=1;
                    opTest1=false;
                }

                if (numUppercase>=1){
                    optionalPassed+=1;
                    passed+=1;
                }else{
                    failed+=1;
                    opTest2=false;
                }

                if (numNumbers >= 2){
                    optionalPassed+=1;
                    passed+=1;
                }else{
                    failed+=1;
                    opTest3=false;
                }

                if(numSymbols >= 2){
                    optionalPassed+=1;
                    passed+=1;
                }else{
                    failed+=1;
                    opTest4=false;
                }
            }

            printf("Failed Tests   :%d\n",failed);
            printf("Passed Tests   :%d\n",passed);

            if(reqTest1 == false){
                printf("The password must be fewer than %d characters.\n",maxLimit);
            }
            if(reqTest2 == false){
                printf("The password must be at least %d characters long.\n",minLimit);
            }
            if(reqTest3 == false){
                printf("The password may not contain sequence of three or more repeated characters.\n");
            }
            if(reqTest4 == false){
                printf("The password must contain letters, numbers, AND symbols.\n");
            }
            if((opTest1 == false)&&(isPassPhrase==false)){
                printf("The password must contain at least one lowercase letter.\n");
            }
            if((opTest2 == false)&&(isPassPhrase==false)){
                printf("The password must contain at least one uppercase letter.\n");
            }
            if((opTest3 == false)&&(isPassPhrase==false)){
                printf("The password must contain at least two numbers.\n");
            }
            if((opTest4 == false)&&(isPassPhrase==false)){
                printf("The password must contain at least two special characters.\n");
            }
            
            if(isPassPhrase == true){
                printf("Is a Pass phrase      :True\n");
            }else printf("Is a Pass phrase      :False\n");

            if((allowOpTest == true) && (isPassPhrase == false)){
                if(((reqTest1 == true)&&(reqTest2 == true)&&(reqTest3 == true)&&(reqTest4 == true))&&(optionalPassed>=numOpTest)){
                    printf("Strong?               :True\n");
                }else printf("Strong?               :False\n");
            }else{
                if((reqTest1 == true)&&(reqTest2 == true)&&(reqTest3 == true)&&(reqTest4 == true)){
                    printf("Strong?               :True\n");
                }else printf("Strong?               :False\n"); 
            }  

            if(allowOpTest != false){
                printf("Total optional tests passed: %d\n\n",optionalPassed);
            }else printf("\n\n");
            

            
        }
        printf("\n");
        fclose(fileContents);
    }
    return(0);
}
