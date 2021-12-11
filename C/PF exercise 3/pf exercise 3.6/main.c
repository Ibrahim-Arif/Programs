#include <stdio.h>
#include <stdlib.h>

int main()
{
    float gs, sales, salary;
    while(sales != -1)
    {
    printf("Enter sales in pounds (-1 to end): ");
    scanf("%f",&sales);
    if(sales != -1)
    {
    gs = 0.09 * sales;
    salary = gs + 200;
    printf("Salary is: %.2f\n",salary);
    }
    }
}
