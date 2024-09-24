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

        fscanf(fileContents,"%d",&maxLimit);
        printf("Maximum password lenght: %d\n",maxLimit);

        fscanf(fileContents,"%d",&minLimit);
        printf("Minimum password lenght: %d\n",minLimit);

        fscanf(fileContents,"%d",&allowPasPhrases);
        if (allowPasPhrases == true){
            printf("Pass pharases are allowed\n");
            int minlenght;
            fscanf(fileContents,"%d",&minlenght);
            printf("Minimum phrase lenght: %d\n", minlenght);
        } else printf("Pass pharases are NOT allowed\n");

        fscanf(fileContents,"%d",&allowOpTest);
        if (allowOpTest == true){
            printf("Optional tests are allowed\n");
            int numOpTest;
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
            int passLenght = strlen(password);

            if (passLenght > maxLimit){
                reqTest1 = false;
                failed+=1;
            }else passed+=1;

            bool isPassPhrase = false;
            if (passLenght < minLimit){
                reqTest2 = false;
                failed+=1;
                isPassPhrase = true;
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


            //optionaltestlocation


            printf("Failed Tests   :%d\n",failed);
            printf("Passed Tests   :%d\n",passed);


            if (reqTest1 == false){
                printf("The password must be fewer than %d characters.\n",maxLimit);
            }
            if(reqTest2 == false){
                printf("The password must be at least %d characters long.\n",minLimit);
            }
            if(reqTest3 == false){
                printf("The password may not contain sequence of three or more repeated characters.\n");
            }
            if(reqTest4 == false){
                printf("The password must contain letters, numbers, and symbols.");
            }

            if(isPassPhrase == true){
                printf("Is a Pass phrase      :True\n");
            }else printf("Is a Pass phrase      :False\n");
            
            if((reqTest1 == true)&&(reqTest2 == true)&&(reqTest3 == true)){
                printf("Strong?               :True\n");
            }else printf("Strong?               :False\n");

            
        }
        fclose(fileContents);
    }
    return(0);
}
