#include <stdio.h>
#include <stdlib.h>

void hours(float hour[])
{
    int i,j=1;
    for(i=0;i<3;i++)
    {
        printf("Enter %d employ no. of hours:  ",j);
        scanf("%f",&hour[i]);
        j++;
    }
}
void rates(float rate[])
{
    int i, j=1;
    for(i=0;i<3;i++)
    {
        printf("Enter %d employ hourly rate:  ",j);
        scanf("%f",&rate[i]);
        j++;
    }
}
void b_salarys(float hour[], float rate[])
{
    int j=1;
    float b_salary[3];
    for(int i=0;i<3;i++)
    {
        b_salary[i] = hour[i] * rate[i];
    }
    for(int i=0;i<3;i++)
    {
        printf("Basic salary of %d employee is %.2f\n",j, b_salary[i]);
        j++;
    }
}

int main()
{
    float hour[3], rate[3];
    hours(hour);
    printf("\n");
    rates(rate);
    printf("\n");
    b_salarys(hour, rate);
    return 0;
}
