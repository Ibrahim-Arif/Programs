#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void delay(int MS)
{
    long pause;
    clock_t now, then;

    pause = MS * (CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int main()
{
    FILE *fptr1;
    FILE *fptr2;
    int ch;
    char p1=0, p2=0, p3=0, p4=0;
    int choice;
    char f1[150];
    printf("Enter 1 for Encryption.\nEnter 2 for Decryption.\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    if(choice== 1)
    {
        printf("Enter the name/address of file to encrypt: ");
        scanf("%s",f1);
        fflush(stdin);
        fptr1=fopen(f1,"r");
        fptr2=fopen("Encrypted file.txt","w");
        if(!fptr1)
            printf("Unable to open file :( ");
        else
        {
            while( !feof(fptr1) )
            {
                ch=fgetc(fptr1);
                ch=ch+77;
                fputc((char)ch,fptr2);
            }
            fclose(fptr1);
            fclose(fptr2);
            printf("\nFile encrypted successfully :)");
        }
    }

    else if(choice == 2 )
    {
        label:
        printf("\nEnter 4-digit password: ");
        p1=getch();    printf("*");
        p2=getch();   printf("*");
        p3=getch();   printf("*");
        p4=getch();   printf("*");

        if(p1=='1' && p2=='1' && p3=='2' && p4=='2' )
        {
        printf("\nAccess Granted :( \n");
        delay(200);
        printf("DECRYPTING, please wait");
        delay(300);     printf(".");
        delay(300);     printf(".");
        delay(300);     printf(".");
        delay(300);     printf(".");
        delay(300);     printf(".\n");

        fptr2=fopen("Encrypted file.txt","r");
        if( !fptr2 )
            printf("Unable to open file :( ");
        else
        {
            printf("\n\n");
            while( !feof(fptr2) )
            {
                ch=fgetc(fptr2);
                ch=ch-77;
                printf("%c",ch);
            }
        }
        }
        else
        {
            printf("\nAccess Denied :( \n\n");
            goto label;
        }
    }

    else
        printf("Wrong choice...\n\n");
    printf("\n\n");
    return 0;
}
