#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x,p;
    printf("Enter original price of item:\n");
    scanf("%d",&n);
    printf("Enter Sale price:\n");
    scanf("%d",&x);
    p=x-n;
    if(p>1)
    {
        printf("Profit is=%d",p);
    }
    else if(p<1)
    {
        printf("Loss is=%d",p);
    }
return 0;
}
