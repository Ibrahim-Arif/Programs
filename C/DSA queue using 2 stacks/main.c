#include <stdio.h>                                  //https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
#include <stdlib.h>
int *first, *second;
int topF = -1, topS = -1;

void push(int ele, int *stack, int *top){
    *top = *top+1;
    *(stack + *top) = ele;
}
int pop(int *stack, int *top){
    if(isEmpty(*top)){
        printf("Stack is underflow!");
        return 0;
    }else{
        int c = *(stack + *top);
        *top = *top - 1;
        return c;
    }
}
void traverse(int *stack, int top){
    if(isEmpty(top)){
        printf("Stack is underflow!");
    }else{
        printf("%d \n",*(stack++) );
    }
}
int isEmpty(int top){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    int times, choice, ele;
    first = (int*)calloc(100, sizeof(int));
    second = (int*)calloc(100, sizeof(int));

    scanf("%d",&times);
    while(times--){
        scanf("%d", &choice);
        if(choice == 1){
            scanf("%d",&ele);
            push(ele, first, &topF);
        }
        else{
            if(isEmpty(topS)){
                while(!isEmpty(topF)){
                    ele = pop(first, &topF);
                    push(ele, second, &topS);
                }
            }
            if( !isEmpty(topS) ){
                if(choice == 2)     pop(second, &topS);
                if(choice == 3)     traverse(second, topS);
            }
        }
    }
    return 0;
}
