#include <stdio.h>
#include <stdlib.h>

int foo(int n){
    int temp=0;
    if(n < 1)      return 0;

    temp = 1+ foo(n-1);
    printf("%d ",temp);
    return temp;
}

int main()
{
    foo(10);

    return 0;
}
