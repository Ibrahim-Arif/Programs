#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define size 50

void vowels(const char string[size], int size_of_string)
{
    int count=0, i;
    for(i=0;i<size_of_string;i++)
    {
        if( string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
             string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U'  )
        {
            count++;
        }
    }
    printf("Total number of Vowels: %d", count);
}

void consonants(const char string[size], int size_of_string)
{
    int count=0, i;
    for(i=0;i<size_of_string;i++)
    {
        if( string[i] != 'a' && string[i] != 'e' &&  string[i] != 'i'  && string[i] != 'o' && string[i] != 'u' &&
             string[i] != 'A' && string[i] != 'E' && string[i] != 'I' && string[i] != 'O' && string[i] != 'U'  )
            {
                if( isdigit(string[i]) || isspace(string[i]) )
                    ;
                else
                    count++;
            }
    }
    printf("Total number of Consonants: %d", count);
}

void digits(const char string[size], int size_of_string)
{
    int i, count=0;
    for(i=0;i<size_of_string;i++)
    {
        if( isdigit(string[i]))
            count++;
    }
    printf("Total digits are: %d", count);
}

void space( const char string[size], int size_of_string)
{
    int i, count=0;
    for(i=0; i< size_of_string; i++)
    {
        if(isspace(string[i]))
            count++;
    }
    printf("total blank space are: %d",count);
}


int main()
{
    char string[size];
    int i, size_of_string=0;

    printf("Enter a string: ");
    gets(string);

    for(i=0;string[i] != '\0' ; i++)
        size_of_string++;

    printf("\n");
    vowels(string, size_of_string);
    printf("\n");
    consonants(string, size_of_string);
    printf("\n");
    digits(string, size_of_string);
    printf("\n");
    space(string, size_of_string);

    printf("\n\n");
    return 0;
}
