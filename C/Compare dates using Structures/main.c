#include <stdio.h>
#include <stdlib.h>

typedef struct date
{
    int dd;
    int mm;
    int yy;
}date;

void input(date *date1, date *date2)
{
    printf("Enter 1st date (dd/mm/yy): ");
    scanf("%d %d %d",&date1 -> dd, &date1 -> mm, &date1 -> yy);

    printf("Enter 2nd date (dd/mm/yy): ");
    scanf("%d %d %d", &date2 -> dd, &date2 -> mm, &date2 -> yy);
}

int compare(date date1, date date2)
{
    if( date1.dd==date2.dd && date1.mm==date2.mm && date1.yy==date2.yy )
        return 1;
    else
        return 0;
}

int main()
{
    int result=0;
    date date1, date2;

    input(&date1, &date2);
    result = compare(date1, date2);

    if(result == 1)
        printf("Dates are equal.");
    else
        printf("Dates are not equal.");

    printf("\n\n");
    return 0;
}
