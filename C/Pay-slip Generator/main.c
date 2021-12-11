#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int BS,EY,PIA,G,RP,ADH,A,GP,AI,IT,DA,TD,NP;
    float HRA,SSA,ITR,GPF;
    char S;
    printf("\nEnter your scale: ");
    scanf("%c",&S);
    printf("Enter your Age: ");
    scanf("%d",&A);
    printf("Experience in Years: ");
    scanf("%d",&EY);
    printf("\n__________________________");
    printf("\n\nBasic Pay");
    printf("\n_________\n");

    if(S=='W')
    {
         BS=10000;
         RP=BS+(EY*700);
         printf("\nBasic Salary:                    %5.2d",BS);
         printf("\nNo of Increments:             %5.2d",EY);
         printf("\nRunning Pay:                     %5.2d",RP);
    }
    else if(S=='X')
    {
         BS=12900;
         RP=BS+(EY*910);
         printf("\nBasic Salary:                    %5.2d",BS);
         printf("\nNo of Increments:             %5.2d",EY);
         printf("\nRunning Pay:                     %5.2d",RP);
    }
    else if(S=='Y')
    {
         BS=21700;
         RP=BS+(EY*1500);
         printf("\nBasic Salary:                    %5.2d",BS);
         printf("\nNo of Increments:             %5.2d",EY);
         printf("\nRunning Pay:                     %5.2d",RP);
    }
    else if(S=='Z')
    {
         BS=32600;
         RP=BS+(EY*2800);
         printf("\nBasic Salary:                    %5.2d",BS);
         printf("\nNo of Increments:             %5.2d",EY);
         printf("\nRunning Pay:                     %5.2d",RP);
    }
    else
        {
            printf("Incorrect Scale.\n");
        }

    printf("\n\nAllowances");
    printf("\n___________");

    HRA= 0.45*RP;
    printf("\nHouse Rent Allowance:            %5.2f",HRA);

    SSA= 0.3*BS;
    printf("\nSocial Security Benefits:        %5.2f",SSA);

    if(S=='W' && A>=40)
    {
            ADH=3000;
            printf("\nAdhoc Relief Allowance:         %5.2d",ADH);
    }
    else
        {
            ADH=1500;
            printf("\nAdhoc Relief Allowance:         %5.2d",ADH);
        }


    GP=RP+HRA+SSA+ADH;
    printf("\nGross Pay:                       %5.2d",GP);

    printf("\n\nDeductions");
    printf("\n___________");

    AI= GP*12;

    if(AI>=0 && AI<=400000)
    {
        ITR=0;
        IT=ITR*AI;
        IT=IT/12;
        printf("\nIncome Tax (at %5.2f%):          %5.2d",ITR,IT);
    }
    else if(AI>=400001 && AI<=650000)
    {
        ITR=2.5;
        IT=(ITR/100)*AI;
        IT=IT/12;
        printf("\nIncome Tax (at %5.2f%):          %5.2d",ITR,IT);
    }
    else if(AI>=650001 && AI<=1000000)
    {
        ITR=4.75;
        IT=(ITR/100)*AI;
        IT=IT/12;
        printf("\nIncome Tax (at %5.2f%):          %5.2d",ITR,IT);
    }
    else if(AI>=1000001 && AI<=1500000)
    {
        ITR=7;
        IT=(ITR/100)*AI;
        IT=IT/12;
        printf("\nIncome Tax (at %5.2f%):          %5.2d",ITR,IT);
    }
    else
    {
        ITR=11.5;
        IT=(ITR/100)*AI;
        IT=IT/12;
        printf("\nIncome Tax (at %5.2f%):          %5.2d",ITR,IT);
    }

    GPF=0.1*GP;
    printf("\nGeneral Provident Fund:          %5.2f",GPF);

    DA=GP%100;
    GP=GP-DA;
    printf("\nDonation:                     %5.2d",DA);

    TD=IT+GPF+DA;
    printf("\n\nTotal Deductions:               %5.2d",TD);

    NP=GP-TD;
    printf("\n\nNet Pay:                         %5.2d\n",NP);

}

