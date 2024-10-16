#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

int blockCounter(char *datafile, int fileNameLenght){
    FILE*data;
    data = fopen(datafile, "r");
    if(data == NULL){
        printf("Error in opening file");
        return 1;
    } else {printf("2D Parity Check Processing...\n\n");}

    int numBlock=0;
    int numStreams=0;
    char line[90];
    int rowCounter=0;
    while(fgets(line, 80, data)!=NULL){
        if(rowCounter >= 8){
            rowCounter=0;
            break;
        }
        if(line[0] == '\n'){
            continue;
        }
        numStreams+=1;
    }
    numBlock = numStreams/8;

    printf("%d of Data Blocks found",numBlock);
    return numBlock;
    fclose(data);
}

int twoDimensionalParityCheck(char *datafile, int fileNameLenght){
    FILE*data;
    data = fopen(datafile, "r");
    if(data == NULL){
        printf("Error in opening file");
        return 1;
    } else {printf("2D Parity Check Processing...\n\n");}
    int lineCounter=1;
    char line[90];
    int errorVCounter=0;
    int errorHCounter=0;
    int dataStreams[8][10];
    int verticalBytes[8];
    int horizontalBytes[8];
    int verticalBinaryBytes[9][8];
    int horizontalBinaryBytes[9][8];
    int rowCounter=0;
    int block=blockCounter(datafile,fileNameLenght);

    printf("Processing Transmission Block: %d\n", lineCounter++);
    while(block>0){
        while(fgets(line, 80, data)!=NULL){
            if(rowCounter >= 8){
                rowCounter=0;
                break;
            }
            if(line[0] == '\n'){
                continue;
            }
            sscanf(line,"%d %d %d %d %d %d %d %d %d %d",&dataStreams[rowCounter][0],&dataStreams[rowCounter][1],
            &dataStreams[rowCounter][2],&dataStreams[rowCounter][3],&dataStreams[rowCounter][4],&dataStreams[rowCounter][5],
            &dataStreams[rowCounter][6],&dataStreams[rowCounter][7],&dataStreams[rowCounter][8],&dataStreams[rowCounter][9]);
            rowCounter+=1;
        }
        for(int b = 0; b<8; b++){
            printf("%4d %4d %4d %4d %4d %4d %4d %4d [V:%4d] [H:%4d]\n",dataStreams[b][0],dataStreams[b][1],
            dataStreams[b][2],dataStreams[b][3],dataStreams[b][4],dataStreams[b][5],
            dataStreams[b][6],dataStreams[b][7],dataStreams[b][8],dataStreams[b][9]);
        }
        printf("Data Streams:\n");

        //Verticalpairtycheck
        int tLine = 0;
        int collumnNumber = 0;
        while(collumnNumber<8){
            for(int b=0; b<8; b++){
                verticalBytes[b]=dataStreams[b][collumnNumber];
            }
            verticalBytes[8]=dataStreams[collumnNumber][8];
            printf("Vertical processing transmission line %d:\n", tLine++);
            printf("%d %d %d %d %d %d %d %d %d\n",verticalBytes[0],verticalBytes[1],verticalBytes[2],
            verticalBytes[3],verticalBytes[4],verticalBytes[5],verticalBytes[6],verticalBytes[7],verticalBytes[8]);

            for(int b=0; b<9; b++){
                int byte = verticalBytes[b];
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
                    verticalBinaryBytes[b][copy] = binary[copy];
                    copy+=1;
                }
            }
            printf("\n");
        
            for(int b=0; b<8; b++){
                int counter = 0;
                int parityBit = 0;
                for(int f=0; f<8; f++){
                    if(verticalBinaryBytes[b][f]==1){
                        counter+=1;
                    }
                }
                parityBit = verticalBinaryBytes[8][b];

                //odd parity check
                if(((counter%2==1)&&(parityBit==0))||((counter%2==0)&&(parityBit==1))){
                }else{ 
                errorVCounter+=1;
                }
                counter = 0;
            }
            printf("\n");
            collumnNumber++;
        }
        tLine = 0;
        collumnNumber=0;
        
        //Horizontalpatirycheck
        int rowNumber = 0;
        while(rowNumber<8){
            for(int b=0; b<8; b++){
                horizontalBytes[b]=dataStreams[rowNumber][b];
            }
            horizontalBytes[8]=dataStreams[rowNumber][9];
            printf("Horizontal processing transmission line %d:\n", tLine++);
            printf("%d %d %d %d %d %d %d %d %d\n",horizontalBytes[0],horizontalBytes[1],horizontalBytes[2],
            horizontalBytes[3],horizontalBytes[4],horizontalBytes[5],horizontalBytes[6],horizontalBytes[7],horizontalBytes[8]);

            for(int b=0; b<9; b++){
                int byte = horizontalBytes[b];
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
                    horizontalBinaryBytes[b][copy] = binary[copy];
                    copy+=1;
                }
            }
            printf("\n");

            for(int b=0; b<8; b++){
                int counter = 0;
                int parityBit = 0;
                for(int f=0; f<8; f++){
                    if(horizontalBinaryBytes[b][f]==1){
                        counter+=1;
                    }
                }
                parityBit = horizontalBinaryBytes[8][b];

                //odd parity check
                if(((counter%2==1)&&(parityBit==0))||((counter%2==0)&&(parityBit==1))){
                }else{ 
                errorHCounter+=1;
                }
                counter = 0;
            }
            printf("\n");
            rowNumber++;
        }
        tLine=0;
        rowNumber=0;
        if ((errorHCounter>0)&&(errorVCounter>0)){
            printf("An error has been found\n\n");
        }else{printf("No errors found\n\n");}
        errorHCounter=0;
        errorVCounter=0;
        block-=1;
    }
    fclose(data);
}





int main(){
    /*
    Program contains pointer char array that contains the names of each of the files.
    It will then measure the lenght of the names and make a function call with the datafiles name, and namelenght.
    */
    char *dataFiles[] = {
    "White House Transmission Data - Parity.txt",
    "White House Transmission Data - Checksum.txt",
    "White House Transmission Data - 2D Parity.txt"};

    int nameLenght;
    nameLenght = strlen(dataFiles[2]);
    twoDimensionalParityCheck(dataFiles[2], nameLenght);

    
    return 0;
}