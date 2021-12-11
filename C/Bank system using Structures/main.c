#include <stdio.h>
#include <stdlib.h>

typedef struct user
{
    char name[30];
    int account_no;
    int balance;
}user;

void input(user *costumer, int i)
{
    printf("Enter name of %d user: ",++i);
    fflush(stdin);
    gets(costumer -> name);
    printf("Enter account number: ");
    scanf("%d",&costumer -> account_no);
    printf("Enter balance: ");
    scanf("%d",&costumer -> balance);
}

lessthan200(float costumer_balance, char costumer_name[30], int i)
{
    int a=0;
    if(costumer_balance < 200)
    {
        if(a==0)
            printf("Name of costumers having balance less than $200: \n");a=1;

        puts(costumer_name);
    }
}

morethan1000(user *costumer)
{
    if(costumer -> balance > 1000 )
        costumer -> balance+=100;
}

int main()
{
    int n, i,result=0, a=0;
    printf("Enter number of users: ");
    scanf("%d",&n);
    printf("--------------------------------------\n");

    user costumer[n];

    for(i=0;i<n;i++)
    {
        input(&costumer[i],i);
        printf("\n");
    }

    for(i=0;i<n;i++)
        lessthan200(costumer[i].balance, costumer[i].name, i);

    for(i=0;i<n;i++)
        morethan1000(&costumer[i]);

    printf("\nBalance after increment: \n");
    for(i=0;i<n;i++)
        printf("%s: %d\n",costumer[i].name, costumer[i].balance);


    printf("\n\n");
    return 0;
}
