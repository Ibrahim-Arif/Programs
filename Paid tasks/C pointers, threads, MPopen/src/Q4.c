#include <stdio.h>       
#include <stdlib.h>
#include <time.h>
#include <pthread.h>     

//This defines the number of threads that will be used for the problem
/** @todo adjust this ! */
// #define NUM_THREADS 2
// #define NUM_THREADS 4
// #define NUM_THREADS 8
#define NUM_THREADS 16


// @todo adjust this value to increase number of elements
// #define VALUE 1000
// #define VALUE 500000
#define VALUE 1000000

#define ARRAY_SIZE (NUM_THREADS * VALUE)
int length; 		//this is the length of the slice (ARRAY_SIZE/NUM_THREADS)

volatile int A[ARRAY_SIZE];
volatile int B[ARRAY_SIZE];
volatile int C[ARRAY_SIZE];

void* add_vector(void* data){
    int offset = *((int *)data);  //cast the data as an integer (offset into array)     
    
    for (int i = 0; i < length; i++){
        *(C + i + offset) = *(A + i + offset) + *(B + i + offset);
    }
	 
    pthread_exit(NULL);			// terminate the thread 
}

/* like any C program, program's execution begins in main */
int main(int argc, char* argv[]){
    int rc[NUM_THREADS];         	
    int start_pos[NUM_THREADS];

	/* @todo - assign random value to arrays! */
    for (int i = 0; i < ARRAY_SIZE; i ++){   	
	   	A[i] = rand();
	   	B[i] = rand();
    }
    
    pthread_t  t[NUM_THREADS];
    length = ARRAY_SIZE / NUM_THREADS;
    
    clock_t seconds[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++){
	    start_pos[i] = i * length; 
	    
		/* @todo - timing starts here! */	
		seconds[i] = clock();
		
	    rc[i] = pthread_create(&(t[i]), NULL, add_vector, (void *)&(start_pos[i])); 
	
		// could not create thread 
	    if(rc[i]){ 				
	       	printf("\nERROR: return code from pthread_create is %d \n", rc[i]);
		    exit(1);
	    }else{
			printf("\nCreated new thread (%d) ...",t[i]);	
		}
    }

    //now wait for the threads to end...
    for (int i = 0; i < NUM_THREADS; i++){
	    pthread_join(t[i], NULL);
    }
    printf("\nAll threads are done! \n	\n");
    
    /** @todo Timing stops here!*/
    for(int i=0; i<NUM_THREADS; i++){
    	seconds[i] = clock() - seconds[i];
    	printf("Execution time: %.2lf sec \n", ((double)seconds[i])/CLOCKS_PER_SEC);	
	}
    //check results
    char bad = 0;
    for (int i = 0; i < ARRAY_SIZE; i ++){
	    if (A[i] + B[i] != C[i]){
	    	printf("Error at %d\n",i);
		    bad |= 1;	
	    }
    }
    
    if (bad)
	    printf("Sums failed\n");
    else
	    printf("Sums all good!\n");
    
	exit(0);
}


// output with ==> NUM_THREADS = 2, VALUE = 10000000
// Created new thread (1) ...
// Created new thread (2) ...
// All threads are done!
//
// Execution time: 0.04 sec
// Execution time: 0.06 sec
// Sums all good!


// output with ==> NUM_THREADS = 4, VALUE = 500000
// Created new thread (1) ...
// Created new thread (2) ...
// Created new thread (3) ...
// Created new thread (4) ...
// All threads are done!
//
// Execution time: 0.02 sec
// Execution time: 0.02 sec
// Execution time: 0.02 sec
// Execution time: 0.00 sec
// Sums all good!


// output with ==> NUM_THREADS = 8, VALUE = 1000000
// Created new thread (1) ...
// Created new thread (2) ...
// Created new thread (3) ...
// Created new thread (4) ...
// Created new thread (5) ...
// Created new thread (6) ...
// Created new thread (7) ...
// Created new thread (8) ...
// All threads are done!
//
// Execution time: 0.02 sec
// Execution time: 0.01 sec
// Execution time: 0.01 sec
// Execution time: 0.01 sec
// Execution time: 0.01 sec
// Execution time: 0.01 sec
// Execution time: 0.01 sec
// Execution time: 0.01 sec
// Sums all good!

// output with ==> NUM_THREADS = 16, VALUE = 1000000
// Created new thread (1) ...
// Created new thread (2) ...
// Created new thread (3) ...
// Created new thread (4) ...
// Created new thread (5) ...
// Created new thread (6) ...
// Created new thread (7) ...
// Created new thread (8) ...
// Created new thread (9) ...
// Created new thread (10) ...
// Created new thread (11) ...
// Created new thread (12) ...
// Created new thread (13) ...
// Created new thread (14) ...
// Created new thread (15) ...
// Created new thread (16) ...
// All threads are done!
//
// Execution time: 0.03 sec
// Execution time: 0.03 sec
// Execution time: 0.03 sec
// Execution time: 0.03 sec
// Execution time: 0.03 sec
// Execution time: 0.03 sec
// Execution time: 0.03 sec
// Execution time: 0.03 sec
// Execution time: 0.02 sec
// Execution time: 0.02 sec
// Execution time: 0.02 sec
// Execution time: 0.02 sec
// Execution time: 0.02 sec
// Execution time: 0.02 sec
// Execution time: 0.02 sec
// Execution time: 0.02 sec
// Sums all good!
