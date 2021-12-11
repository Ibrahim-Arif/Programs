#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1, even_sum=0;
    while(i<31)
    {
        if(i%2==0)
            even_sum=even_sum+i;
        i++;
    }
    printf("even sum of first 30: %d\n\n",even_sum);
    return 0;
}
