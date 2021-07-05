#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    const char *arti[5] = { "The", "A","Some","One","Any"};
    const char *noun[5] = { "faizan", "umer","bilal","shamraiz","ali"};
    const char *verb[5] = { "drove", "jumped","ran","sucks","fucked"};
    const char *prep[5] = { "to", "from","over","under","on"};
    int arti1=0, arti2=0, noun1=0, noun2=0,  verbb=0, prepp=0;

    for(int i=1;i<21;i++)
    {
        arti1 = rand() % 5;
        arti2 = rand() % 5;
        noun1= rand() % 5;
        noun2 = rand()% 5;
        verbb = rand() % 5;
        prepp = rand() % 5;

        printf("%d: %s %s %s %s %s %s.",i,arti[arti1], noun[noun1], verb[verbb], prep[prepp], arti[arti2], noun[noun2]);
        printf("\n");
    }
        return 0;
}
