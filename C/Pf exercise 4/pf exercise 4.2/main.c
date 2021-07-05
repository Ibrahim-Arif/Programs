#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(void)
{
    int num1, num2, num3, num4, num5, num6;

    num1 = (rand()% 2)+1;
    printf("num1= %d\n",num1);

    num2 = (rand()%101)+1;
    printf("num2= %d\n",num2);

    num3 = rand()%10;
    printf("num3= %d\n",num3);

    num4 = (rand()%113)+1000;
    printf("num4= %d\n",num4);

    num5= (rand()%2)-(1/2);
    printf("num5= %d\n",num5);

    num6=(rand()%12)-(11/2);
    printf("num6= %d\n",num6);

    return 0;
}
