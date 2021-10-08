/**
* Starter code for lab 2 - Q5
* @todo Please read the comments in the code to understand what needs to be done
* To compile on command line:  gcc Q5.c -o 5.exe -fopenmp
**/
#include <stdio.h>       
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
	int numThreads, tid;
	/* This creates a team of threads; each thread has own copy of variables  */
	#pragma omp parallel private(numThreads, tid)
	{
		tid = omp_get_thread_num();
		printf("Hello World from thread number %d\n", tid);

		/* The following is executed by the master thread only (tid=0) */
		if (tid == 0) {
			numThreads = omp_get_num_threads();
			printf("Number of threads is %d\n", numThreads);
		}
	}
	return 0;
}
