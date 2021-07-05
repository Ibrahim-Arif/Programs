#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int find_prime(int arr[])
{
    int i, j, count=0,temp=0, a=0;
    for(i=0;i<20;i++)                           // to control index of array containing 20 random numbers
    {
        temp=arr[i];                                // temp will made this loop more flexible

        for(j=2;j<temp;j++)
        {
            if(temp % j == 0)                      // filter number prime or not
                a=1;
        }
        if(a==0 && temp != 1)                   // to count number of prime numbers and temp != 1 is to avoid 1 count as a prime
            count++;

        if(a==0 && temp != 1)                   // if temp is prime and not 1 then print prime
            printf("\n%d is a prime number.",temp);
        else
            printf("\n%d is not a prime number.",temp);

        a=0;                                                // getting old value for next number of array
    }
    return count;
}

int main()
{
    srand(time(0));
    int arr[20]={0}, temp=0, i,j, count=0,flag=0;             //these are local variables so it does not matter if we use same variable names in different functions

    for(i=0;i<20;i++)
    {
        //label:
        flag=0;
        temp = 1+(rand () %100);                    // will generate a random number between 0 - 99 and +1 will make it between 1 - 100

        for(j=0;j<20;j++)
        {
            if(temp == arr[j])
            {
                i--;                                            // i-- is to get the same index of array to store new random number in case of repetition
                flag=1;
                continue;
                //goto label;
            }
        }
        if(flag==0)
        {
            arr[i]=temp;                                   // is number is unique.. now it is ready to store in array
            temp=0;                                           // is to avoid any possibility of repetition of previous number
        }
    }

    printf("---20 random numbers---\n");
    for(i=0;i<20;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    count=find_prime(arr);                       // will take array containing non repeated numbers to function to check prime or not
    printf("\n\nThere are %d prime numbers.\n\n",count);

    return 0;                                                // THANK YOU FOR READING...
}
