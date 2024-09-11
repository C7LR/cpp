/*Cesar Lozada*/

#include<stdio.h>
#include<string.h>

int main()
{
    //Initializes int variables for both cheking and savings
    //accounts of person a and b.
    //Also assigns each accounts their repective balance.
    int aChecking = 500;
    int aSavings = 1000;
    int bChecking = 750;
    int bSavings = 325;

    //Initializes the int accounts multi-dimensinal(2x2) array.
    //Then assigns the checking and savings account of person a into the first row,
    //and the checking and savings account of person b into the other.
    int accounts[2][2]={{aChecking,aSavings},{bChecking,bSavings}};

    //Initializes int emptyAccount array and emptyAccountType.
    //This is used in case of incorrect input or name not matching.
    int emptyAccountType = 0;
    int emptyAccount[1][1] = {{emptyAccountType}};

    //Initializes the char variables userName and chosenAccount and
    //the int variable amountWithdrawn.
    //The queries user regarding their name, which account they want to access
    //and the amount they want to withdraw.
    //Also assigns each responce to it repective variable.
    char userName;
    printf("Enter your name:\n");
    userName = getchar();
    getchar();
    char chosenAccount;
    printf("Would you like to withdraw from (c)checking or (s)savings?\n");
    chosenAccount = getchar();
    int amountWithdrawn;
    printf("How much would you like to withdraw?\n");
    scanf(" %d",&amountWithdrawn);


    //Initializes the int variables userAccount, userId, andaccountType.
    //Then it uses the given userName responce to find the accounts that belong
    //to that particular user.
    //If userName doesnt match account name of person a or b,
    //it will print message stating "User name not found".
    //If userName matches name of person a or b but, 
    //chosemAccount responce isn't c (for checking)  or s (for savings)
    //then it will print message "Incorrect input (s or c please)".
    //For both userName not found and Incorrect input it will then 
    //assign userAcount to emptyAccount.
    //Finally if the userName and chosenAccount match, then the userId
    //will be assigned the value that conatains the user's accounts 
    //in the account array, and the accountType will be assigned 
    //the value that corresponds to the user's account type in the array.
    //userAccount will then be assigned the balance of the specified account.
    int userAccount;
    int userId;
    int accountType;
    switch (userName) {
        case'a':
            userId = 0;
            switch (chosenAccount) {
                case'c':
                    accountType = 0;
                    userAccount = accounts[userId][accountType];
                    break;
                case's':
                    accountType = 1;
                    userAccount = accounts[userId][accountType];
                    break;
                default:
                    printf("Incorret input (s or c please)\n");
                    userAccount = emptyAccount[0][0];
                    break;
            }
            break;
        case'b':
            userId = 1;
            switch (chosenAccount) {
                case'c':
                    accountType = 0;
                    userAccount = accounts[userId][accountType];
                    break;
                case's':
                    accountType = 1;
                    userAccount = accounts[userId][accountType];
                    break;
                default:
                    printf("Incorret input (s or c please)\n");
                    userAccount = emptyAccount[0][0];
                    break;
            }
            break;
        default:
            printf("User name not found\n");
            userAccount = emptyAccount[0][0];
            break;
        }
    
    //Initializes the int variable amountRemaining.
    //Then it checks whether amountWithdrawn is greater than $200.
    //If amountWithdrawn is greater than $200, then it will print message
    //saying that witdraw amount is greater than limit.
    //If amount is within limit but if the userAccount balance is less than the
    //amountWithdrawn then it will print message showing account balance and
    //and thaat the amount being withdrawn is more than what is in the account.
    //Finally if amount is within the limit and is less than what is on the
    //user's balance it will print the message showing amount in the user account
    //then proceed to calculate the amountRemainingin the user's account, 
    //then it will count and print each type of dollar bill that user will receive, 
    //and then will finally display a message showing what the amountRemaining 
    //in the user's account is.
    int amountRemaining;
    if(amountWithdrawn > 200) {
        printf("Withdraw amount is greater than limit($200)\n");
    }
    else {
        if (userAccount < amountWithdrawn){
            printf("Amount in account to be withdrawn from: $%d\n", userAccount);
            printf("Amount withdrawn is more than what is in the account.\n");
        }
        else{
            amountRemaining = userAccount - amountWithdrawn;
            printf("Amount in account to be withdrawn from: $%d\n", userAccount);
            if (amountWithdrawn > 100){
                printf("$100 bill\n");
                amountWithdrawn -= 100;
            }
            if(amountWithdrawn >= 100){
                printf("$100 bill\n");
                amountWithdrawn -= 100;
            }
            if (amountWithdrawn > 50){
                printf("$ 50 bill\n");
                amountWithdrawn -= 50;
            }
            if (amountWithdrawn > 20){
                printf("$ 20 bill\n");
                amountWithdrawn -= 20;
            }
            if (amountWithdrawn >= 20){
                printf("$ 20 bill\n");
                amountWithdrawn -= 20;
            }
            if (amountWithdrawn > 10){
                printf("$ 10 bill\n");
                amountWithdrawn -= 10;
            }
            if (amountWithdrawn >= 10){
                printf("$ 10 bill\n");
                amountWithdrawn -= 10;
            }
            if (amountWithdrawn > 5){
                printf("$  5 bill\n");
                amountWithdrawn -= 5;
            }
            if (amountWithdrawn >= 5){
                printf("$  5 bill\n");
                amountWithdrawn -= 5;
            }
            if (amountWithdrawn > 1){
                printf("$  1 bill\n");
                amountWithdrawn -= 1;
            }
            if (amountWithdrawn > 1){
                printf("$  1 bill\n");
                amountWithdrawn -= 1;
            }
            if (amountWithdrawn > 1){
                printf("$  1 bill\n");
                amountWithdrawn -= 1;
            }
            if (amountWithdrawn > 1){
                printf("$  1 bill\n");
                amountWithdrawn -= 1;
            }
            if (amountWithdrawn > 1){
                printf("$  1 bill\n");
                amountWithdrawn -= 1;
            }
            if (amountWithdrawn >= 1){
                printf("$  1 bill\n");
                amountWithdrawn -= 1;
            }
            printf("Amount in account after withdrwal: $%d\n", amountRemaining);
        }
    }

    return 0;
}
