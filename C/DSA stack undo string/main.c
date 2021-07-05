#include <stdio.h>                      //https://www.hackerrank.com/challenges/simple-text-editor/problem
#include <stdlib.h>
#include <string.h>
char undo[20][20], s[100];
int top = -1;

void push(char c[100]){
    top++;
    for(int i=0; i<strlen(c); i++){
        undo[top][i] = c[i];
    }
}
void append(char w[]){
    push(s);
    strcat(s, w);
}
void delete(int k){
    push(s);
    s[strlen(s)-k] = '\0';
}
void print(int k){
    puts(s);
    printf("character at %d: %c \n",k,s[k-1]);

    //To print complete stack
    /*for(int i=0; i<=top; i++){
       puts(undo[i]);
    }*/
}
void undoo(){
    memset(s,0,strlen(s));
    for(int i=0; i<strlen(undo[top]); i++){
        s[i] = undo[top][i];
    }
    top--;
}

int main()
{
    int choice, k, op;
    char w[20];
    printf("1: append \n2: delete \n3: print \n4: undo \nEnter number of operations: ");
    scanf("%d",&op);

    for(int i=0; i<op; i++){
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                scanf("%s",&w);
                append(w);
                break;
            }
            case 2:{
                scanf("%d",&k);
                delete(k);
                break;
            }
            case 3:{
                scanf("%d",&k);
                print(k);
                break;
            }
            case 4:{
                undoo();
                break;
            }
            default:{
                printf("wrong input");
                break;
            }
        }
    }
    return 0;
}
