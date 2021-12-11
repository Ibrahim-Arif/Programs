#include <stdio.h>
#include <stdlib.h>
#define CAP 50
int top = -1;
int stack[CAP];

void push(int ele){
    if( isFull() ){
        printf("Stack is overflow!");
    }else{
        stack[++top] = ele;
    }
}
int pop(){
    if(isEmpty()){
        printf("");
    }else{
        return stack[top--];
    }
}
int peek(){
        return stack[top];
}
void traverse(){
        for(int i=top; i>=0; i--)
            printf("%d",stack[i]);
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
int isGrouped(char str[]){
    char curr, searchOf;
    int i=0;

    while(str[i] != '\0'){
        curr = str[i];
        if( curr == '{' || curr == '(' )    push(curr);
        else if( curr == '}' || curr == ')' ){
            if(curr == '}')     searchOf = '{';
            else                   searchOf = '(';

            while( !isEmpty() ){
               curr = pop();
               if(curr == searchOf)     break;
            }
        }
        i++;
    }
    if(isEmpty())   return 1;
    return 0;
}
int main()
{
    int ind = 0, i=0;
    char str[CAP], curr;
    printf("Enter an expression: ");
    gets(str);
    if(!isGrouped(str)){
        printf("Not properly grouped, Indentation unavailable!");
        return 0;
    }
    top = -1;
    while(str[i] != '\0'){
        curr = str[i];
        if( curr=='{' || curr=='(' ){
            printf("\n");
            for(int i=1; i<=peek(); i++)        printf("\t");
            printf("%c \n",curr);
            push(++ind);
            for(int i=1; i<=peek(); i++)        printf("\t");
        }
        else if( curr=='}' || curr==')' ){
            pop();
            ind = peek();
            printf("\n");
            for(int i=1; i<=peek(); i++)       printf("\t");
            printf("%c \n",curr);
            for(int i=1; i<=peek(); i++)       printf("\t");
        }
        else    printf("%c",curr);
        i++;
    }
    printf("\n\n");
    return 0;
}
