#include <stdio.h>
#include <stdlib.h>

#define HASHTABLESIZE 20

struct Bucket {
   int key, value;
};
struct Node{
    int data;
    struct Node *left, *right;
};

struct Bucket* hashTableArray[HASHTABLESIZE];
struct Node *root = NULL;

int getHashCode(int key) {
   return key % HASHTABLESIZE;
}
struct Bucket *searchHashTable(int key) {
    int index = getHashCode(key);

    while(hashTableArray[index]) {
        if(hashTableArray[index]->key == key) return hashTableArray[index];
        index = index+1;
        index = index % HASHTABLESIZE;
    }

    return NULL;
}
void insertHashTable(int key, int value) {
    struct Bucket *temp = (struct Bucket*) malloc(sizeof(struct Bucket));
    temp->value = value;
    temp->key = key;

    int index = getHashCode(temp->key);
    while(hashTableArray[index] && hashTableArray[index]->key != -1) {
        index = index+1;
        index = index % HASHTABLESIZE;
    }

    hashTableArray[index] = temp;
}
struct Bucket* deleteHashTable(struct Bucket* p) {
   int index = getHashCode(p->key);

   while(hashTableArray[index]) {
      if(hashTableArray[index]->key == p->key) {
        struct Bucket* temp = hashTableArray[index];
        struct Bucket* after = (struct Bucket*) malloc(sizeof(struct Bucket));
        after->value = -1;
        after->key = -1;

        hashTableArray[index] = after;
        return temp;
      }

      index = index+1;
      index = index % HASHTABLESIZE;
   }

   return NULL;
}
void displayHashTable() {
   for(int i=0; i<HASHTABLESIZE; i++) {
      if(hashTableArray[i]) printf(" (%d,%d)",hashTableArray[i]->key,hashTableArray[i]->value);
      else printf(" ~~ ");
   }

   printf("\n");
}

struct Node* newNode(int data){
    struct Node *temp = (struct Node*) calloc(1, sizeof(struct Node));
    temp->data = data;

    return temp;
}
struct Node* insertBinaryTree(struct Node *curr, struct Node *parent, struct Node *ele){
    if(curr == NULL){
        if(ele->data > parent->data) parent->right = ele;
        else parent->left = ele;
        return NULL;
    }
    else if(ele->data > curr->data) return insertBinaryTree(curr->right, curr, ele);
    else return insertBinaryTree(curr->left, curr, ele);
}
struct Node* minValueNode(struct Node *Node) {
  struct Node *current = Node;
  while (current && current->left != NULL) current = current->left;
  return current;
}
struct Node* deleteBinaryTree(struct Node *root, int key){
    struct Node *temp;
    if (root == NULL) return root;

    if (key < root->data) root->left = deleteBinaryTree(root->left, key);
    else if (key > root->data) root->right = deleteBinaryTree(root->right, key);

    else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteBinaryTree(root->right, temp->data);
    }
    return temp;
}
void displayBinaryTree(struct Node *p){
    if(root == NULL){
        printf("Tree is empty!");
        return;
    }
    if(p->left) displayBinaryTree(p->left);
    printf("%d ",p->data);
    if(p->right) displayBinaryTree(p->right);
}
struct Node* searchBinaryTree(struct Node *curr, int ele){
    if(curr == NULL || curr->data == ele) return curr;
    else if(ele > curr->data) searchBinaryTree(curr->right, ele);
    else if(ele < curr->data) searchBinaryTree(curr->left, ele);
}

int main() {
   insertHashTable(1, 20);
   insertHashTable(2, 70);
   insertHashTable(42, 80);
   insertHashTable(4, 25);
   insertHashTable(12, 44);
   insertHashTable(14, 32);
   insertHashTable(17, 11);
   insertHashTable(13, 78);
   insertHashTable(37, 97);
   displayHashTable();

   struct Bucket* item = searchHashTable(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->value);
   } else {
      printf("Element not found\n");
   }

   deleteHashTable(item);
   item = searchHashTable(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->value);
   } else {
      printf("Element not found\n");
   }
}
