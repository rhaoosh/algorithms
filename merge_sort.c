/*
MERGE-SORT
Introduction to Algorithms 3rd E.  p.31

MERGE(A,p,q,r)
	n1 = q-p+1
	n2 = r-q
	let L[1..n1+1] and R[1..n2+1] be new arrays
	
	for i = 1 to n1
		L[i] = A[p+i-1]
	for j = 1 to n2
		R[j] = A[q+j]
	
	//inf is a sentinal greater than all other numbers
	L[n1+1] = inf
	R[n2+1] = inf
	i=1
	j=1
	for k = p to r
		if L[i] <= R[j]
			A[k] = L[i]
			i = i + 1
		else
			A[k] = R[j]
			j = j+1


Running Time of MERGE: O(n)


MERGE-SORT(A,p,r)
	if p < r
		p = floor((p+r)/2))
		MERGE-SORT(A,p,q)
		MERGE-SORT(A,q+1,r)
		MERGE(A,p,q,r)
		
Running time of MERGE-SORT: O(n*lg(n))
*/

#include "utils.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

void merge(int A[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r -q;
	
	int L[n1+1];
	int R[n2+1];
	
	for(int i=0; i < n1; i++){
		L[i] = A[p+i];
	}
	
	for(int j=0; j < n2; j++){
		R[j] = A[q + j + 1];
	}

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
			
//	printf("L = ");
//	print_array(L, n1 + 1);
//	printf("R = ");
//	print_array(R, n2 + 1);
	
	int i = 0;
	int j = 0;
	
	for (int k = p; k <= r; k++){
		if(L[i] <= R[j]){
//			printf("L wins: %d\n",L[i]);
			A[k] = L[i];
			i = i + 1;
		}else{
//			printf("R wins: %d\n",R[j]);
			A[k] = R[j];
			j = j + 1;
		}
	}
	
	
}


void merge_sort(int A[], int p, int r){
	if (p < r){
		int q = floor((p+r)/2);
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}



//TESTS
#ifndef HASMAIN

int main(){

	int A[]={11,2,4,1,6,8,9,10,2,3,7,3,4};
	int result[]={11,2,4,1,2,3,6,7,8,9,10,3,4};
	
//	printf("Input A = ");
//	print_array(A,12);
	
	merge(A,3,7,10);
	
//	printf("Output A = ");
//	print_array(A,12);
	
//	printf("Expected = ");
//	print_array(result,12);

	if(!equal_array(A,result,12)){
		printf("Fail! A and result are not equal.");
		return 1;
	}
	

	int A2[]={1,4,2,5,6,3,6};
	int result2[]= {1,2,3,4,5,6,6};
	
	merge_sort(A2,0,6);
	print_array(A2,7);
	
	if(!equal_array(A2,result2,7)){
		printf("Fail! A and result are not equal.");
		return 1;
	}
	
	
	printf("\nSuccess!\n");
	return 0;

}

#endif
