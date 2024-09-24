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
            printf("Minimum number of optional tests to pass: %d\n", numOpTest);
        } else printf("Optional tests are NOT allowed\n");
        
        char newLineSkip;
        newLineSkip=fgetc(fileContents);
        char newLineSkip2;
        newLineSkip2=fgetc(fileContents);

        char password[60];
        while ((fgets(password, 50, fileContents)!=NULL)){
            if (password == "\n"){
                continue;

            }else printf("Potential password: %s",password);
            int passed;
            int failed;
            if ((allowOpTest!=true)&&(allowPasPhrases!=true)){
                if (strlen(password) > maxLimit){
                    printf("The password must be fewer than %d characters.", maxLimit);
                    failed+=1;
                }else passed+=1;

                if (strlen(password) < minLimit){
                    printf("The password must be at least %d characters long.", minLimit);
                    failed+=1;
                }else passed+=1;

                
            }


            
        }


        fclose(fileContents);

    }

    return(0);
}
