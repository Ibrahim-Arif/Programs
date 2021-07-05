#include <stdio.h>
#include <stdlib.h>
#define size 100

char strcpyy(char string1[], char string2[]);

int main()
{
    char string1[size], string2[size];
    printf("Enter a string: ");
    gets(string2);

    strcpyy(string1, string2);
    printf("\nAfter coping to string 1: \n");
    printf("%s",string1);

    printf("\n\n");
    return 0;
}

char strcpyy(char string1[size], char string2[size])
{
    int i;
    for(i=0;(string1[i] = string2[i]) != '\0' ; i++)
        ;
    string2[i] = '\0';
}
