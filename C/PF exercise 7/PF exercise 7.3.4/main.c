#include <stdio.h>
#include <stdlib.h>
#define size 50

void just_alphabets(char string[size], int size_of_string)
{
    int i, count=0;
    for(i=0; i<size_of_string ; i++)
    {
        if( isalpha(string[i]) )
            count++;
        else
            string[i] = ' ';
    }
   // printf("%d",count);

    for(i=0;i<size_of_string;i++)
        printf("%c",string[i]);

}

int main()
{
    char string[size];
    int size_of_string=0, i;
    printf("Enter a string: ");
    gets(string);

    for(int i=0;string[i] != '\0'; i++)
        size_of_string++;

    printf("\nString after removing non-alphabet characters:\n");
    just_alphabets(string, size_of_string);
    printf("\n\nString without blank spaces: \n");
    for(i=0;i<size_of_string;i++)
        if(string[i] != ' ')
            printf("%c",string[i]);

    printf("\n\n");
    return 0;
}
