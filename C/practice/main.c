#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[30];
    int roll;
    char city[10];
}student;

void print(student *std,int i)
{
        printf("name of %d student: %s\n",i+1,std -> name);
        printf("roll no of %d student: %d\n",i+1,std -> roll);
        printf("city of %d student: %s\n",i+1,std -> city);
}


int main()
{
    student std[3];
    FILE *fptr;
    int i;
    int add=0;

    //printf("%p ",&std[0]);

    for(i=0;i<1;i++)
    {
            printf("Enter a name: ");
            fflush(stdin);
            gets(std[i].name);
            printf("Enter a roll no: ");
            scanf("%d",&std[i].roll);
            add = add + std[i].roll;
            printf("Enter a city name: ");
            fflush(stdin);
            scanf("%s",std[i].city);
    }
    printf("\n\n");

    fptr=fopen("file.txt","r");
    if(fptr== 0)
        printf("unable\n");
    else
    {
    for(i=0;i<1;i++)
    {
        fprintf(fptr,"%s %d %s\n",std[i].name,std[i].roll,std[i].city);
    }
    fclose(fptr);

    for(i=0;i<1;i++)
    {
        print( &std[i] ,i);
        printf("\n");
    }
    }

    return 0;
}
