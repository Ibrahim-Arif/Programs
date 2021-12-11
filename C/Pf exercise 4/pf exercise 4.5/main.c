#include <stdio.h>
#include <stdlib.h>

int GCD(int x, int y)
{
    if(y==0){
        return x;
    }
    else{
        return GCD(y, x%y);
    }

}

int main()
{
    int a, b, result;
    printf("Enter 2 numbers: ");
    scanf("%d %d",&a,&b);
    result = GCD(a,b);
    printf("result: %d\n\n",result);

    return 0;
}
