#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int x=0;

struct thread_data{
	int *num;
	int *nump;
	int thread_num;
};

void *threadFun(void *p){
	struct thread_data *data = (struct thread_data*) p; 
	printf("\n\nBEFORE increment: Thread number %d with TID of %lu, num = %d, nump = %d, x = %d", data->thread_num, pthread_self(), *data->num, *data->nump, x);
    
	x += 5;
    *data->num += 1;
	*data->nump += 1;
	
    printf("\nAFTER increment: Thread number %d with TID of %lu, num = %d, nump = %d, x = %d", data->thread_num, pthread_self(), *data->num, *data->nump, x);
	
	pthread_exit(NULL);
}


int main(int argc, char** argv) {
	if(argc == 1){
		printf("Error: Number of threads not specified !!");
		return -1;
	}
	
	int numThreads = atoi(argv[1]);
	
	if(numThreads < 1 || numThreads > 10){
		printf("Error: Number of threads are out of range !!");
		return -1;
	}

	numThreads += 1; 	// add 1 for proper indexing. 
	x = 10;
	int num = 50;
	int temp = 100;
	int *nump = &temp;
	int error;
	pthread_t thread_id[numThreads];
	struct thread_data data[numThreads];
	
	printf("Starting threads creation process with values, numThreads = %d, num = %d, nump = %d, x = %d", numThreads, num, *nump, x);
	
	for(int i=0; i<numThreads; i++){
		data[i].num = &num;
		data[i].nump = nump;
		data[i].thread_num = i;
		
		error = pthread_create(&thread_id[i], NULL, threadFun, &data[i]);
		
		if (error != 0){
			perror("Thread creation failed");
   			exit(error);
		}       
	}

   return 0;
}
