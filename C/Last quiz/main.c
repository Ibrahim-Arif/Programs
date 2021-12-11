#include <stdio.h>
#include <stdlib.h>

struct address
{
    int houseno;
    char city[20];
};

struct employee
{
    int empno;
    char empname[30];
    struct address add;
};

int main()
{
    struct employee emp={1,"Ali",402,"Lahore"};
    struct employee *ptremp = &emp;
    printf("%d",ptremp -> empno);
    printf(" %s",ptremp -> empname);
    printf(" %d",ptremp -> add.houseno);
    printf(" %s",ptremp -> add.city);

    printf("\n\n");
    return 0;
}
