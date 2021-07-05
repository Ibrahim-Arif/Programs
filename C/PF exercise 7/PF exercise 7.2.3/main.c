#include <stdio.h>
#include <stdlib.h>
#define size 100

void strcat(char string1[], char string2[], int size_of_string);

int main()
{
    char string1[size], string2[size];
    char string3[size];
    int size_of_string1=0;
    printf("Enter first string: ");
    gets(string1);
    printf("Enter second string: ");
    gets(string2);

    size_of_string1 = strlen(string1) ;
    strcat(string1, string2, size_of_string1);
    size_of_string1 = strlen(string1) ;
    string1[size_of_string1] = ' ';
    printf("\nString 1 after additon: \n");
    printf("%s",string1);

    printf("\n\n");
    return 0;
}

void strcat(char string1[], char string2[], int size_of_string1)
{
    int i,j=0;
    for(i=size_of_string1,j=0;string2[j] != '\0' ; i++,j++)
    {
        string1[i] = string2[j];
    }
}
