/*Cesar Lozada*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main(){
    struct USFstudentinfo{
        char name[50];
        int age;
        char Unumber[12];
        float GPA;
        bool onCampus;
        bool paidCurrentSemester;
    };

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
        "Error: Please enter (y)-yes or (n)-no.";
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
        "Error: Please enter (y)-yes or (n)-no.";
        break;
    }

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