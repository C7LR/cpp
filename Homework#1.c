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

        int maxLimit;
        fscanf(fileContents,"%d",&maxLimit);
        printf("Maximum password lenght: %d\n",maxLimit);

        int minLimit;
        fscanf(fileContents,"%d",&minLimit);
        printf("Minimum password lenght: %d\n",minLimit);

        bool allowPasPhrases = true;
        fscanf(fileContents,"%d",&allowPasPhrases);
        if (allowPasPhrases == true){
            printf("Pass pharases are allowed\n");
            int minlenght;
            fscanf(fileContents,"%d",&minlenght);
            printf("Minimum phrase lenght: %d\n", minlenght);
        } else printf("Pass pharases are NOT allowed\n");

        bool allowOpTest = true;
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
            if (strlen(password) > maxLimit){
                printf("The password must be fewer than %d characters.\n", maxLimit);
                failed+=1;
            }else passed+=1;

            if (strlen(password) < minLimit){
                printf("The password must be at least %d characters long.\n", minLimit);
                failed+=1;
            }else passed+=1;

            int passLenght = strlen(password);
            bool repeatedSeq = false;
            for (int w = 0; w<passLenght; w++){
                char letter = password[w];
                if(w < passLenght){
                    if ((letter == password[w+1])&&(letter == password[w+2])){
                        printf("The password may not contain sequence of three or more repreated characters.\n");
                        failed+=1;
                        repeatedSeq = true;
                        break;
                    }
                }
            }
            if(repeatedSeq == false){
                passed+=1;
            }


            printf("Failed Tests   :%d\n",failed);
            printf("Passed Tests   :%d\n",passed);
            if ((allowPasPhrases != true) && (allowOpTest != true)){
                if(failed > 0){
                printf("Password failed - it cannot be used.\n\n");
                }else printf("Password passed - it is strong.\n\n");
            }
        }
        fclose(fileContents);
    }
    return(0);
}
