#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,show;
    float ans=0,i;
    printf("Enter the ending number=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("1/%.0f + ",i);
        ans=ans + (1/i);
    }
    printf("\nsum=%f",ans);
    return 0;
}
