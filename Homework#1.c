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
    /*
    *Initializes char 2-D array passwordFiles.
    *Then assigns each row with name of a password file.
    */
    char passwordFiles[3][30] = {"Proposed passwords #1.txt",
    "Proposed passwords #2.txt","Proposed passwords #3.txt"};

    //Initializes int fileNumber varaible array and assigns it value 1.
    int fileNumber = 1;
    for(int i=0;i<3;i++){
        /*
        *Creates for loop that opens the fileContents of each file in the fileName array.
        *If theres an issue accessing file, then error message will print.
        *Other wise it will print message saying its processing file number: (fileNumber).
        *Loop ends when value of int i varible is greater than value 3(Size of passwordFiles 2-D array).
        *Also initilizes bool allowOpTest and allowPasPhrases variables assigns them true value.
        *It wil also intializes int variables maxLimit, minLimit, minPhraselnght, and  variables.
        */
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
        int numOpTest;

        /*
        *It will then go through fileContents of each password file.
        *It will proceed to find the maxLimit and minLimit of a password's lenght and print them.
        *If file allowOpTest and allowPasPhrases by whether value given is 0-false or 1-true.
        *If value of allowOpTest is true, it will search of minimum numOpTest needed to pass 
        and print message saying optional tests are allowed and minimum required to pass.
        *If value of allowPassPhrase is true, it will look for minimum pass phrase lenght
        and will print message saying pass phrases are allowed and minimum lenght allowed for phrase.
        *If either is false, no it will print messsage indicating which or if neither are not allowed.
        */
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
        fscanf(fileContents,"%d",&allowOpTest);
        if (allowOpTest == true){
            printf("Optional tests are allowed\n");
            fscanf(fileContents,"%d", &numOpTest);
            printf("Minimum number of optional tests to pass: %d\n\n", numOpTest);
        } else printf("Optional tests are NOT allowed\n\n");
        //Skips newlines in files.
        char newLineSkip;
        newLineSkip=fgetc(fileContents);
        char newLineSkip2;
        newLineSkip2=fgetc(fileContents);

        /*
        *It will then initialize the char password variable.
        *This contains a specific password in a file.
        *In the loop, each password in a specific password file has and an accompaning newline.
        *Then it will proceed to initialize int passed and failed and variables and assigns them value 0. 
        *They contein number of tests passes or failed.
        *Then will intialize the bool reqTests# variables and assigns them value true.
        *They represent if password failed/passed a required test.
        *Then it will initialize int numLetters, numUppercase, numLowercase, numSymbols, and numSpaces and assigns them
        value of 0.
        *They contain number of letter, uppercase letters, lowercase letters, symbols and spaces in given password.
        *Then it will initialize int passlenght variable and assigns them lenght of password.
        *Then it will initialize bool isPassPhrase variable and assign it value false.
        *This will mark whether specific password is a pass phrase or not.
        *Then it will initialize int optionalPassed and assign it value 0.
        *This will contian number of optional tests passed by given password.
        *Then will intilize the bool opTests# variables and assigns them value true. 
        *They represent if password failed/passed an optional test.
        */
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

            /*REQUIRED TEST1
            *If passLenght is greater than maxLimit password fails test.
            *It will then change value of reqTest1 to false and add value 1 to failed variable.
            *If passLenght is less than maxLimit then password passed test.
            *Value of 1 will be given to passed variable.
            */
            if (passLenght > maxLimit){
                reqTest1 = false;
                failed+=1;
            }else passed+=1;

            /*REQUIRED TEST2
            *If passLenght is less than minLimit password fails test.
            *It will then change value of reqTest2 to false and add value 1 to failed variable.
            *If passLenght is less than minLimit then password passed test.
            *Value of 1 will be given to passed variable.
            */
            if (passLenght < minLimit){
                reqTest2 = false;
                failed+=1;
            }else passed+=1;

            /*REQUIRED TEST3
            *Before test is started, the repeatedSeq bool variable is initialized and assigned value of false.
            *Variable determines whether password has sequence of 3 or more repeated characters.
            *Then test will look at each letter in password in a for loop that ends when int w(assigned value of 0) 
            is greater than passLenght.
            *Char letter variable is then initialized and given value of each letter(AND character) in the password 
            within loop.
            *In the loop, as long as w is less than passLenght, it will check if the next two letters of the password
            are repeated.
            *If password is found to have three letters that are the same and next to each other, it
            will then add value 1 to failed, change value of reqTest3 to false, change value of repeatedSeq to true, 
            and break loop.
            *This means password has failed test.
            *If no repeated words are found, loop will naturally end.
            *Then if repeatedSeq is still false, then password has passed test3.
            *Value of 1 is added to Passed.
            */
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

            /*REQUIRED TEST4
            *Char character variable is then initialized and given value of each character in the password within loop.
            *Int chValue variable is also then initialized and given the int representation of value in character.
            *In loop, each chValue will then be checked by it value.
            *If value is between (97 and 122), then chValue is of a lowercase character.
            *It will proceed to add value of 1 to numLowercase.
            *If value is between (65 and 90), then chValue is of a uppercase character.
            *It will proceed to add value of 1 to numUppercase.
            *If value is between (48 and 57), then chValue is of an integer character.
            *It will proceed to add value of 1 to numNumbers.
            *If value is between (32 and 47) or (58 and 64) or (91 and 96) or (123 and 126), 
            then chValue is of a symbol character.
            *It will proceed to add value of 1 to numSymbols.
            *Additionally, if chValue is equal to 32, then chValue is of a space character.
            *It will also proceed to add value of 1 to numSpaces.
            *Loop will then end naturally(When int w is greater than passLenght).
            *After end of loop, numLetters is assigned value equal to numLowercase and numUppercase.
            *Finally, if numLetters, numNumbers, or numSymbols are equal zero, then password fails
            test.
            *It will then change value of reqTest4 to false, add value of 1 to failed.
            *If password is found to contain at least one symbol, number, or letter, it then passes.
            *Value of 1 is added to passed.
            */
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

            /*
            *If allowPasPhrases is still true and numSpaces is greater or equal to one,
            then it will check if password is a pass phrase.
            *If lenght of password is greated or equal to minPhraselnght then value of isPassPhrase will be
            changed to true.
            */
            if ((allowPasPhrases == true)&&(numSpaces >= 1)){
                if(passLenght >= minPhraselnght){
                    isPassPhrase = true;
                }
            }
            
            /*OPTIONAL TESTS
            *If allowOpTest has value true then password will take four additional test.
            *Else the Optional tests are ignored.
            */
            if((allowOpTest == true)){
                /*OPTIONAL TEST1
                *If numLowercase is greater or equal to value 1, password passes optional test.
                *Value 1 is added to passed and optional passed.
                *If numLowercase is less than 1, password fails optional test.
                *Value 1 is added to failed and opTest1 value is changed to false.
                */
                if (numLowercase>=1){
                    optionalPassed+=1;
                    passed+=1;
                }else{
                    failed+=1;
                    opTest1=false;
                }

                /*OPTIONAL TEST2
                *If numUppercase is greater or equal to value 1, password passes optional test.
                *Value 1 is added to passed and optional passed.
                *If numUppercase is less than 1, password fails optional test.
                *Value 1 is added to failed and opTest2 value is changed to false.
                */
                if (numUppercase>=1){
                    optionalPassed+=1;
                    passed+=1;
                }else{
                    failed+=1;
                    opTest2=false;
                }

                /*OPTIONAL TEST3
                *If numNumbers is greater or equal to value 2, password passes optional test.
                *Value 1 is added to passed and optional passed.
                *If numNumbers is less than 2, password fails optional test.
                *Value 1 is added to failed and opTest3 value is changed to false.
                */
                if (numNumbers >= 2){
                    optionalPassed+=1;
                    passed+=1;
                }else{
                    failed+=1;
                    opTest3=false;
                }
                
                /*OPTIONAL TEST4
                *If numSymbols is greater or equal to value 2, password passes optional test.
                *Value 1 is added to passed and optional passed.
                *If numSymbols is less than 2, password fails optional test.
                *Value 1 is added to failed and opTest4 value is changed to false.
                */
                if(numSymbols >= 2){
                    optionalPassed+=1;
                    passed+=1;
                }else{
                    failed+=1;
                    opTest4=false;
                }
            }

            //Prints total number of tests passed and failed of a particular password.
            printf("Failed Tests   :%d\n",failed);
            printf("Passed Tests   :%d\n",passed);

            //If value of a specific Test(reqTest# or opTest#) is false, then correlating error message will be printed.
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
            if((opTest1 == false)){
                printf("The password must contain at least one lowercase letter.\n");
            }
            if((opTest2 == false)){
                printf("The password must contain at least one uppercase letter.\n");
            }
            if((opTest3 == false)){
                printf("The password must contain at least two numbers.\n");
            }
            if((opTest4 == false)){
                printf("The password must contain at least two special characters.\n");
            }
            
            /*
            *If password is determined to be a pass phrase(isPassPhrase has value true) then, 
            it will print message saying password is a passphrase.
            *If not a passPhrase then(isPassPhrase has value false), 
            it will print message saying password is not a passphrase
            */
            if(isPassPhrase == true){
                printf("Is a Pass phrase      :True\n");
            }else printf("Is a Pass phrase      :False\n");

            /*
            *If allowOptest is true and given password is not a pass phrase, 
            then the password will be considered to be strong not only if four reqTests were passed(true) but also if 
            password was able to pass minimum numOpTest needed to pass.
            *If in consideration password fails 1 of the main reqTests or if optinalPassed is not equal or greater to numOPtest,
            then password will not be considered strong.
            *If allowOpTest is not true or if password is a pass phrase, then it will be considered strong only if it  
            passes the main four reqTests.
            *If it fails one of the main four reTests it will not be considered strong.
            */
            if((allowOpTest == true) && (isPassPhrase == false)){
                if(((reqTest1 == true)&&(reqTest2 == true)&&(reqTest3 == true)&&(reqTest4 == true))&&(optionalPassed>=numOpTest)){
                    printf("Strong?               :True\n");
                }else printf("Strong?               :False\n");
            }else{
                if((reqTest1 == true)&&(reqTest2 == true)&&(reqTest3 == true)&&(reqTest4 == true)){
                    printf("Strong?               :True\n");
                }else printf("Strong?               :False\n"); 
            }  

            /*
            *If allowOpTest is true then message displaying number of optionalPassed will be displayed.
            *Else it will print 2 newline characters.
            */
            if(allowOpTest != false){
                printf("Total optional tests passed: %d\n\n",optionalPassed);
            }else printf("\n\n"); 
        }
        //Finally, after all passwords are analysed in particular file, loop prints a newline and closes the file.
        printf("\n");
        fclose(fileContents);
    }
    return(0);
}
