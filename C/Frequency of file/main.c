#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    int count=0;
    char ch='a';
    char temp;
    char str[100];
    printf("Enter a string: ");
    gets(str);
    fptr1=fopen("file.txt","w");
    fputs(str,fptr1);
    fclose(fptr1);

    fptr2=fopen("file.txt","r");
    for(ch='a' ; ch<='z' ; ch++)
    {
        rewind(fptr2);
        while(!feof(fptr2))
        {
            temp=fgetc(fptr2);
            if(ch==temp)
                count++;
        }
        if(count != 0)
            printf("frequency of %c: %d\n",ch,count);

        count=0;
    }

    fclose(fptr2);


    return 0;
}
