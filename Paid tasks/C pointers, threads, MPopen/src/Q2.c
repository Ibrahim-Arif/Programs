#include <stdio.h> 
#include <stdlib.h>
#include <time.h>	//used for timing - see last lab.

/**
* Your function must use this function prototype (the signature must 
* be the same.
**/
int* addVec2(int* A, int* B, int size);

int* addVec2(int* A, int* B, int size){
	int *C = (int *) malloc(size * sizeof(int));	
	
	if(C == NULL){
		return NULL;
	}
	
	int i;
	for(i=0; i<size; i++){
		*(C + i) = *(A + i) + *(B + i);
	}
	
	return C;
}



int main(void){
	int size = 50000000;
	
	int *A = (int *) calloc(size, sizeof(int));
	int *B = (int *) calloc(size, sizeof(int));
	
	if(A == NULL || B == NULL){
		printf("Not enough memory.");
		exit(1);
	}
	
	clock_t seconds = clock();
	int *C = addVec2(A, B, size);
	seconds = clock() - seconds;
	
	if(C == NULL){
		printf("Not enough memory.");
		exit(1);
	}
	
	int i;
	for(i=0; i<10; i++){
		printf("%d ", C[i]);
	}
	
	printf("\nExecution time: %.2lf sec", ((double)seconds)/CLOCKS_PER_SEC);
}


// OUTPUT REPOST-1
// 0 0 0 0 0 0 0 0 0 0
// Execution time: 0.25 sec

// OUTPUT REPOST-2
// 0 0 0 0 0 0 0 0 0 0
// Execution time: 0.24 sec

