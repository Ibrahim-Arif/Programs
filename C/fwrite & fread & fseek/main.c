#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    char name[30];
    int roll;
    float gpa;
}student;

void input(student *std)
{
    scanf("%s %d %f",std -> name,&std -> roll,&std -> gpa);
}

int main()
{
    student std[100];
    int count,i,n,z;
    printf("Enter number of record for file: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter name, roll no, and GPA of %d student: ",i);
        input( &std[i] );
    }

    FILE *fptr;
    fptr = fopen("file.txt","wb");
    for(i=0;i<n;i++)
        fwrite(&std[i],sizeof(std),1,fptr);
    fclose(fptr);

    fptr=fopen("file.txt","rb");
    for(i=0;i<n;i++)
        fread(&std[i],sizeof(std),1,fptr);

    for(i=0;i<n;i++)
        printf("%s \t %d \t %.2f\n",std[i].name,std[i].roll,std[i].gpa);
    fclose(fptr);

    fptr=fopen("file.txt","rb");
    printf("\n\nTo data: ");
    scanf("%d",&z);
    fseek(fptr, sizeof(std)*--z ,0);
    fread(&std,sizeof(std),1,fptr);
    printf("%s %d %.2f",std[0].name,std[0].roll,std[0].gpa);
    fclose(fptr);

    printf("\n\n");
    return 0;
}
