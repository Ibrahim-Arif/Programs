#include <stdio.h>
#include <stdlib.h>

struct student
{
    int rollno;
    char name;
    float fee;
};

int main()
{
    struct student std;
    FILE *fptr;

    printf("Enter roll number: ");
    scanf("%d",&std.rollno);
    fflush(stdin);
    printf("Enter name: ");
    scanf("%c",&std.name);
    fflush(stdin);
    printf("Enter fee: ");
    scanf("%f",&std.fee);

    fptr = fopen("file.txt", "w");

    fprintf(fptr,"%d %c %f",std.rollno,std.name,std.fee);

    return 0;
}
