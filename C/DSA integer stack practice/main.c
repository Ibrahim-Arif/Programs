#include <stdio.h>
#include <stdlib.h>
#define CAP 5

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
        printf("Stack is underflow!");
        return -1;
    }else{
        return stack[top--];
    }
}

int peek(){
    if(isEmpty()){
        printf("Stack is underflow!");
        return;
    }else{
        return stack[top];
    }
}

void traverse(){
    if(isEmpty()){
        printf("Stack is underflow!");
        return;
    }else{
        printf("Stack elements are: ");
        for(int i=0; i<=top; i++){
            printf("%d, ",stack[i]);
        }
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
    if(top == 4){
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
    int choice, ele;
    printf("1: push \n2: pop \n3: peek \n4: traverse \n5: length \n0: exit");
    do{
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("Enter an element to push: ");
                scanf("%d",&ele);
                push(ele);
                break;
            }
            case 2:{
                choice = pop();
                if(choice != -1)    printf("pop element: %d",choice);
                break;
            }
            case 3:{
                printf("peek element: %d",peek());
                break;
            }
            case 4:{
                traverse();
                break;
            }
            case 5:{
                printf("Current length of stack: %d",length());
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("wrong input");
            }
        }

    }while(choice != 0);
    return 0;
}
