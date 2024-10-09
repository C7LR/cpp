/*Cesar Lozada*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 3000//Defines variable MAX_LEN with value 3000.

int main(){
    /* 
    Program first opens and reads the "AHPA 12 - Movie Data.txt" file.
    Then it creates two arrays;
        movieLenght: int array that stores the sum of average income produced by a movie with a certain title lenght.
        *starWarsMovies: char pointer array that stores the Star Wars movie titles.
    It then proceeds to gather the year(year a movie was released), total(total gross earned by movie),
    realeases(number of releases movie had), average(average income movie earned), and title(movie title).
    It will then determine the lenght of the title.
    Then it will find each of the movie titles in the file that have "Star Wars" in the name and will
    store them in the starWarsMovies pointer array.
    After which, it will then proceed to classify each of the movies based on their titleLenght,
    and store the sum their respective average income(to find which titleLenght has produced the most income) in the
    movieLenght array.
    It will then print the contents of the movieLenght array next to the specific titleLenght they represent.
    It will also print which titleLenght has earned th emost income.
    Finally it prints the starWarsMovies array in a list format. 
    */
    FILE*movieReleases;
    movieReleases = fopen("AHPA 12 - Movie Data.txt", "r");
    if(movieReleases == NULL){
        printf("Error: data unable to be found.");
        return(1);
    }

    
    int movieLenght[50]={0};
    char *starWarsMovies[90];
    size_t counter=0;

    char str[3500];
    while(fgets(str, MAX_LEN, movieReleases)!=NULL){
        int year;
        float total;
        int releases;
        int average;
        char title[MAX_LEN];
        sscanf(str,"%d %f %d %d %[^\n]s", &year, &total, &releases, &average, &title);
        
        int titleLength = strlen(title);
        if(strstr(title,"Star Wars")){
            starWarsMovies[counter] = (char*)malloc(titleLength+1);
            strcpy(starWarsMovies[counter],title);
            counter+=1;
        }
        
        if(titleLength==0){
            movieLenght[0]+=average;
        }
        if(titleLength==1){
            movieLenght[1]+=average;
        }
        if(titleLength==2){
            movieLenght[2]+=average;
        }
        if(titleLength==3){
            movieLenght[3]+=average;
        }
        if(titleLength==4){
            movieLenght[4]+=average;
        }
        if(titleLength==5){
            movieLenght[5]+=average;
        }
        if(titleLength==6){
            movieLenght[6]+=average;
        }
        if(titleLength==7){
            movieLenght[7]+=average;
        }
        if(titleLength==8){
            movieLenght[8]+=average;
        }
        if(titleLength==9){
            movieLenght[9]+=average;
        }
        if(titleLength==10){
            movieLenght[10]+=average;
        }
        if(titleLength==11){
            movieLenght[11]+=average;
        }
        if(titleLength==12){
            movieLenght[13]+=average;
        }
        if(titleLength==14){
            movieLenght[14]+=average;
        }
        if(titleLength==15){
            movieLenght[15]+=average;
        }
        if(titleLength==16){
            movieLenght[16]+=average;
        }
        if(titleLength==17){
            movieLenght[17]+=average;
        }
        if(titleLength==18){
            movieLenght[18]+=average;
        }
        if(titleLength==19){
            movieLenght[19]+=average;
        }
        if(titleLength==20){
            movieLenght[20]+=average;
        }
        if(titleLength==21){
            movieLenght[21]+=average;
        }
        if(titleLength==22){
            movieLenght[22]+=average;
        }
        if(titleLength==23){
            movieLenght[23]+=average;
        }
        if(titleLength==24){
            movieLenght[24]+=average;
        }

    }

    int largestEarner;
    for(int m = 0; m<25; ++m){
        static int comparison = 0;
        if(movieLenght[m]>comparison){
            largestEarner = m;
            comparison = movieLenght[m];
        }
        printf("%2d : %d\n", m, movieLenght[m]);
    }
    printf("\nThe movie title lenght that made the most money was %d \n\n", largestEarner);

    printf("Star Wars Movies In List:\n");
    for(int m = 0; m < 5; ++m){
        printf("%d. %s\n", m, starWarsMovies[m]);
    }
    
    fclose(movieReleases);
    return 0;
}