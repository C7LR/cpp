/* Cesar Lozada*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    //Initializes 23 char letter variables.
    char letter1, letter2, letter3, letter4, letter5, 
    letter6, letter7, letter8, letter9, letter10,
    letter11, letter12, letter13, letter14, letter15,
    letter16, letter17, letter18, letter19, letter20,
    letter21, letter22, letter23;

    //Creates file pointer message.
    //Then it opens and reads the file "clearMessage.txt".
    //If file pointer message returns as a NULL, it will print a message
    //saying theres a "Error in opening file" and return the value 1.
    FILE *message;
    message = fopen("clearMessage.txt", "r");
    if (message == NULL){
        printf("Error in opening file.\n");
        return 1;
    }

    //Each char letter variable will then read an individual character (up to 23 characters)
    //from the message contained in the "clearMessage.txt" file.
    //Each variable will corrispond to an individual character that makes up the message
    //in the file.
    letter1 = fgetc(message);
    letter2 = fgetc(message);
    letter3 = fgetc(message);
    letter4 = fgetc(message);
    letter5 = fgetc(message);
    letter6 = fgetc(message);
    letter7 = fgetc(message);
    letter8 = fgetc(message);
    letter9 = fgetc(message);
    letter10 = fgetc(message);
    letter11 = fgetc(message);
    letter12 = fgetc(message);
    letter13 = fgetc(message);
    letter14 = fgetc(message);
    letter15 = fgetc(message);
    letter16 = fgetc(message);
    letter17 = fgetc(message);
    letter18 = fgetc(message);
    letter19 = fgetc(message);
    letter20 = fgetc(message);
    letter21 = fgetc(message);
    letter22 = fgetc(message);
    letter23 = fgetc(message);

    //Each char letter variable's characcter is then converted into their 
    //repective ASCII int value and assigned to a letter#NumEquivalent int variable.
    //Each letter#NumEquivalent is then compared to determine whetehr they are a
    //value representing the alaphabet or some other character.
    //If the letter#NumEquivalent is between the value of 65-90(A-Z) or 97-122(a-z),
    //then the letter#NumEquivalent is shifted to the right through adding 3 to its repective value.
    //If the letter#NumEquivalent is not within these parameters, then letter#NumEquivalent is left
    //unaltered. (It is not a letter of alpahbet.)
    //Finally, each letter#NumEquivalent is then returned to a character based on their ASCII
    //decimal value and assined to their respective encryptedLetter char variable.
    //This proscess adds the shift by 3, ceaser cypher to the message.
    int letter1NumEquivalent = (int)letter1;
    if ((letter1NumEquivalent >= 65 && letter1NumEquivalent <= 90) || 
    (letter1NumEquivalent >= 97 && letter1NumEquivalent <=122)){
        letter1NumEquivalent += 3;
    }
    char encryptedLetter1 = (char)letter1NumEquivalent;

    int letter2NumEquivalent = (int)letter2;
    if ((letter2NumEquivalent >= 65 && letter2NumEquivalent <= 90) || 
    (letter2NumEquivalent >= 97 && letter2NumEquivalent <=122)){
        letter2NumEquivalent += 3;
    }
    char encryptedLetter2 = (char)letter2NumEquivalent;

    int letter3NumEquivalent = (int)letter3;
    if ((letter3NumEquivalent >= 65 && letter3NumEquivalent <= 90) || 
    (letter3NumEquivalent >= 97 && letter3NumEquivalent <=122)){
        letter3NumEquivalent += 3;
    }
    char encryptedLetter3 = (char)letter3NumEquivalent;

    int letter4NumEquivalent = (int)letter4;
    if ((letter4NumEquivalent >= 65 && letter4NumEquivalent <= 90) || 
    (letter4NumEquivalent >= 97 && letter4NumEquivalent <=122)){
        letter4NumEquivalent += 3;
    }
    char encryptedLetter4 = (char)letter4NumEquivalent;

    int letter5NumEquivalent = (int)letter5;
    if ((letter5NumEquivalent >= 65 && letter5NumEquivalent <= 90) || 
    (letter5NumEquivalent >= 97 && letter5NumEquivalent <=122)){
        letter5NumEquivalent += 3;
    }
    char encryptedLetter5 = (char)letter5NumEquivalent;

    int letter6NumEquivalent = (int)letter6;
    if ((letter6NumEquivalent >= 65 && letter6NumEquivalent <= 90) || 
    (letter6NumEquivalent >= 97 && letter6NumEquivalent <=122)){
        letter6NumEquivalent += 3;
    }
    char encryptedLetter6 = (char)letter6NumEquivalent;

    int letter7NumEquivalent = (int)letter7;
    if ((letter7NumEquivalent >= 65 && letter7NumEquivalent <= 90) || 
    (letter7NumEquivalent >= 97 && letter7NumEquivalent <=122)){
        letter7NumEquivalent += 3;
    }
    char encryptedLetter7 = (char)letter7NumEquivalent;

    int letter8NumEquivalent = (int)letter8;
    if ((letter8NumEquivalent >= 65 && letter8NumEquivalent <= 90) || 
    (letter8NumEquivalent >= 97 && letter8NumEquivalent <=122)){
        letter8NumEquivalent += 3;
    }
    char encryptedLetter8 = (char)letter8NumEquivalent;

    int letter9NumEquivalent = (int)letter9;
    if ((letter9NumEquivalent >= 65 && letter9NumEquivalent <= 90) || 
    (letter9NumEquivalent >= 97 && letter9NumEquivalent <=122)){
        letter9NumEquivalent += 3;
    }
    char encryptedLetter9 = (char)letter9NumEquivalent;

    int letter10NumEquivalent = (int)letter10;
    if ((letter10NumEquivalent >= 65 && letter10NumEquivalent <= 90) || 
    (letter10NumEquivalent >= 97 && letter10NumEquivalent <=122)){
        letter10NumEquivalent += 3;
    }
    char encryptedLetter10 = (char)letter10NumEquivalent;

    int letter11NumEquivalent = (int)letter11;
    if ((letter11NumEquivalent >= 65 && letter11NumEquivalent <= 90) || 
    (letter11NumEquivalent >= 97 && letter11NumEquivalent <=122)){
        letter11NumEquivalent += 3;
    }
    char encryptedLetter11 = (char)letter11NumEquivalent;

    int letter12NumEquivalent = (int)letter12;
    if ((letter12NumEquivalent >= 65 && letter12NumEquivalent <= 90) || 
    (letter12NumEquivalent >= 97 && letter12NumEquivalent <=122)){
        letter12NumEquivalent += 3;
    }
    char encryptedLetter12 = (char)letter12NumEquivalent;

    int letter13NumEquivalent = (int)letter13;
    if ((letter13NumEquivalent >= 65 && letter13NumEquivalent <= 90) || 
    (letter13NumEquivalent >= 97 && letter13NumEquivalent <=122)){
        letter13NumEquivalent += 3;
    }
    char encryptedLetter13 = (char)letter13NumEquivalent;

    int letter14NumEquivalent = (int)letter14;
    if ((letter14NumEquivalent >= 65 && letter14NumEquivalent <= 90) || 
    (letter14NumEquivalent >= 97 && letter14NumEquivalent <=122)){
        letter14NumEquivalent += 3;
    }
    char encryptedLetter14 = (char)letter14NumEquivalent;

    int letter15NumEquivalent = (int)letter15;
    if ((letter15NumEquivalent >= 65 && letter15NumEquivalent <= 90) || 
    (letter15NumEquivalent >= 97 && letter15NumEquivalent <=122)){
        letter15NumEquivalent += 3;
    }
    char encryptedLetter15 = (char)letter15NumEquivalent;

    int letter16NumEquivalent = (int)letter16;
    if ((letter16NumEquivalent >= 65 && letter16NumEquivalent <= 90) || 
    (letter16NumEquivalent >= 97 && letter16NumEquivalent <=122)){
        letter16NumEquivalent += 3;
    }
    char encryptedLetter16 = (char)letter16NumEquivalent;

    int letter17NumEquivalent = (int)letter17;
    if ((letter17NumEquivalent >= 65 && letter17NumEquivalent <= 90) || 
    (letter17NumEquivalent >= 97 && letter17NumEquivalent <=122)){
        letter17NumEquivalent += 3;
    }
    char encryptedLetter17 = (char)letter17NumEquivalent;

    int letter18NumEquivalent = (int)letter18;
    if ((letter18NumEquivalent >= 65 && letter18NumEquivalent <= 90) || 
    (letter18NumEquivalent >= 97 && letter18NumEquivalent <=122)){
        letter18NumEquivalent += 3;
    }
    char encryptedLetter18 = (char)letter18NumEquivalent;

    int letter19NumEquivalent = (int)letter19;
    if ((letter19NumEquivalent >= 65 && letter19NumEquivalent <= 90) || 
    (letter19NumEquivalent >= 97 && letter19NumEquivalent <=122)){
        letter19NumEquivalent += 3;
    }
    char encryptedLetter19 = (char)letter19NumEquivalent;

    int letter20NumEquivalent = (int)letter20;
    if ((letter20NumEquivalent >= 65 && letter20NumEquivalent <= 90) || 
    (letter20NumEquivalent >= 97 && letter20NumEquivalent <=122)){
        letter20NumEquivalent += 3;
    }
    char encryptedLetter20 = (char)letter20NumEquivalent;
    
    int letter21NumEquivalent = (int)letter21;
    if ((letter21NumEquivalent >= 65 && letter21NumEquivalent <= 90) || 
    (letter21NumEquivalent >= 97 && letter21NumEquivalent <=122)){
        letter21NumEquivalent += 3;
    }
    char encryptedLetter21 = (char)letter21NumEquivalent;

    int letter22NumEquivalent = (int)letter22;
    if ((letter22NumEquivalent >= 65 && letter22NumEquivalent <= 90) || 
    (letter22NumEquivalent >= 97 && letter22NumEquivalent <=122)){
        letter22NumEquivalent += 3;
    }
    char encryptedLetter22 = (char)letter22NumEquivalent;

    int letter23NumEquivalent = (int)letter23;
    if ((letter23NumEquivalent >= 65 && letter23NumEquivalent <= 90) || 
    (letter23NumEquivalent >= 97 && letter23NumEquivalent <=122)){
        letter23NumEquivalent += 3;
    }
    char encryptedLetter23 = (char)letter23NumEquivalent;

    //Creates file pointer encryptedMessage.
    //Then opens a file by the name of "secretMessage.txt" to write in.
    //If the pointer is NULL then it prints the message "Error in new message."
    //and returns the value 1.
    //Then it writes the encrypted message of the clearMessage file
    //through compiling all the encrypted letters together in 
    //order to form the new encrypted message.
    //It then closses the file of "secretMessage.txt" and then closes the file for
    //"clearMessage.txt".
    FILE *encryptedMessage;
    encryptedMessage = fopen("secretMessage.text","w");
    if(encryptedMessage == NULL){
        printf("Error in new message.\n");
        return 1;
    }
    fprintf(encryptedMessage, 
    "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
    encryptedLetter1,encryptedLetter2,encryptedLetter3,encryptedLetter4,
    encryptedLetter5,encryptedLetter6,encryptedLetter7,encryptedLetter8,
    encryptedLetter9,encryptedLetter10,encryptedLetter11,encryptedLetter12,
    encryptedLetter13,encryptedLetter14,encryptedLetter15,encryptedLetter16,
    encryptedLetter17,encryptedLetter18,encryptedLetter19,encryptedLetter20,
    encryptedLetter21,encryptedLetter22,encryptedLetter23);
    fclose(encryptedMessage);

    fclose(message);


    return 0;
}
