/*
INSERTION SORT
Chapter 2 - Getting Started, p 18
Introduction to Algorithms 3rd Edition

INSERTION-SORT(A)
for j = 2 to A.length
	key = A[j]
	//Insert A[j] into the sorted sequence A[1..j-1].
	i = j -1
	while i>0 and A[i]>key
		A[i+1] = A[i]
		i=i-1
	A[i+1] = key



loop invariant:
At the start of each iteration of the for loop of lines 1–8, 
the subarray A[1..j-1] consists of the elements originally in A[1..j-1] 
but in sorted order.


Worst-case running time (sorted in reverse):
O(n^2)

Avg-case running time (1/2 of worst case):
O(n^2)

Best-case running time (sorted):
O(n)



*/

#include "utils.h"
#include <stdio.h>

void insertion_sort(int A[], int size){
	for (int j=1; j<size; j++){
		int key = A[j];
		int i = j -1;
		while(i>=0 && A[i]>key){
			A[i+1] = A[i];
			i=i-1;
		}
		A[i+1] = key;
	}
}

//Ex. 2.1.2  Non-increasing order
void insertion_sort2(int A[], int size){
	for (int j=1; j<size; j++){
		int key = A[j];
		int i = j -1;
		while(i>=0 && A[i]<key){
			A[i+1] = A[i];
			i=i-1;
		}
		A[i+1] = key;
	}	
}

//TESTS
#ifndef HASMAIN

int main(){
	int A[]={1,4,2,5,6,3,6};
	int result[]= {1,2,3,4,5,6,6};
	
	insertion_sort(A, 7);
	print_array(A,7);
	
	if(!equal_array(A,result,7)){
		printf("Fail! A and result are not equal.");
		return 1;
	}
	
	
	int A2[]={1,4,2,5,6,3,6};
	int result2[]= {6,6,5,4,3,2,1};
	
	insertion_sort2(A2, 7);
	print_array(A2,7);	
	
	if(!equal_array(A2,result2,7)){
		printf("Fail! A2 and result are not equal.");
		return 1;
	}
	
	printf("\nSuccess!\n");
	return 0;

}

#endif
