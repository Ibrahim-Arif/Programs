#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1, odd_product=1;
    while(i<20)
    {
        if(i%2!=0)
            odd_product=odd_product*i;
        i++;
    }
    printf("Odd product of first 30: %d\n\n",odd_product);
    return 0;
}
