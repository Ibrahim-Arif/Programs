#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    int a=1;
    char name[5][30];
    int roll[5], marks[5];

    /*fptr=fopen("file.txt","w");
    for(int i=0;i<5;i++)
    {
        printf("Enter data: ");
        scanf("%s %d %d",name[i],&roll[i],&marks[i]);
        fprintf(fptr,"%s %d %d\n", name[i],roll[i],marks[i]);
    }
    fclose(fptr);*/

    fptr=fopen("file.txt","r");
    fscanf(fptr,"%s %d %d",name[0],&roll[0],&marks[0]);
    while(!feof(fptr))
    {
        fscanf(fptr,"%s %d %d",name[a],&roll[a],&marks[a]);
        a++;
    }
    fclose(fptr);

    for(a=0;a<5;a++)
        printf("%s  %d  %d\n",name[a],roll[a],marks[a]);
    return 0;
}
