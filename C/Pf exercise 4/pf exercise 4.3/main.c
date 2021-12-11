#include <stdio.h>
#include <stdlib.h>

float calculate_charges(float hours)
{
    float charges;
    if(hours<=3)
    {
        charges=2;
        return charges;
    }
    else if(hours>3 && hours<24)
    {
        hours=hours-3;
        charges=(hours*0.5)+2;
        if(charges>10)
            charges=10;
        return charges;
    }
    else if(hours==24)
    {
        charges=10;
        return charges;
    }
}

int main()
{
    float hours1, hours2, hours3,charge1,charge2,charge3,t_hours,t_charge;

        printf("Enter 1st car hours(1 to 24): ");
        scanf("%f",&hours1);
        charge1=calculate_charges(hours1);

        printf("Enter 2nd car hours(1 to 24): ");
        scanf("%f",&hours2);
        charge2=calculate_charges(hours2);

        printf("Enter 3rd car hours(1 to 24): ");
        scanf("%f",&hours3);
        charge3=calculate_charges(hours3);

        t_hours=hours1+hours2+hours3;
        t_charge=charge1+charge2+charge3;

        printf("\nCar\tHours\tCharge\n");
        printf("1\t%.1f\t%.2f\n",hours1,charge1);
        printf("2\t%.1f\t%.2f\n",hours2,charge2);
        printf("3\t%.1f\t%.2f\n",hours3,charge3);
        printf("TOTAL\t%.1f\t%.2f\n\n",t_hours,t_charge);


    return 0;
}
