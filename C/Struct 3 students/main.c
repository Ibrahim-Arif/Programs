#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll_no;
    char name[30];
    int marks[3];
};

int input(struct student *std)
{
    int i, sum=0;
    printf("Enter a roll no: ");
    scanf("%d",&std -> roll_no);
    fflush(stdin);
    printf("Enter name of student: ");
    gets(std -> name);
    fflush(stdin);
    for(i=0; i<3; i++)
    {
        printf("Enter marks of %d subject: ",i);
        scanf("%d",&std -> marks[i]);
        sum = sum + std -> marks[i];
    }
    return sum;
}

int main()
{
    FILE *fptr;
    struct student std[3];
    int i, sum[3] ;
    float avg[3];
    fptr = fopen("student.txt", "w");

    for(i=0;i<3;i++)
    {
        sum[i] = input(&std[i]);
        avg[i] = sum[i] /3;
        printf("\nTotal marks of %s: %d\n",std[i].name,sum[i]);
        printf("Average marks of %s: %.2f",std[i].name,avg[i]);
        printf("\n\n");
    }
    int j;
    fprintf(fptr,"Roll no   Name    Marks\n");
    for(i=0;i<3;i++)
    {
        fprintf(fptr,"%d \t   %s \t",std[i].roll_no,std[i].name);

        for(j=0;j<3;j++){
            fprintf(fptr," %d,",std[i].marks[j]);

        }
        fprintf(fptr,"\n");
    }



    printf("\n\n");
    return 0;
}
