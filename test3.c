

#include <stdio.h>
#include <string.h>

int main()
{
    int sum;
    sum = 2 + 3;
    printf("%d\n\n", sum);

    int a[10], i;
    a[10] = 0;
    printf("%d\n\n", a[10]);

    char variable[20];
    strncpy(variable, "Master Chef", 12);
    printf("%s\n\n",variable);

    char answer[10];
    fgets(answer, 12, stdin);
    printf("%s\n\n", answer);

    return 0;
}