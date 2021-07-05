#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[5]= "abc";
    int n;
    FILE *fptr1, *fptr2;
    fptr1=fopen("file.txt","r");
    if(!fptr1)
        printf("Unable to open file :(");
    else{
        printf("enter number of character to access: ");
        scanf("%d",&n);
        fseek(fptr1,n-1,SEEK_SET);
        printf("%c",fgetc(fptr1));
        fclose(fptr1);

        fptr2=fopen("file.txt","r+");
        fseek(fptr2,n-1,0);
        fputs(a,fptr2);
        fclose(fptr2);
    }
    return 0;
}
