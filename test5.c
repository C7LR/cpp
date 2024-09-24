#include <stdio.h>
#include <string.h>

int main(){
    char password[50]= "New eeVegas is supreme";
    
    int passLenght = strlen(password);
    int wcounter;
    for (int w = 0; w<passLenght; w++){
        char letter = password[w];
        if(w < passLenght){
            if ((letter == password[w+1])&&(letter == password[w+2])){
                printf("Sequence of repeated character detected");
                break;
            }
        }
        wcounter+=1;
        if(wcounter == passLenght){
            printf("done");
        }
    
    }

    return 0;
}