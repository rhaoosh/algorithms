/*
SELECTION-SORT
Ex. 2.2-2 Introdution to Algorithms 3rd Edition

SELECTION-SORT (A)

for j = 1 to n-1
	smallest = j
	for i=j+1 to n
		if A[i] < A[smallest]
			smallest = i
	
	A[j] = smallest
	


Loop invariant:
At start of outer loop iteration, A[1..j-1] consists of 
j-1 smallest elements of A[1..n] in sorted order.

Running time all cases:
O(n^2)

*/

#include "utils.h"
#include <stdio.h>

void selection_sort(int A[], int size){
	for (int j=0; j<size-1; j++){
		int smallest = j;
		for (int i=j+1; i<size; i++){
			if(A[i] < A[smallest])
				smallest = i;
		}
		int tmp = A[smallest];
		A[smallest] = A[j];
		A[j] = tmp;
	}
}


//TESTS
#ifndef HASMAIN

int main(){
	int A[]={6,4,2,5,6,3,2};
	int result[]= {2,2,3,4,5,6,6};
	
	selection_sort(A, 7);
	print_array(A,7);
	
	if(!equal_array(A,result,7)){
		printf("Fail! A and result are not equal.");
		return 1;
	}
	
	
	int A2[]={0,1,1,2,3,2,4};
	int result2[]= {0,1,1,2,2,3,4};
	
	selection_sort(A2, 7);
	print_array(A2,7);	
	
	if(!equal_array(A2,result2,7)){
		printf("Fail! A2 and result are not equal.");
		return 1;
	}
	
	printf("\nSuccess!\n");
	return 0;

}

#endif

