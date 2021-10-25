#include <stdio.h>
#include <stdlib.h>

#define HASHTABLESIZE 20

struct Bucket {
   int key, value;
};

struct Bucket* hashTableArray[HASHTABLESIZE];

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
