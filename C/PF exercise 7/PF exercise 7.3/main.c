#include <stdio.h>
#include <stdlib.h>
#define size 100

void frequency(const char string[size], int size_of_string)
{
    char i;
    int j, count;
    for(i='a'; i<= 'z'; i++)
    {
        count=0;
        for(j=0;j<size_of_string;j++)
        {
            if(i == string[j])
                count++;
        }
        if(count != 0)
            printf("\nfrequency of %c is %d",i,count);
    }
}

int main()
{
    char string[size];
    int freq[size], count=0, i, size_of_string=0;
    printf("Enter a string: ");
    gets(string);

    for(i=0;string[i] != '\0';i++)
        size_of_string++;

    frequency(string, size_of_string);

    printf("\n\n");
    return 0;
}
