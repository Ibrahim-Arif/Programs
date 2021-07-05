#include <stdio.h>
#include <stdlib.h>

char arr[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char player1[15], player2[15];
int count=1;
int label1;

grid_screen();
check_win();
char input();
who_turn(int);
again();


int main()
{
    char choice;
    printf("\n");
    printf("\n\t\t\t-----------------\t\t\t\t\t\b---------------------------\n");
    printf("\t\t\t|  Tic Tac Toe  |\t\t\t\t\t\b|  Made by: Ali Shazaib  |");
    printf("\n\t\t\t-----------------\t\t\t\t\t\b---------------------------\n");
    printf("\n");

    printf("\t1. Start Game.");
    printf("\n\t2. Quit Game.\n");
    printf("\n Enter your choice: ");
    choice = getche();
    if(choice== '1' )
    {
        printf("\n\n Who is playing for X: ");
        scanf("%s",player1);
        printf(" Welcome %s your sign is X\n",player1);
        printf("\n Who is playing for O: ");
        scanf("%s",player2);
        printf(" Welcome %s your sign is O\n\n\n\n",player2);
        system("pause");
        system("cls");
        grid_screen();
        input();
        //system("exit");
    }
    else if(choice== '2' )
    {
        system("exit");
    }


}

grid_screen()
{
    printf("\n");
    printf("\t %c | %c | %c\n",arr[1],arr[2],arr[3]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c\n",arr[4],arr[5],arr[6]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c\n\n",arr[7],arr[8],arr[9]);


}

check_win()
{
    //Win_Case for X (Player-1)
    if(arr[1]=='X' && arr[2]=='X' && arr[3]=='X')
        return 'X';
    else if(arr[1]=='X' && arr[4]=='X' && arr[7]=='X')
        return 'X';
    else if(arr[1]=='X' && arr[5]=='X' && arr[9]=='X')
        return 'X';
    else if(arr[1]=='X' && arr[4]=='X' && arr[7]=='X')
        return 'X';
    else if(arr[2]=='X' && arr[5]=='X' && arr[8]=='X')
        return 'X';
    else if(arr[1]=='X' && arr[4]=='X' && arr[7]=='X')
        return 'X';
    else if(arr[3]=='X' && arr[6]=='X' && arr[9]=='X')
        return 'X';
    else if(arr[3]=='X' && arr[5]=='X' && arr[7]=='X')
        return 'X';
    else if(arr[4]=='X' && arr[5]=='X' && arr[6]=='X')
        return 'X';
    else if(arr[7]=='X' && arr[8]=='X' && arr[9]=='X')
        return 'X';

    //Win_Case for O (Player-2)
    else if(arr[1]=='O' && arr[2]=='O' && arr[3]=='O')
        return 'O';
    else if(arr[1]=='O' && arr[4]=='O' && arr[7]=='O')
        return 'O';
    else if(arr[1]=='O' && arr[5]=='O' && arr[9]=='O')
        return 'O';
    else if(arr[1]=='O' && arr[4]=='O' && arr[7]=='O')
        return 'O';
    else if(arr[2]=='O' && arr[5]=='O' && arr[8]=='O')
        return 'O';
    else if(arr[1]=='O' && arr[4]=='O' && arr[7]=='O')
        return 'O';
    else if(arr[3]=='O' && arr[6]=='O' && arr[9]=='O')
        return 'O';
    else if(arr[3]=='O' && arr[5]=='O' && arr[7]=='O')
        return 'O';
    else if(arr[4]=='O' && arr[5]=='O' && arr[6]=='O')
        return 'O';
    else if(arr[7]=='O' && arr[8]=='O' && arr[9]=='O')
        return 'O';
    else if(count == 9)
        return 'T';
}

char input()
{
    int location;
    char win,again;
    label:
    printf("Enter the Location: ");
    scanf("%d",&location);
    if(arr[location] == ' ')
    {
        if(count%2==0)
        arr[location]='O';
    else
        arr[location]='X';

    }
    else
    {
            printf("\n!!! Location is occupied. !!!\n\n");
            goto label;
    }

    system("cls");
    grid_screen();
    check_win();
    win=check_win();
        if(win=='X')
            {
                printf("\n\t-----------------------------------");
                printf("\n\t       Congratulations! %s wins      \n",player1);
                printf("\t-----------------------------------\n\n");
                goto breaak;
            //system("pause");
            }
        else if(win=='O')
            {
                printf("\n\t-----------------------------------");
                printf("\n\t      Congratulations! %s wins     \n",player2);
                printf("\t-----------------------------------\n\n");
                goto breaak;
            //system("pause");
            }
        else if(win=='T')
            {
                printf("\n\t  !!!.Match Tied.!!! \n\n\n",player2);
                goto breaak;
            }
    whos_turn(count);

    count++;
    goto label;
    breaak:
    system("pause");
    system("exit");
}

whos_turn(int count)
{
    if(count%2==0)
    {   printf("------------------------");
        printf("\n\t\b\b%s\'s turn\n\n",player1); }
    else
    {
        printf("------------------------");
        printf("\n\t\b\b%s\'s turn\n\n",player2);
    }
}
