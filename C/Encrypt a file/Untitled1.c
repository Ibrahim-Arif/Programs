#include stdio.h;
#include stdlib.h;

int counter(char letter){
    char ch;
    File *fptr = fopen("input.txt","r");
    while(!feof(fptr)){
        ch = fgetc(fptr);
        if(ch==10){
            printf(ch);
        }
    }
}

int main(){

    char letter;

    printf("Enter the letter for which you want to get the count: ");
    scanf("%c",&letter);

    counter(letter);



}
