#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 100
int top = -1;
char stack[CAP], str[CAP];

void push(char ele){
    if( isFull() ){
        printf("");
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
    if(isEmpty()){
        printf("");
    }else{
        return stack[top];
    }
}
void traverse(){
    if(isEmpty()){
        printf("");
    }else{
        for(int i=top; i>=0; i--){
            printf("%c",stack[i]);
        }
        printf("\n");
    }
}
int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(){
    if(top == CAP-1){
        return 1;
    }else{
        return 0;
    }
}
int length(){
    return top+1;
}
int precedence(char op){
    if(op == '(' || op == ')' || op == '{' || op == '}')               return 4;
    else if(op == '^')                                                            return 3;
    else if(op == '*' || op == '/' || op == '%')                      return 2;
    else if(op == '+' || op == '-')                                         return 1;
    else return;
}
void string_reverse(){
    int i=0;
    while(str[i] != '\0')   push(str[i++]);
    str[0] = '\0';
    i=0;
    while(!isEmpty())   str[i++] = pop();
}

int main()
{
    int i=0, j=0;
    char curr,  str2[CAP], searchOf;
    printf("Enter  an expression: ");
    gets(str);
    string_reverse();
    top = -1;

    while(str[i] != '\0'){
        curr = str[i];
        if(isalpha(curr) || isdigit(curr))                                                str2[j++] = curr;
        else if(peek()== ')' || peek()=='}' || curr==')' || curr=='}')      push(curr);
        else if(curr=='(' || curr=='{'){
            if(curr == '(')     searchOf = ')';
            else                  searchOf = '}';
            char so = pop();
            while(so != searchOf){
                    str2[j++] = so;
                    so = pop();
            }
        }
        else if(precedence(curr) > precedence( peek() ))            push(curr);
        else if(precedence(curr) == precedence( peek() ))          push(curr);       //R -> L is missing
        else if(precedence(curr) < precedence( peek() )){
            str2[j++] = pop();
            continue;
            push(curr);
        }
        i++;
    }
    while(!isEmpty()) str2[j++]=pop();
    str2[j]='\0';
    strcpy(str, str2);
    string_reverse();
    puts(str);
    return 0;
}
