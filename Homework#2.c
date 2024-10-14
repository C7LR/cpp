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

/*
-parityCheck function:
Function recieves a datafile pointer and filenamelenght as parameters.
Uses parameters to access datafile and initate an even parityCheck.
Does so by isolating parity and rest of the bits in data row then compares them.
If the sum  of 1s that comprise a regular data string is even and the paring string is of value 0, or
if the sum of 1s is odd and the paring string is of value 1, then bits pass checks.
Else bits fail and a message will appear indicating error intransmission of data has occured.
*/

int parityCheck(char *datafile, int fileNameLenght){
    FILE*data;
    data = fopen(datafile, "r");
    if(data == NULL){
        printf("Error in opening file");
        return 1;
    } else {printf("Parity Check Processing...\n\n");}
    
    int lineCounter=1;
    char line[50];
    int errorCounter=0;
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
            }else{printf("Error in transmission byte: %d\n", bytes[b]);
            errorCounter+=1;
            }
            
            counter = 0;
        }
        printf("\n");

    }
    if(errorCounter>0){
        printf("An error has been found\n\n");
    }else{printf("No errors found\n\n");}

    fclose(data);
    printf("\n");
}

/*
-checkSum function:
Function recieves a datafile pointer and filenamelenght as parameters.
Uses parameters to access datafile and initate an sumCheck.
It sums the all values of a data row then adds them to the checkSum byte.
Then the byte is complimented.
If sum after being complimented is 0 for each data row, datafile pass checks.
Else a message will be printed indicating an error has been found.
*/
int checkSum(char *datafile, int fileNameLenght){
    FILE*data;
    data = fopen(datafile, "r");
    if(data == NULL){
        printf("Error in opening file");
        return 1;
    } else {printf("Checksum Processing...\n\n");}

    int lineCounter=1;
    char line[50];
    int errorCounter=0;
    while(fgets(line, 40, data)!=NULL){
        printf("Transmission line number: %d\n", lineCounter++);
        
        int bytes[9];
        sscanf(line,"%d %d %d %d %d %d %d %d %d",&bytes[0],&bytes[1],&bytes[2],
        &bytes[3], &bytes[4],&bytes[5],&bytes[6],&bytes[7],&bytes[8]);
        printf("Data Stream:\n");
        printf("%d %d %d %d %d %d %d %d\n",bytes[0],bytes[1],bytes[2],
        bytes[3], bytes[4],bytes[5],bytes[6],bytes[7]);
        printf("Checksum: %d\n\n",bytes[8]);

        unsigned int dataSum=0; 
        for(int b=0; b<8; b++){
            dataSum+=bytes[b];
        }
        printf("Sum of data items: %d\n", dataSum);

        dataSum += bytes[8];
        printf("Sum after adding checksum: %d\n", dataSum);

        unsigned int sumCompliment;
        sumCompliment = ~dataSum;
        sumCompliment %= 256;
        printf("Sum after compliment: %d\n", sumCompliment);

        if(sumCompliment == 0){
            printf("Checksum: No errors in transmission \n\n");
        }else{printf("Checksum: Errors found in transmission \n\n");
        errorCounter+=1;
        }
    }
    if(errorCounter>0){
        printf("An error has been found\n\n");
    }else{printf("No errors found\n\n");}
    fclose(data);
}


