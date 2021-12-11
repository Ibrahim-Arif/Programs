#include <stdio.h>
#include <stdlib.h>
#define CAP 50
int top = -1;
char stack[CAP];

void push(char ele){
    if( isFull() ){
        printf("Stack is overflow!");
    }else{
        stack[++top] = ele;
    }
}
char pop(){
    if(isEmpty()){
        printf("");
    }else{
        return stack[top--];
    }
}
char peek(){
        return stack[top];
}
void traverse(){
        for(int i=top; i>=0; i--)
            printf("%c",stack[i]);
}
int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(){
    if(top == 29){
        return 1;
    }else{
        return 0;
    }
}
int length(){
    return top+1;
}
int main()
{
    char str[CAP], curr, searchOf;
    int start=0, end=0, i=0, count=0;
    printf("Enter an expression: ");
    gets(str);

    while(str[i] != '\0'){
        curr = str[i];
        if( curr == '{' || curr == '(' )    push(curr);
        else if( curr == '}' || curr == ')' ){
            end = 1;
            if(curr == '}')     searchOf = '{';
            else                   searchOf = '(';

            while(!isEmpty()){
               curr = pop();
               if(curr == searchOf) {
                   start = 1;
                   break;
               }
            }
        }
        if(start==1 && end==1){
            count++;
            start = end = 0;
        }
        i++;
    }
    if(isEmpty() || count!=0)  printf("Total groups: %d", count);
    else                printf("Does not match a matching group symbol");

    printf("\n\n");
    return 0;
}
