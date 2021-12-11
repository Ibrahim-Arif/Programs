#include <stdio.h>
#include <stdlib.h>
struct node *root = NULL;

struct student{
    char name[20];
    int id;
};
struct node{
    struct student *std;
    struct node *left;
    struct node *right;
};

void append(){
    struct node *p = root, *temp;
    struct student *std;
    std = (struct student*)calloc(1,sizeof(struct student));
    printf("Enter name: ");
    scanf("%s",std->name);
    printf("Enter id: ");
    scanf("%d",&std->id);
    temp = (struct node*) calloc(1,sizeof(struct node));
    temp->std = std;

    if(root == NULL)
        root = temp;
    else{
        while(p->right != NULL)
            p = p->right;

        p->right = temp;
        temp->left = p;
    }
}
void display(){
    struct node *p;
    if(root == NULL)
        printf("List is empty!");
    else{
        p=root;
        while(p != NULL){
            printf("%s-%d, ",p->std->name, p->std->id);
            p=p->right;
        }
        printf("\n");
    }
}
void add_begin(){
    struct student *std;
    struct node *temp;
    std = (struct student*)calloc(1, sizeof(struct student));
    printf("Enter name: ");
    scanf("%s",std->name);
    printf("Enter id: ");
    scanf("%d",&std->id);
    temp = (struct node*)calloc(1, sizeof(struct node));
    temp->std = std;

    if(root == NULL)
        root = temp;
    else{
        temp->right = root;
        root->left = temp;
        root = temp;
    }
}
void add_after(int loc){
    struct node *temp, *p = root;
    struct student *std;
    if(loc >= length())
        printf("location out of bound!");
    else{
        std = (struct student*)calloc(1, sizeof(struct student));
        printf("Enter name: ");
        scanf("%s",std->name);
        printf("Enter id: ");
        scanf("%d",&std->id);

        temp = (struct node*)calloc(1, sizeof(struct node));
        temp->std = std;

        for(int i=1; i<loc; i++)
            p = p->right;

        temp->right = p->right;
        p->right->left = temp;
        p->right=temp;
        temp->left = p;
    }
}
int length(){
    struct node *p = root;
    int count=0;
    if(p == NULL)
        return 0;
    else{
        while(p != NULL){
            p = p->right;
            count++;
        }
        return count;
    }
}
void delete(int id){
    struct node *p = root;
    if(root->std->id == id){
        p->right->left = NULL;
        root = p->right;
    }else{
        while(p->std->id != id){
            p = p->right;
        }
        p->left->right = p->right;
        p->right->left = p->left;
        p->left = p->right = NULL;
    }
}
void swap(int x, int y){
    struct node *first=root, *second=root, *prevF, *prevS, *nextF, *nextS;
    int flag=0;
    if(x == y){
        printf("same student!");
        return;
    }
    while(first && first->std->id != x)
        first = first->right;
    while(second && second->std->id != y)
        second = second->right;

    if(!first || !second){
        printf("ID's not found!");
        return;
    }
    prevF = first->left;
    prevS = second->left;
    nextF = first->right;
    nextS = second->right;

    if(nextF->std->id==y || prevS->std->id==x)    flag =1;

    if(prevF!=NULL)   prevF->right = second;
    else root = second;

    prevS->right = first;
    first->right = nextS;

    if(flag == 0){
        second->right = nextF;
        second->left = prevF;
        nextF->left = second;
        first->left = prevS;
    }else{
        second->right = first;
        second->left = prevF;
        nextF->left = prevF;
        first->left = second;
    }
    if(first->right != NULL)    first->right->left = first;
}
void reverse(){
    struct node *tempR, *tempL=NULL, *p=root;
    while(p->right != NULL)
        p = p->right;
    tempR = p;
    p=root;

    while(p != NULL){
        tempL = p->right;
        p->right = p->left;
        p->left = tempL;

        p = p->left;
    }
    root = tempR;
}
void sort(){
    struct node *curr = root, *next;
    int temp;
    if(root == NULL){
        printf("List is empty!");
        return;
    }
    while(curr != NULL){
        next = curr->right;
        while(next != NULL){
            if(curr->std->id > next->std->id){
                temp = curr->std;
                curr->std = next->std;
                next->std = temp;
            }
            next = next->right;
        }
        curr = curr->right;
    }
}

int main()
{
    int choice, loc;
    printf("1: Append \n2: Add at begin \n3: Add After \n4: Delete \n5: Display \n6: Length \n7: Reverse \n8: Swap \n9: Sort \n0: Exit");
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
                    printf("Enter id: ");
                    scanf("%d",&loc);
                    delete(loc);
                    break;
                }
                case 5:{
                    display();
                    break;
                }
                case 6:{
                    printf("length: %d",length());
                    break;
                }
                case 7:{
                    reverse();
                    break;
                }
                case 8:{
                    int loc2;
                    printf("Enter id's: ");
                    scanf("%d %d",&loc, &loc2);
                    swap(loc, loc2);
                    break;
                }
                case 9:{
                    sort();
                    break;
                }
                case 0:{
                    break;
                }
                default:{
                    printf("wrong input!");
                    break;
                }
            }
    }while(choice != 0);
    return 0;
}
