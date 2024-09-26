/*Cesar Lozada*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main(){
    //Defines a USFstudentinfo structure as well as initializes its member variables.
    //Member variables include: a char name variable, an int age variable, a char Unumber variable,
    //a float GPA variable. a bool onCampus variable, and a bool paidCurrentSemester variable.
    struct USFstudentinfo{
        char name[50];
        int age;
        char Unumber[12];
        float GPA;
        bool onCampus;
        bool paidCurrentSemester;
    };

    //Creates array of USFstudentinfo structures named USFstudentDatabases containing 2 structures.
    //Then queries user on a student's name, age, Unumber, and GPA and assigns values given to repective
    //member variables within first structure.
    //Then queries user if student lives on campus, and if student has paid for current semester.
    //If user responds yes(y) to either, then the respective member value is assigned true.
    //If user responds no(n) to either, then the respective member value is assigned false.
    //If user respond is neither n or y then error message is printed and assigns member with false.
    struct USFstudentinfo USFstudentDatabase[2];
    printf("Enter student's name:\n");
    fgets(USFstudentDatabase[0].name, 40, stdin);
    printf("Enter student's age:\n");
    scanf("%d",&USFstudentDatabase[0].age);
    getchar();
    printf("Enter student's U number:\n");
    fgets(USFstudentDatabase[0].Unumber, 40, stdin);
    printf("Enter student's GPA:\n");
    scanf("%f",&USFstudentDatabase[0].GPA);
    getchar();
    printf("Enter if student lives on campus(y/n):\n");
    char campusResponce=getchar();
    switch (campusResponce)
    {
    case'y':
        USFstudentDatabase[0].onCampus = true;
        break;
    
    case'n':
        USFstudentDatabase[0].onCampus = false;
        break;

    default:
        printf("Error: Please enter (y)-yes or (n)-no.\n");
        USFstudentDatabase[0].onCampus = false;
        break;
    }
    getchar();
    printf("Enter if student has paid for current semester(y/n):\n");
    char paymentRespnce=getchar();
    switch (paymentRespnce)
    {
    case'y':
        USFstudentDatabase[0].paidCurrentSemester = true;
        break;
    
    case'n':
        USFstudentDatabase[0].paidCurrentSemester = false;
        break;

    default:
        printf("Error: Please enter (y)-yes or (n)-no.\n");
        USFstudentDatabase[0].paidCurrentSemester = false;
        break;
    }

    //It will then ask user to name second student.
    //After which it will then copy information in first USFstudentDatabase structure 
    //to the second USFstudentDatabase structure.
    //It will then proceed to alter the name member variable of the second structure with the second student name given.
    //It will also swap the values of both onCampus and paidCurrentSemester member variables with their opposite values.
    getchar();
    USFstudentDatabase[1] = USFstudentDatabase[0];
    char student2Name[50];
    printf("\nEnter a second student name:\n");
    fgets(student2Name, 40, stdin);
    int nameLength = strlen(student2Name);
    for(int x=0; x<nameLength; x++){
        char letter=student2Name[x];
        USFstudentDatabase[1].name[x]=letter;
        if (x == nameLength-1){
            USFstudentDatabase[1].name[x]='\n';
            USFstudentDatabase[1].name[x+1]='\0';           
        }
    }
    if(USFstudentDatabase[1].onCampus == true){
        USFstudentDatabase[1].onCampus = false;
    }else USFstudentDatabase[1].onCampus = true;
    if(USFstudentDatabase[1].paidCurrentSemester == true){
        USFstudentDatabase[1].paidCurrentSemester = false;
    }else USFstudentDatabase[1].paidCurrentSemester = true;
    
    //It will then print the information in both USFstudentDatabase structures.
    printf("\nStudent Name: %s", USFstudentDatabase[0].name);
    printf("Student age: %d\n", USFstudentDatabase[0].age);
    printf("Student Unumber: %s", USFstudentDatabase[0].Unumber);
    printf("Student Name: %.2f\n", USFstudentDatabase[0].GPA);
    if(USFstudentDatabase[0].onCampus==true){
        printf("Student is on campus.\n");
    }else printf("Student is not on campus.\n");
    if(USFstudentDatabase[0].paidCurrentSemester==true){
        printf("Student paid for current semester.\n\n");
    }else printf("Student has not paid for current semester.\n\n");

    printf("Student Name: %s", USFstudentDatabase[1].name);
    printf("Student age: %d\n", USFstudentDatabase[1].age);
    printf("Student Unumber: %s", USFstudentDatabase[1].Unumber);
    printf("Student Name: %.2f\n", USFstudentDatabase[1].GPA);
    if(USFstudentDatabase[1].onCampus==true){
        printf("Student is on campus.\n");
    }else printf("Student is not on campus.\n");
    if(USFstudentDatabase[1].paidCurrentSemester==true){
        printf("Student paid for current semester.\n\n");
    }else printf("Student has not paid for current semester.\n\n");

    return(0);
}