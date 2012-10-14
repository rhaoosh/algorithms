#ifndef ALGORITHMS_UTILS_H
#define ALGORITHMS_UTILS_H

#include <stdio.h>
#include <stdbool.h>

static inline bool equal_array(int A[], int B[], int size){
	for(int i=0; i<size; i++){
		if(A[i] != B[i]){
			return false;
		}
	}
	
	return true;
}

static inline void print_array(int A[], int size){
	printf("Array:");
	
	for(int i=0; i<size-1; i++){		
		printf(" %d,",A[i]);
	}
	
	printf(" %d\n",A[size-1]); 	
	
}


#endif