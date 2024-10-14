/*
*COP 3515 - Fall Semester 2024
*
*Homework #2: Spotting The Hacker
*
*Cesar Lozada
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>


int parityCheck(char *datafile, int fileNameLenght){
    FILE*data;
    data = fopen(datafile, "r");
    if(data == NULL){
        printf("Error in opening file");
        return 1;
    } else {printf("Parity Check Processing...\n\n");}
    
    int lineCounter=1;
    char line[50];
    while(fgets(line, 40, data)!=NULL){
        printf("Transmission line number: %d\n", lineCounter++);
        
        int bytes[9];
        int binaryBytes[9][8]={{0,0,0,0,0,0,0,0}};
        sscanf(line,"%d %d %d %d %d %d %d %d %d",&bytes[0],&bytes[1],&bytes[2],
        &bytes[3], &bytes[4],&bytes[5],&bytes[6],&bytes[7],&bytes[8]);
        printf("Data Stream:\n");
        printf("%d %d %d %d %d %d %d %d\n",bytes[0],bytes[1],bytes[2],
        bytes[3], bytes[4],bytes[5],bytes[6],bytes[7]);
        printf("Parity byte: %d\n\n",bytes[8]);

        for(int b=0; b<9; b++){
            int byte = bytes[b];
            int binary[8]={0,0,0,0,0,0,0,0};
            int bit = 7;
            while(byte != 0){
                if(byte%2==1){
                    binary[bit]=1;
                }
                byte/=2;
                byte = (int)byte;
                bit-=1;
            }
            int copy = 0;
            while(copy<8){
                binaryBytes[b][copy] = binary[copy];
                copy+=1;
            }
        }

        bool evenParityCheck = true;
        bool oddParityCheck = false;
        for(int b=0; b<8; b++){
            int counter = 0;
            int parityBit = 0;
            for(int f=0; f<8; f++){
                if(binaryBytes[b][f]==1){
                    counter+=1;
                }
            }
            parityBit = binaryBytes[8][b];

            //Even parity check
            if(((counter%2==0)&&(parityBit==0))||((counter%2==1)&&(parityBit==1))){
                printf("No error in transmission byte: %d\n", bytes[b]);
            }else{printf("Error in transmission byte: %d\n", bytes[b]);}

            counter = 0;
        }
        printf("\n");
   
    }
    fclose(data);
    printf("\n");

}

int checkSum(char *datafile, int fileNameLenght){
    FILE*bytes;
    bytes = fopen(datafile, "r");
    if(bytes == NULL){
        printf("Error in opening file");
        return 1;
    } else {printf("Checksum Processing...\n");}


    fclose(bytes);
}

int twoDimensionalParityCheck(char *datafile, int fileNameLenght){
    FILE*bytes;
    bytes = fopen(datafile, "r");
    if(bytes == NULL){
        printf("Error in opening file");
        return 1;
    } else {printf("2D Parity Check Processing...\n");}

    fclose(bytes);
}


int main(){
    char *dataFiles[] = {
    "White House Transmission Data - Parity.txt",
    "White House Transmission Data - Checksum.txt",
    "White House Transmission Data - 2D Parity.txt"};

    int transmission = 1;
    for(int d=0;d<3;d++){
        printf("Checking data file: %d\n", transmission++);

        int nameLenght = strlen(dataFiles[d]);
        if(strstr(dataFiles[d],"Parity")){
            if(strstr(dataFiles[d], "2D Parity")){
                twoDimensionalParityCheck(dataFiles[d], nameLenght);
            } else{parityCheck(dataFiles[d], nameLenght);}

        }
        if(strstr(dataFiles[d],"Checksum")){
            checkSum(dataFiles[d], nameLenght);
        }
    }
    return 0;
}