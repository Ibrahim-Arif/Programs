#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[50];
    int RollNo;
    float CGPA;
};

void write_to_file(struct student *s1)
{
    FILE *fptr;
    fptr = fopen("student.txt", "a");
    fprintf(fptr,"%s\t\t%d\t\t%.2f\n",s1->name,s1->RollNo, s1->CGPA);
    fclose(fptr);
}

void read_from_file(struct student *s1)
{
    FILE *fptr;
    char ch;
    fptr = fopen("student.txt", "r");

    while(  !feof(fptr))
        printf("%c",fgetc(fptr) );

    fclose(fptr);
}

int main()
{
    int i;
    FILE *fptr;
    struct student s1[5] = { {"Ibrahim", 033, 3.2}, {"haseeb", 042, 3.1}, {"shami", 057, 3.0} , {"Faizan", 075, 2.7}, {"bilal", 99, 3.4} };

    //----------------------- Writing to file ------------------------------------
    for(i=0; i<5;i++)
        write_to_file( &s1[i] );

    //----------------------- Reading from file ----------------------------------
    printf("Content in student.txt:\n\n");
    read_from_file( &s1 );

    //----------------------- Adding new data at the end of file ------------------
    struct student s2[2] = {  {"ali", 120, 3.4}, {"zohaib", 003, 3.1} };
    fptr = fopen("student.txt", "a");

    for(i=0;i<2;i++)
        fprintf(fptr,"%s\t\t%d\t\t%.2f\n",s2[i].name,s2[i].RollNo, s2[i].CGPA);
    fclose(fptr);

    //---------------------- Reading after adding new data ------------------------
    printf("\n----------------------------------------------------------------------\n");
    printf("Content in student.txt after adding new data: \n\n");
    read_from_file( &s1 );

    printf("\n\n");
    return 0;
}
