#include <stdio.h>
#include <stdlib.h>
float result;

float sum(float no1, float no2)
{
    result = no1 + no2;
    return result;
}
float subt(float no1, float no2)
{
    result = no1 - no2;
    return result;
}
float multi(float no1, float no2)
{
    result = no1 * no2;
    return result;
}
float divi(float no1, float no2)
{
    result = no1 / no2;
    return result;
}
remind(int no1, int no2)
{
    int rem= no1 % no2;
    printf("\nresult= %d\n\n",rem);
}
fact(int no1, int no2)
{
    int i,fact1=1, fact2=1;

    for(i=no1;i>=1;i--)
        fact1 = fact1 * i;
    printf("\n%d! = %d",no1,fact1);

    for(i=no2;i>=1;i--)
        fact2 = fact2 * i;
    printf("\n%d! = %d\n\n",no2,fact2);
}
power(int no1, int no2)
{
    int i,pow=1;
    for(i=1;i<=no2;i++)
        pow = pow*no1;
    printf("\nResult= %d\n\n",pow);
}

int main()
{
    char choice;
    float no1, no2;
    printf(" + for addition\n");
    printf(" - for subtraction\n");
    printf(" * for multiplication\n");
    printf(" / for division\n");
    printf(" %c for reminder\n",37);
    printf(" ! for \n");
    printf(" ^ for power\n\n");
    label:

    printf("Enter your choice: ");
    choice=getche();
    printf("\nEnter 1st number: ");
    scanf("%f",&no1);
    printf("Enter 2nd number: ");
    scanf("%f",&no2);

    if(choice == '+')
        result=sum(no1,no2);
    else if(choice == '-')
        result=subt(no1,no2);
    else if(choice == '*')
        result=multi(no1,no2);
    else if(choice == '/')
        result=divi(no1,no2);
    else if(choice == '%')
        remind((int)no1,(int)no2);
    else if(choice == '!')
        fact((int)no1,(int)no2);
    else if(choice == '^')
        power((int)no1,(int)no2);
    else
        {printf("\n!!! Wrong Input !!!");
        return 0;}

    printf("Result= %.2f\n\n",result);
    goto label;
    return 0;
}
