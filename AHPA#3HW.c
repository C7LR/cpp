/*Cesar Lozada*/

#include <stdio.h>
#include <string.h>

int main()
{
    //Initializes flavor enumarator and assigns flavor names.
    enum flavors{vanilla, chocolate, mint, straberry};

    //Initializes 4 IceFlavor char variables.
    //Then prints query to user regarding what 4 ice cream flavors in sale.
    //Then assigns value ot each IceFlavor variable through fgets inputs.
    char firstIceFlavor[20];
    printf("Enter ice cream flavor #1:\n");
    fgets(firstIceFlavor,15,stdin);
    char secondIceFlavor[20];
    printf("\nEnter ice cream flavor #2:\n");
    fgets(secondIceFlavor,15,stdin);
    char thirdIceFlavor[20];
    printf("\nEnter ice cream flavor #3:\n");
    fgets(thirdIceFlavor,15,stdin);
    char fourthIceFlavor[20];
    printf("\nEnter ice cream flavor #4:\n");
    fgets(fourthIceFlavor,15,stdin);

    //Initializes 4 FlavorSalesC1 float variables.
    //Then prints query to user regarding the sales of a ice cream flavor
    //in streat corner 1.
    //Then assigns value to each FlavorSalesC1 varible through use of fgets.
    float firstFlavorSalesC1;
    printf("\n\nEnter corner 1 sales of %s",firstIceFlavor);
    scanf("%f",&firstFlavorSalesC1);
    float secondFlavorSalesC1;
    printf("\nEnter corner 1 sales of %s",secondIceFlavor);
    scanf("%f",&secondFlavorSalesC1);
    float thirdFlavorSalesC1;
    printf("\nEnter corner 1 sales of %s",thirdIceFlavor);
    scanf("%f",&thirdFlavorSalesC1);
    float fourthFlavorSalesC1;
    printf("\nEnter corner 1 sales of %s",fourthIceFlavor);
    scanf("%f",&fourthFlavorSalesC1);

    //Initializes 4 FlavorSalesC2 float variables.
    //Then prints query to user regarding the sales of a ice cream flavor
    //in streat corner 2.
    //Then assigns value to each FlavorSalesC2 varible through use of fgets.
    float firstFlavorSalesC2;
    printf("\n\nEnter corner 2 sales of %s",firstIceFlavor);
    scanf("%f",&firstFlavorSalesC2);
    float secondFlavorSalesC2;
    printf("\nEnter corner 2 sales of %s",secondIceFlavor);
    scanf("%f",&secondFlavorSalesC2);
    float thirdFlavorSalesC2;
    printf("\nEnter corner 2 sales of %s",thirdIceFlavor);
    scanf("%f",&thirdFlavorSalesC2);
    float fourthFlavorSalesC2;
    printf("\nEnter corner 2 sales of %s",fourthIceFlavor);
    scanf("%f",&fourthFlavorSalesC2);

    //Defines corner1Sales and corner2Sales sales arrays.
    //Loads all 4 corner1SalesC1 to corner1Sales array.
    //Loads all 4 corner1SalesC2 to corner2Sales array.
    float corner1Sales[]={firstFlavorSalesC1,secondFlavorSalesC1,
    thirdFlavorSalesC1,fourthFlavorSalesC1};
    float corner2Sales[]={firstFlavorSalesC2,secondFlavorSalesC2,
    thirdFlavorSalesC2,fourthFlavorSalesC2};

    //Defines 4 total FlavorSales float variables for each flavor.
    //Assigns the total sum of a specific ice cream flavors sale in both corners.
    //Utilizes flavor enum variables as indexes to the corner#Sales arrays.
    float totalFirstFlavorSales = corner1Sales[vanilla] + corner2Sales[vanilla];
    float totalSecondFlavorSales = corner1Sales[chocolate] + corner2Sales[chocolate];
    float totalThirdFlavorSales = corner1Sales[mint] + corner2Sales[mint];
    float totalFourthFlavorSales = corner1Sales[straberry] + corner2Sales[straberry];

    //Defines the totalSales float variable.
    //Assigns variable the total sum of ice cream sales in both corners.
    float totalSales = totalFirstFlavorSales + totalSecondFlavorSales +
    totalThirdFlavorSales + totalFourthFlavorSales;

    //Prints the sales sum of each ice cream flavors.
    //Then prints the total sales sum of all ice cream flavor.
    printf("\nTotal %ssales: %.2f\n", firstIceFlavor, totalFirstFlavorSales);
    printf("Total %ssales: %.2f\n", secondIceFlavor, totalSecondFlavorSales);
    printf("Total %ssales: %.2f\n", thirdIceFlavor, totalThirdFlavorSales);
    printf("Total %ssales: %.2f\n", fourthIceFlavor, totalFourthFlavorSales);
    printf("\nBob's Ice Cream total sales: %.2f\n", totalSales);

    return 0;
}