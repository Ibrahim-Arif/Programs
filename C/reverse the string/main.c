#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string[20];
    int i=0, count=0,j;
    printf("enter the string to reverse: ");
    gets(string);

    while(string[i] != '\0')
    {
        i++;
    }
    //printf("\n%d",i);

    j=i-1;
    while(j>=0)
    {
        printf("%c",string[j]);
        j--;
    }

    return 0;
}
