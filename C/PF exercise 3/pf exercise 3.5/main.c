#include <stdio.h>
#include <stdlib.h>

int main()
{
    int  a_no;
    float bbm, charges, credit, a_credit, new_b;
    while(a_no != -1)
    {
    printf("Enter account number(-1 to end): ");
    scanf("%d",&a_no);
    if(a_no != -1)
    {
    printf("Enter initial balance: ");
    scanf("%f",&bbm);
    printf("Enter total charges: ");
    scanf("%f",&charges);
    printf("Enter total credits: ");
    scanf("%f",&credit);
    printf("Enter credit limit: ");
    scanf("%f",&a_credit);

    new_b = (bbm + charges -credit);

    printf("Account: %d\n",a_no);
    printf("Credit limit: %.2f\n",a_credit);
    printf("Balance: %.2f\n",new_b);
    if(new_b>a_credit)
    {
        printf("Credit Limit Exceeded\n\n");
    }}}
}
