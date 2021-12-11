#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base,power,ans,i;
    printf("Enter base=");
    scanf("%d",&base);
    printf("Enter power=");
    scanf("%d",&power);
    for(i=1;i<power;i++)
    {
        if(i==1)
            ans=(base*base);
        else
            ans=ans*base;

    }
    printf("ans=%d",ans);
    return ;
}
