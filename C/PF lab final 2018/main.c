#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    int count=0;
    int ready;
    char str[150];
    char ch;
    fptr1=fopen("file.txt", "w");
    if(!fptr1)
        printf("Unable to open file :(");
    else
    {
        printf("Enter the string in lower case (must ending with blank space)= ");
        gets(str);
        fflush(stdin);
        fputs(str,fptr1);
        fclose(fptr1);

        fptr2=fopen("file.txt","r");            //open file in read mode

        while( !feof(fptr2) )
        {
            ch='*';
            fseek(fptr2,count,0);
            while( ch != ' ')
            {
                ch = fgetc(fptr2);              //will get character to get the location of blank space
                count++;
            }

            fptr1=fopen("file.txt","r+");       //open file in read and update mode to edit lower case into upper case
            fseek(fptr1,count,0);                   // this will take file control to the we want to edit
            ready=fgetc(fptr2);                     // ready will store ASCII of lower case character
            ready=ready-32;                          // lower to upper (ASCII)
            fputc((char)ready,fptr1);               //gonna put character representing that ASCII
            fclose(fptr1);

        }
        fclose(fptr2);
    }

    fptr1=fopen("file.txt","r");            // next 7 lines do the same process for first ever character of file
    ready=fgetc(fptr1);
    ready= ready-32;
    fclose(fptr1);
    fptr2=fopen("file.txt","r+");
    fputc( (char)ready,fptr2 );
    fclose(fptr2);

    fptr1=fopen("file.txt","r");
    printf("\nFile after editing upper cases: \n");         //time to put file on screen
    while(!feof(fptr1))
        printf("%c",fgetc(fptr1));

    printf("\n\n\n");
    return 0;
}
