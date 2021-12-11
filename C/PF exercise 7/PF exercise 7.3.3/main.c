#include <stdio.h>
#include <stdlib.h>
#define size 100

void reverse_using_loop(const char string[size], int size_of_string)
{
    int i;
    for(i=size_of_string-1 ; i>=0 ; i--)
        printf("%c",string[i]);
}

void reverse_using_recursion(const char string[size], int size_of_string)
{
    if(size_of_string < 0)
        return 1;
    else
        {
            printf("%c",string[size_of_string]);
            reverse_using_recursion(string, size_of_string-1);
        }
}

int main()
{
    char string[size];
    int i, size_of_string=0;
    printf("Enter a string: ");
    gets(string);

    for(int i=0; string[i] != '\0'; i++)
        size_of_string++;

    printf("\nReverse using loop:\n");
    reverse_using_loop(string, size_of_string);
    printf("\n\nReverse using recursion:\n");
    reverse_using_recursion(string, size_of_string-1);

    printf("\n\n");
    return 0;
}
