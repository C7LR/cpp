/*Cesar Lozada*/

#include <stdio.h>
int main()
{
    //Initializes the constant integer variable numStudents.
    //Also stores the total number of students.
    const int numStudents = 9;
    
    //Initializes multiple integer variables named student#Location for each student in the class.
    //Also stores the seating location of each of the students in the class.
    int student1Location = 1, student2Location = 2, student3Location = 3, 
    student4Location = 4, student5Location = 5, student6Location = 6, 
    student7Location = 7, student8Location = 8, student9Location = 9;

    //Initializes multiple character variables named student#Name for each student in the class.
    //Also stores the name of each of the students in the class.
    char student1Name = 'B', student2Name = 'M', student3Name = 'T',
    student4Name = 'J', student5Name = 'P', student6Name = 'E',
    student7Name = 'H', student8Name = 'R', student9Name = 'X';

    //Initializes multiple floating point variables named student#Grade for each student in the class.
    //Also stores the current grades of each of the students in the class.
    float student1Grade = 79.54, student2Grade = 82.13, student3Grade = 74.61,
    student4Grade = 91.12, student5Grade = 78.83, student6Grade = 97.17,
    student7Grade = 85.65, student8Grade = 65.42, student9Grade = 70.26;

    //Prints the number of students in the class.
    //Then prints the Seating Location, Name, and Current Grade of each fo the students.
    //Information of the students are printed in 3 rows and 3 columns format.
    printf("Number of students in the class:%2d\n\n",numStudents);

    printf("%d %c %.1f",student1Location,student1Name,student1Grade);
    printf("%5d %c %.1f", student2Location, student2Name, student2Grade);
    printf("%5d %c %.1f\n", student3Location, student3Name, student3Grade);

    printf("%d %c %.1f",student4Location,student4Name,student4Grade);
    printf("%5d %c %.1f", student5Location, student5Name, student5Grade);
    printf("%5d %c %.1f\n", student6Location, student6Name, student6Grade);

    printf("%d %c %.1f",student7Location,student7Name,student7Grade);
    printf("%5d %c %.1f", student8Location, student8Name, student8Grade);
    printf("%5d %c %.1f\n", student9Location, student9Name, student9Grade);
    return(0);
}