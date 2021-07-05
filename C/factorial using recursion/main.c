#include <stdio.h>
#include <stdlib.h>

int factorial(int n,int result)
{
    if(n==1)
        return result;
    else
    {
        result=result*n;
        factorial(n-1,result);
    }
}

int main()
{
    int n,result=1;
    printf("Enter a number for factorial: ");
    scanf("%d",&n);
    result=factorial(n,result);
    printf("Factorial: %d \n\n",result);

    return 0;
}
