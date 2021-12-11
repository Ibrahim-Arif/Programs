#include <stdio.h>
#include <stdlib.h>

char *undo, *redo;
int topU = -1, topR = -1;

void push(char ele, char *stack, int *top){
    if( isFull(*top) ){
        printf("Stack is overflow!");
    }else{
        *top = *top +1;
        *(stack + *top) = ele;
    }
}

char pop(char *stack, int *top){
    if(isEmpty(*top)){
        printf("Stack is underflow!");
        return '0';
    }else{
        char c = *(stack + *top);
        *top = *top -1;
        return c;
    }
}

void traverse(char *stack, int top){
    if(isEmpty(top)){
        printf("Stack is underflow!");
    }else{
        printf("Stack elements are: ");
        for(int i=0; i<=top; i++){
            printf("%c",*(stack+i));
        }
    }
}

int isEmpty(int top){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(int top){
    if(top == 99){
        return 1;
    }else{
        return 0;
    }
}

int length(int top){
    return top+1;
}

int main()
{
    int choice;
    char ch;
    undo = (char*)malloc(100*sizeof(char));
    redo = (char*)malloc(100*sizeof(char));
    printf("1: Add character \n2: Undo \n3: Redo \n4: print\n0 : exit");

    do{
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                printf("Enter character to add: ");
                scanf(" %c",&ch);
                push(ch, undo, &topU);
                printf("Character Added!");
                break;
            }
            case 2:{
                ch = pop(undo, &topU);
                if(ch != '0'){
                    push(ch, redo, &topR);
                    printf("undo successfully!");
                }
                break;
            }
            case 3:{
                ch = pop(redo, &topR);
                if(ch != '0'){
                    push(ch, undo, &topU);
                    printf("undo successfully!");
                }
                break;
            }
            case 4:{
                traverse(undo, topU);
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("wrong input!");
            }
        }

    }while(choice != 0);
}
