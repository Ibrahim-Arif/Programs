#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[50];
    int RollNo;
    float CGPA;
};

void print_student_record(struct student *s1)
{
        printf("name: %s\n",s1 -> name);
        printf("Roll no: %d\n",s1 -> RollNo);
        printf("CGPA: %f\n\n",s1-> CGPA);
}

int main()
{
    int i;
    struct student s1[5] = { {"Ibrahim", 033, 3.2}, {"haseeb", 042, 3.1}, {"shamraiz", 057, 3.0} , {"Faizan", 075, 2.7}, {"bilal", 99, 3.4} };

    printf("Content in array:\n\n");
    for(i=0; i<5;i++)
        print_student_record( &s1[i] );

    printf("\n");
    return 0;
}
