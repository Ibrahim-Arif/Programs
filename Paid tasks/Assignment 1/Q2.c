#include <stdio.h>
#include <stdlib.h>

// function to calculate gross pay
float calculateGrossPay(int hours, float gbp){
    float grossPay;

    // if hours <= 38 then no over pay, else we will use 1.5 times the GBP
    if(hours <= 38){
        grossPay = hours * gbp;
    }else{
        grossPay = 38 * gbp;
        grossPay += (hours - 38) * (gbp * 1.5);
    }

    return grossPay;
}

float calculateTax(float grossPay){
    float tax = 0;

    // if gross pay <= 300 then simple 0.15 tax
    if(grossPay <= 300){
        tax = grossPay * 0.15;
    } else if(grossPay <= 500){
    // if gross pay <= 500, then 0.15 for first 300 and 0.2 for the rest
        grossPay -= 300;
        tax = 300 * 0.15;
        tax += grossPay * 0.2;
    } else if(grossPay <= 650){
    // if gross pay <= 650, then 0.15 for first 300 and 0.2 for next 200 and 0.25 from the rest
        grossPay -= 300;
        tax = 300 * 0.15;
        tax += 200 * 0.2;
        grossPay -= 200;
        tax += grossPay * 0.25;
    } else{
    // if gross pay is > 650, then 0.15 for first 300 and 0.2 for next 200 and 0.25 from the next 150 and 0.3 for the rest
        grossPay -= 300;
        tax = 300 * 0.15;
        tax += 200 * 0.2;
        grossPay -= 200;
        tax += 150 * 0.25;
        grossPay -= 150;
        tax += grossPay * 0.3;
    }

    return tax;
}

int main(){
    int choice, hours=0;
    float gbp=0, grossPay, tax;

    // pay rate menu
    printf("Enter the number corresponding to the desired pay rate: \n");
    printf("1-  8.50 GBP/hour      2-  9.90 GBP/hour \n");
    printf("3- 22.40 GBP/hour      4- 30.00 GBP/hour \n");

    // user input choice 1-4
    printf("\n: ");
    scanf("%d", &choice);

    // if choice is not from 1-4
    if(choice < 1 || choice > 4){
        printf("Wrong choice !! \n");
        exit(0);
    }

    printf("Enter number of hours worked in week: ");
    scanf("%d", &hours);

    // GBP according to user selected pay
    if(choice == 1){
        gbp = 8.5;
    } else if(choice == 2){
        gbp = 9.9;
    } else if(choice == 3){
        gbp = 22.4;
    } else if(choice == 4){
        gbp = 30;
    }

    grossPay = calculateGrossPay(hours, gbp);
    tax = calculateTax(grossPay);

    printf("\nGross Pay: %.2f \n", grossPay);
    printf("Taxes: %.2f \n", tax);
    printf("Net Pay: %.2f \n", grossPay - tax);

    return 0;
}
