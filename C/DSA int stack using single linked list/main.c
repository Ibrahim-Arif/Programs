#include <stdio.h>
#include <stdlib.h>
struct node *root = NULL, *top, *second_top;

struct node{
    int roll;
    char name[30];
    struct node *link;
};

void push(){
    struct node *temp, *p;
    char name[20];
    temp = (struct node*)malloc( sizeof(struct node) );
    printf("Enter name: ");
    scanf("%s", temp->name);
    printf("Enter roll number: ");
    scanf("%d",&temp->roll);
    temp->link = NULL;

    if(root == NULL){
        root = temp;
    }else{
        p=root;
        while(p->link != NULL){ //->link
            p = p->link;
        }
        p->link = temp;
    }
}
int length(){
    struct node *temp = root;
    int count=0;
    while(temp != NULL){
        temp = temp->link;
        count++;
    }
    return count;
}
void display(){
    if(root == NULL){
        printf("Stack underflow!");
    }else{
        struct node *temp = root;
        while(temp != NULL){
            printf("%s-%d, ",temp->name, temp->roll);
            temp = temp->link;
        }
        printf("\n");
    }
}
void pop_peek(int choice){
    struct node *temp;
    if(root == NULL)
        printf("Stack underflow!");
    else{
        getLast();
        printf("Top: %s-%d \n", top->name, top->roll);
        if(choice == 1)
            second_top->link = NULL;
    }
}
void getLast(){
    struct node *curr = root, *prev;
    while(curr->link != NULL){
        prev = curr;
        curr = curr->link;
    }
    top = curr;
    second_top = prev;
}

int main()
{
    int choice;
    printf("1: push \n2: pop \n3: peek \n4: display \n5: length \n0: exit");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                push();
                break;
            }
            case 2:{
                pop_peek(1);
                break;
            }
            case 3:{
                pop_peek(0);
                break;
            }
            case 4:{
                display();
                break;
            }
            case 5:{
                printf("length: %d",length());
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
    return 0;
}
