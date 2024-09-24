


#include <stdio.h>
#include <string.h>

int main(){
    char password[50]= "New Vegas is supreme";
    
    int passLenght = strlen(password);
    for (int w = 0; w<passLenght; w++){
        int chCounter = 0;
        char letter= password[w];
        if (w < passLenght){
            printf("%c",letter);
        }
        for (int w = 0; w<passLenght; w++){
            if(letter == password[w]){
                chCounter+=1;
            }
        }
        if(chCounter > 1){
            printf("Repeated character detected.");
            break;
        }
        printf("=%d\n",chCounter);


    }
    return (0);

}