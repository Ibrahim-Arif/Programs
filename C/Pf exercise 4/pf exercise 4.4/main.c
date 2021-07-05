#include <stdio.h>
#include <stdlib.h>

function_celsius()
{
    int i,a=1,fah2;
    float fah,cel;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f",&fah);
    cel=(fah-32)*0.55556;
    printf("%.1f f = %.1f c\n",fah,cel);

    printf("\nFahrenheit\tCelsius\n");

    for(fah2=0;fah2<101;fah2++)
    {
        cel=(fah2-32)*0.55556;
        printf("%d\t%.1f\n",fah2,cel);

    }
}

function_fahrenheit()
{
    int i,a=1,cel2;
    float fah,cel;
    printf("\n\nEnter temperature in Celsius: ");
    scanf("%f",&cel);
    fah= (1.8*cel)+32;
    printf("%.1f c = %.1f f\n",cel,fah);
    printf("\nCelsius\tFahrenheit\n");

    for(cel2=0;cel2<101;cel2++)
    {
        fah= (1.8*cel2)+32;
        printf("%d\t%.1f\n",cel2,fah);

    }
}

int main()
{
    char choice;
    printf("Enter 1 for Fahrenheit to Celsius\n");
    printf("Enter 2 for Celsius to Fahrenheit\n");
    printf("Enter your choice: ");\
    choice=getche();
    if(choice=='1')
        function_celsius();
    else if(choice=='2')
        function_fahrenheit();
    else
        printf("\n!!! Wrong Input !!!\n\n");
    return 0;
}
