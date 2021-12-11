#include <stdio.h>
#include <stdlib.h>
#define size 100

int strlen(const char string[size]);

int main()
{
    char string[size];
    int size_of_string=0;
    printf("Enter a string: ");
    gets(string);

    size_of_string=strlen(string);
    printf("Size of string: %d",size_of_string);

    printf("\n\n");
    return 0;
}

int strlen(const char string[size])
{
    int i, size_of_string=0;
    for(i=0; string[i] != '\0'; i++)
    {
        size_of_string++;
    }
    return size_of_string;
}
