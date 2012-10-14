/*
INSERTION SORT
Problem 2-2 p.40
Introduction to Algorithms 3rd Edition

BUBBLE-SORT(A)
    for i = 1 to A.length - 1
        for j = A.length downto i + 1
            if A[j] < A[j-1]
                exchange A[j] with A[j-1]

*/

#include "utils.h"
#include <stdio.h>

void bubble_sort(int A[], int size){
	for (int i=0; i<size-1; i++){
        for (int j=size-1; j > i; j--){
            printf("i=%d, j=%d, A[j]=%d, A[j-1]=%d",i,j,A[j],A[j-1]);
            if (A[j] < A[j-1]){
                printf(" swapped");
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
            }
            printf("\n");
        }
	}
}

//TESTS
#ifndef HASMAIN

int main(){
	int A[]={6,4,2,5,6,3,2};
	int result[]= {2,2,3,4,5,6,6};
	
	print_array(A,7);
	bubble_sort(A,7);
	print_array(A,7);
	
	if(!equal_array(A,result,7)){
		printf("Fail! A and result are not equal.");
		return 1;
	}
	
	printf("\nSuccess!\n");
	return 0;

}

#endif
