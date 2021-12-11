#include <stdio.h>
#include <stdlib.h>
struct node *root = NULL;
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(){
    struct node *temp = (struct node*) calloc(1, sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    return temp;
}
struct node* insert(struct node *curr, struct node *parent, struct node *ele){
    if(curr == NULL){
        if(ele->data > parent->data)      parent->right = ele;
        else                                               parent->left = ele;
        return;
    }
    else if(ele->data > curr->data)     return insert(curr->right, curr, ele);
    else                                                  return insert(curr->left, curr, ele);
}
struct node* minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}
struct node* deleteNode(struct node *root, int key){
    struct node *temp;
    if (root == NULL)                    return root;

    if (key < root->data)               root->left = deleteNode(root->left, key);           // finding node to be deleted
    else if (key > root->data)      root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {                                                                                        // If the node is with only one child or no child
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = minValueNode(root->right);                                                                    // If the node has two children
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return temp;
}
void display(struct node *p){
    if(root == NULL){
        printf("Tree is empty!");
        return;
    }
    if(p->left)     display(p->left);
    printf("%d ",p->data);
    if(p->right)    display(p->right);
}
struct node* search(struct node *curr, int ele){
    if(curr == NULL || curr->data == ele)       return curr;
    else if(ele > curr->data)                            search(curr->right, ele);
    else if(ele < curr->data)                            search(curr->left, ele);
}

int main()
{
    int choice=1, ele;
    printf("1: Insert \n2: Delete \n3: Display \n4: Search \n0: Exit");

    while(choice != 0){
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                if(root == NULL)    root = newNode();
                else                         insert(root, root, newNode());
                break;
            }
            case 2:{
                printf("Enter element: ");
                scanf("%d",&ele);
                deleteNode(root, ele);
                break;
            }
            case 3:{
                display(root);
                break;
            }
            case 4:{
                printf("Enter element: ");
                scanf("%d",&ele);
                struct node *temp = search(root, ele);
                if(temp)    printf("%d Found",temp->data);
                else          printf("Not found!");
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
    }
    return 0;
}
