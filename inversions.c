/*
COUNT-INVERSIONS
Problem 2-4 d.  p.42
Introduction to Algorithms 3rd E.

Let A[1..n] be an array of n distinct numbers. 
If i < j and A[i] > A[j], then the pair (i,j) is called an inversion of A.

Running time of COUNT-INVERSIONS: O(n*lg(n))
*/

#include "utils.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int merge_inversions(int A[], int p, int q, int r){
	printf("starting merge_inversions p=%d, q=%d, r=%d\n",p,q,r);
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
			
	printf("L = ");
	print_array(L, n1 + 1);
	printf("R = ");
	print_array(R, n2 + 1);
	
	int i = 0;
	int j = 0;
	int inversions = 0;
	bool counted = false;
	
	for (int k = p; k <= r; k++){
		printf("k=%d, L[%d]=%d, R[%d]=%d, inversions = %d\n",k,i, L[i], j, R[j], inversions);
        if(counted == false && R[j] < L[i]){
            //If L[i] is > R[j], then L[i+1]...L[n1-1] is also > R[j] so we count the rest of
            //the elements in L as well.
            inversions += n1-i;
            counted = true;
            printf("counted! inversions = %d\n",inversions);
        } 
        
        if(L[i] <= R[j]){
            printf("L wins: %d\n",L[i]);
            A[k] = L[i];
            i = i + 1;
        }else{
            printf("R wins: %d\n",R[j]);
            A[k] = R[j];
            j = j + 1;
            counted = false;

        }

	}
	
	return inversions;
}


int count_inversions(int A[], int p, int r){
	printf("starting count_inversions p=%d, r=%d\n",p,r);
    int inversions = 0;
	if (p < r){
		int q = floor((p+r)/2);
		inversions += count_inversions(A,p,q);	
		inversions += count_inversions(A,q+1,r);
		inversions += merge_inversions(A,p,q,r);
	}
	
	return inversions;
}



//TESTS
#ifndef HASMAIN

bool test1(int A[], int size, int expected);

int main(){

	int A[]={2,3,8,6,1};	
	if(!test1(A,5,5)){
	    printf("test1 failed");
	    return 1;
	}
	
	printf("\nSuccess!\n");
	return 0;

}

bool test1(int A[], int size, int expected){
	printf("Input A = ");
	print_array(A,size);
	
	int result = count_inversions(A,0,size-1);
	
	if(result != expected){
		printf("Fail! result != expected, %d != %d\n",result, expected);
		return false;
	}
	return true;
}

#endif
