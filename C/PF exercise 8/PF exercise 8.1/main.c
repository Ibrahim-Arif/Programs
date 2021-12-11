#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char name[300];
    fptr=fopen("DATA.txt","w");

    printf("Enter a string to save it into file: ");
    gets(name);

    if(fptr == 0)
        printf("File not found ):");
    else
        fprintf(fptr,name);

    printf("\n\n");
    return 0;
}
