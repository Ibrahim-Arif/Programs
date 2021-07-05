#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age, gender;
    char marriage;
    printf("Use m for Married\nUse u for Unmarried\nUse 1 for Male\nUse 0 for Female\n\n");
    printf("RelationShip status: ");
    scanf("%c",&marriage);

    if(marriage == 'm')
    {
        printf("Driver is Insured.\n");
        return 0;
    }
    printf("Gender: ");
    scanf("%d",&gender);

    printf("Enter age: ");
    scanf("%d",&age);
    if(marriage == 'u' && gender == 1 && age>30)
    {
        printf("Driver is Insured.\n");
    }
    else if(marriage == 'u' && gender == 0 && age>25)
    {
        printf("Driver is Insured.\n");
    }
    else{
        printf("Driver is Not insured.\n");
    }


    return 0;
}
