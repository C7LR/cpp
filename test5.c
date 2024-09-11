#include <stdio.h>
#include <string.h>

int main()
{
    char word[10];
    fgets(word, 9, stdin);
    printf("\n%s",word);
    printf("test\n\n");

    int lenght = strlen(word);

    return 0;
}