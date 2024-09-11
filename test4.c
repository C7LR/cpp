#include <stdio.h>
#include <string.h>

int main()
{
    char word[10];
    char reword[10];

    fgets(word,12,stdin);
    printf("\n%s test\n\n",word);

    int lenght = strlen(word)-1;

    strncpy(reword,word, lenght);
    printf("%s test\n\n", reword);

    printf("%d", strnlen(word, 10));

    return 0;
}