/*
-twoDimensionalParityCheck function:
Function recieves a datafile pointer and filenamelenght as parameters.
Uses parameters to access datafile and initate a 2D parity check.
Code attempts to isolate two parity bits from rest of bits present in data block.
Then repeats process done in parityCheck function but in two methods.
Method one checks each of the rows using a bit corresponding with the horizontall parity.
Method two checks each collumn using a bit corresponding with the vertical parity.
It will analyse each the bits of each row and collumn with repective parity bit.
If no error are found within any of the methods, a message will printed saying no errors have been found.
Else message saying errors have been found will be printed instead.
*/
int twoDimensionalParityCheck(char *datafile, int fileNameLenght){
    FILE*data;
    data = fopen(datafile, "r");
    if(data == NULL){
        printf("Error in opening file");
        return 1;
    } else {printf("2D Parity Check Processing...\n\n");}
    int lineCounter=1;
    char line[80];
    int errorVCounter=0;
    int errorHCounter=0;
    int dataStreams[8][10];
    int verticalBytes[8];
    int horizontalBytes[8];
    int verticalBinaryBytes[9][8];
    int horizontalBinaryBytes[9][8];
    int rowCounter=0;

    printf("Processing Transmission Block: %d\n", lineCounter++);
    while(fgets(line, 70, data)!=NULL){
        if(rowCounter >= 9){
            rowCounter=0;
            break;
        }
        sscanf(line,"%d %d %d %d %d %d %d %d %d %d",&dataStreams[rowCounter][0],&dataStreams[rowCounter][1],
        &dataStreams[rowCounter][2],&dataStreams[rowCounter][3],&dataStreams[rowCounter][4],&dataStreams[rowCounter][5],
        &dataStreams[rowCounter][6],&dataStreams[rowCounter][7],&dataStreams[rowCounter][8],&dataStreams[rowCounter][9]);
        rowCounter++;
    }
    for(int b = 0; b<8; b++){
        printf("%d %d %d %d %d %d %d %d [V:%4d] [H:%4d]\n",dataStreams[b][0],dataStreams[b][1],
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




    //block2
    printf("Processing Transmission Block: %d\n", lineCounter++);
    while(fgets(line, 70, data)!=NULL){
        if(rowCounter >= 9){
            rowCounter=0;
            break;
        }
        sscanf(line,"%d %d %d %d %d %d %d %d %d %d",&dataStreams[rowCounter][0],&dataStreams[rowCounter][1],
        &dataStreams[rowCounter][2],&dataStreams[rowCounter][3],&dataStreams[rowCounter][4],&dataStreams[rowCounter][5],
        &dataStreams[rowCounter][6],&dataStreams[rowCounter][7],&dataStreams[rowCounter][8],&dataStreams[rowCounter][9]);
        rowCounter++;
    }
    for(int b = 0; b<8; b++){
        printf("%d %d %d %d %d %d %d %d [V:%4d] [H:%4d]\n",dataStreams[b][0],dataStreams[b][1],
        dataStreams[b][2],dataStreams[b][3],dataStreams[b][4],dataStreams[b][5],
        dataStreams[b][6],dataStreams[b][7],dataStreams[b][8],dataStreams[b][9]);
    }
    printf("Data Streams:\n");

    //Verticalpairtycheck
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
    



    //block3
    printf("Processing Transmission Block: %d\n", lineCounter++);
    while(fgets(line, 70, data)!=NULL){
        if(rowCounter >= 9){
            rowCounter=0;
            break;
        }
        sscanf(line,"%d %d %d %d %d %d %d %d %d %d",&dataStreams[rowCounter][0],&dataStreams[rowCounter][1],
        &dataStreams[rowCounter][2],&dataStreams[rowCounter][3],&dataStreams[rowCounter][4],&dataStreams[rowCounter][5],
        &dataStreams[rowCounter][6],&dataStreams[rowCounter][7],&dataStreams[rowCounter][8],&dataStreams[rowCounter][9]);
        rowCounter++;
    }
    for(int b = 0; b<8; b++){
        printf("%d %d %d %d %d %d %d %d [V:%4d] [H:%4d]\n",dataStreams[b][0],dataStreams[b][1],
        dataStreams[b][2],dataStreams[b][3],dataStreams[b][4],dataStreams[b][5],
        dataStreams[b][6],dataStreams[b][7],dataStreams[b][8],dataStreams[b][9]);
    }
    printf("Data Streams:\n");

    //Verticalpairtycheck
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
            }else{; 
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




    //block4
    printf("Processing Transmission Block: %d\n", lineCounter++);
    while(fgets(line, 70, data)!=NULL){
        if(rowCounter >= 9){
            rowCounter=0;
            break;
        }
        sscanf(line,"%d %d %d %d %d %d %d %d %d %d",&dataStreams[rowCounter][0],&dataStreams[rowCounter][1],
        &dataStreams[rowCounter][2],&dataStreams[rowCounter][3],&dataStreams[rowCounter][4],&dataStreams[rowCounter][5],
        &dataStreams[rowCounter][6],&dataStreams[rowCounter][7],&dataStreams[rowCounter][8],&dataStreams[rowCounter][9]);
        rowCounter++;
    }
    for(int b = 0; b<8; b++){
        printf("%d %d %d %d %d %d %d %d [V:%4d] [H:%4d]\n",dataStreams[b][0],dataStreams[b][1],
        dataStreams[b][2],dataStreams[b][3],dataStreams[b][4],dataStreams[b][5],
        dataStreams[b][6],dataStreams[b][7],dataStreams[b][8],dataStreams[b][9]);
    }
    printf("Data Streams:\n");

    //Verticalpairtycheck
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

    
    //block5
    printf("Processing Transmission Block: %d\n", lineCounter++);
    while(fgets(line, 70, data)!=NULL){
        if(rowCounter >= 9){
            rowCounter=0;
            break;
        }
        sscanf(line,"%d %d %d %d %d %d %d %d %d %d",&dataStreams[rowCounter][0],&dataStreams[rowCounter][1],
        &dataStreams[rowCounter][2],&dataStreams[rowCounter][3],&dataStreams[rowCounter][4],&dataStreams[rowCounter][5],
        &dataStreams[rowCounter][6],&dataStreams[rowCounter][7],&dataStreams[rowCounter][8],&dataStreams[rowCounter][9]);
        rowCounter++;
    }
    for(int b = 0; b<8; b++){
        printf("%d %d %d %d %d %d %d %d [V:%4d] [H:%4d]\n",dataStreams[b][0],dataStreams[b][1],
        dataStreams[b][2],dataStreams[b][3],dataStreams[b][4],dataStreams[b][5],
        dataStreams[b][6],dataStreams[b][7],dataStreams[b][8],dataStreams[b][9]);
    }
    printf("Data Streams:\n");

    //Verticalpairtycheck
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

    int nameLenght = strlen(dataFiles[0]);
    parityCheck(dataFiles[0], nameLenght);
    nameLenght = strlen(dataFiles[1]);
    checkSum(dataFiles[1], nameLenght);
    nameLenght = strlen(dataFiles[2]);
    twoDimensionalParityCheck(dataFiles[2], nameLenght); 
    
    
    return 0;
}