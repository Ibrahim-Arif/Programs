#include <stdio.h>
#include <stdlib.h>
struct node *root = NULL;
struct node{
    int data;
    struct node *link;
};

void append(){
    struct node *temp, *p;
    temp = (struct node*)malloc( sizeof(struct node) );
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if(root == NULL){
        root = temp;
    }else{
        p=root;
        while(p->link != NULL){
            p = p->link;
        }
        p->link = temp;
    }
}
void add_begin(){
    struct node *temp;
    temp = (struct node*)malloc( sizeof(struct node) );
    printf("Enter data: ");
    scanf("%d", &temp->data);

    temp->link = root;
    root = temp;
}
void add_after(int loc){
    struct node *p = root, *temp;
    if(loc > length()){
        printf("Location out of bound!");
    }else{
        temp = (struct node*)malloc( sizeof(struct node) );
        printf("Enter data: ");
        scanf("%d", &temp->data);
        for(int i=1; i<loc; i++){
            p = p->link;
        }
        temp->link = p->link;
        p->link = temp;
    }
}
void delete_first(){
    struct node *p=root;
    root = p->link;
    p->link = NULL;
    free(p);
}
void delete_specified(int loc){
    struct node *p = root, *q;
    for(int i=1; i<loc-1; i++){
        p = p->link;
    }
    q=p->link;
    p->link = q->link;
    q->link = NULL;
    free(q);
}
void display(){
    if(root == NULL){
        printf("List is empty!");
    }else{
        struct node *temp = root;

        while(temp != NULL){
            printf("%d, ",temp->data);
            temp = temp->link;
        }
        printf("\n");
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
void reverse(){
    int i=0, j, len = length(), temp;
    struct node *p = root, *q = root;
    j = len-1;
    while(i<j){
        for(int k=0; k<j; k++)
            q = q->link;

        temp = p->data;
        p->data = q->data;
        q->data = temp;

        i++;
        j--;
        p = p->link;
        q=root;
    }
}
void swap(int first, int second){
    struct node *prevF = NULL, *currF = root, *prevS = NULL, *currS = root, *temp;
    if(first == second){
        printf("Same elements! \n");
        return;
    }
    while(currF && currF->data != first){
        prevF = currF;
        currF = currF->link;
    }
    while(currS && currS->data != second){
        prevS = currS;
        currS = currS->link;
    }

    if(currF==NULL || currS==NULL){
        printf("Elements not found! \n");
        return;
    }

    if(prevF != NULL)
        prevF->link = currS;
    else
        root = currS;

    if(prevS != NULL)
        prevS->link = currF;
    else
        root = currF;

    temp = currS->link;
    currS->link = currF->link;
    currF->link = temp;
}
void sort(){
    struct node *curr = root, *next;
    int temp;
    if(root == NULL)
        return;
    while(curr != NULL){
        next = curr->link;
        while(next != NULL){
            if(curr->data > next->data ){
                temp = curr->data;
                curr->data = next->data;
                next->data = temp;
            }
            next = next->link;
        }
        curr = curr->link;
    }
}

int main()
{
    int choice, loc;
    printf("1: Append \n2: Add at begin \n3: Add After \n4: Delete first \n5: Delete specified \n6: Display \n7: Length \n8: Reverse \n9: Swap \n10: Sort \n0: Exit");
    do{
            printf("\nEnter your choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:{
                    append();
                    break;
                }
                case 2:{
                    add_begin();
                    break;
                }
                case 3:{
                    printf("Enter location: ");
                    scanf("%d",&loc);
                    add_after(loc);
                    break;
                }
                case 4:{
                    delete_first();
                    break;
                }
                case 5:{
                    printf("Enter location: ");
                    scanf("%d",&loc);
                    delete_specified(loc);
                    break;
                }
                case 6:{
                    display();
                    break;
                }
                case 7:{
                    printf("length: %d",length());
                    break;
                }
                case 8:{
                    reverse();
                    break;
                }
                case 9:{
                    int loc2;
                    printf("Enter elements: ");
                    scanf("%d %d",&loc, &loc2);
                    swap(loc, loc2);
                    break;
                }
                case 10:{
                    sort();
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
