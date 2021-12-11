#include <stdio.h>
#include <stdlib.h>
#define size 5
int cqueue[size], front=-1, rear=-1;

void insert(int ele){
        if((front==rear+1) || (rear==size-1) && (front==0)){
            printf("Queue is full!");

        } else if(front==-1 && rear==-1){
            front = rear = 0;
            cqueue[rear] = ele;

        } else if(rear==size-1){
            rear = 0;
            cqueue[rear] = ele;

        } else {
            cqueue[++rear] = ele;
        }
}
void delete(){
    if(front==-1 && rear==-1){
        printf("Queue is empty!");

    } else if(front == rear){
        printf("Deleted element: %d",cqueue[front]);
        front = rear = -1;

    } else if(front == size-1){
        printf("Deleted element: %d",cqueue[front]);
        front = 0;

    } else {
        printf("Deleted element: %d",cqueue[front++]);
    }
}
void display(){
    if(front == -1){
        printf("Queue is empty!");
        return;
    }
    if(rear >= front){
        for(int i=front; i<=rear; i++)
            printf("%d, ",cqueue[i]);
    }else{
        for(int i=front; i<size; i++)
            printf("%d, ",cqueue[i]);
        for(int i=0; i<=rear; i++)
            printf("%d, ",cqueue[i]);
    }
}

int main()
{
    int choice, ele;
    printf("1: Insert \n2: Delete \n3: Display \n0: Quit \n");
    while(choice != 0){
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter element: ");
                scanf("%d",&ele);
                insert(ele);
                break;
            }
            case 2:{
                delete();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("Wrong input!");
                break;
            }
        }
    }
    return 0;
}
