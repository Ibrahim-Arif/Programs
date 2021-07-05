#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 30
int heap[size];
int *root = NULL, index=1, tail=size-1;

void    insert(int ele){
    if(heap[1] == NULL){
        heap[index++] = ele;
        return;
    }
    int i = index, j, temp;
    heap[index] = ele;

    while(i != 1){
        j = i;                                  //previous index of last greatest swap
        i /= 2;                                // parent of i = i/2
        if(ele > heap[i]){              // '< ' for min heap
            temp = heap[i];
            heap[i]= ele;
            heap[j] = temp;
        }
    }
    index++;
}
void    display(){
    if(index == 1){
        printf("heap is empty!");
        return;
    }
    for(int i=1; i<index; i++)
        printf("%d, ",heap[i]);
    printf("\n");
}
int       max(int a, int b){
    return (heap[a] > heap[b]) ? a : b;
}
int       leftChild(int i){
    return 2*i;
}
int       rightChild(int i){
    return (2*i)+1;
}
void    delete(){
    if(index == 1){
        printf("Heap is empty!");
        return;
    }
    heap[tail--] = heap[1];                 //largest element into last index, for sorting
    heap[1] = heap[--index];            //last element of heap to root (temporary)

    int i = 1, maxi, temp;
    while(i < index){
        if(leftChild(i)>index || rightChild(i)>index)       break;          // if any index have no child then break;

        maxi = max( leftChild(i), rightChild(i) );
        if(heap[maxi] > heap[i]){
            temp = heap[i];
            heap[i] = heap[maxi];
            heap[maxi] = temp;
        }
        i = maxi;
    }
}
void    sorted(){
    if(tail == size-1){
        printf("Nothing sorted yet!");
        return;
    }
    printf("Sorted elements are: ");
    for(int i=size-1; i>tail; i--){
        printf("%d, ",heap[i]);
    }
    printf("\n");
}
void    search(int ele){
    for(int i=1; i<index; i++){
        if(ele == heap[i])  printf("Found!");
    }
}

int main()
{
    int choice, ele;
    printf("1: Insert \n2: Delete \n3: Search \n4: Display \n5: Sorted \n0: Exit \n");
    while(choice){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                printf("Enter element: ");
                scanf("%d",&ele);
                insert(ele);
                root = &heap[1];
                break;
            }
            case 2:{
                delete();
                break;
            }
            case 3:{
                printf("Enter element to search: ");
                scanf("%d",&ele);
                search(ele);
                break;
            }
            case 4:{
                display();
                break;
            }
            case 5:{
                sorted();
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("Wrong input!");
            }
        }
    }
    return 0;
}
