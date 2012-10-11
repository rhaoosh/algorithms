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
		
*/

#include "utils.h"
#include <stdio.h>
#include <math.h>

void merge(int A[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r -q;
	
	int L[n1] = malloc(n1*sizeof(int));
	int R[n2] = malloc(n2*sizeof(int));
	
	for(int i=0; i < n1; i++){
		L[i] = A[p+i-1]
	}
	
	for(int j=0; j < n2; j++){
		R[j] = A[q + j];
	}
	
	L[n1] = NULL;
	R[n2] = NULL;
	
	int i = 0;
	int j = 0;
	
	for (int k = p; k < p; k++){
		if(L[i] <= R[j]){
			A[k] = L[i]
			i = i + 1
		}else{
			j = j + 1
		}
	}
	
}


void merge_sort(int A[], int p, int r){
	if (p < r){
		q = Math.floor((p+r)/2);
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
	
	merge(A,3,7,10);

	if(!equal_array(A,result,7)){
		printf("Fail! A and result are not equal.");
		return 1;
	}
	

/*
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
	*/
	
	printf("\nSuccess!\n");
	return 0;

}

#endif
