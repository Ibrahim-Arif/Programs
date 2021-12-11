#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    //int a = 9;
    char FileName[40] = "Twenty one pilots - Chlorine";
    char ch;
    int character=0, word=0, line=1, space=0, tab=0;
    fptr=fopen("Twenty one pilots Chlorine.txt","r");

    printf("-------------------------------------------------------------------------------\n");
    printf("|                  FILE READING UNDER PRCESSING, please wait                  |\n");
    printf("-------------------------------------------------------------------------------\n\n");

    if(fptr == 0)
        printf("File not found (Error 404)");
    else
    {
        while( !feof(fptr))
        {
            ch=fgetc(fptr);
            printf("%c",ch);
            if(isalpha(ch))
                character++;
            else if(ch == ' ')
                space++;
            else if(ch == 10)           //there 10 is ASCII of ENTER key,   we can also use '\n' instead of 10
                line++;
            else if(ch == 9)            //there 9 is ASCII of TAB key,   we can also use '\t' instead of 9
                tab++;
            }
    }
        printf("\n-------------------------------------------------------------------------------\n\n");
        printf("File name: %s",FileName);
        printf("\nCharacters: %d",character);
        printf("\nSpace: %d",space);
        printf("\nLine: %d",line);
        printf("\nTabs: %d",tab);
        word = space + line + tab;
        printf("\nWords: %d",word);


    printf("\n\n");
    return 0;
}
