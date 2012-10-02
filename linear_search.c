/*
LINEAR SEARCH
Chapter 2 - Ex 2.2.3
Introduction to Algorithms 3rd Edition

LINEAR-SEARCH(A,v)
	for i = 1 to A.length
		if A[i] == v
			return i
	return NIL

loop invariant:
At the start of each iteration of the for loop of lines 1–4, 
1 <= i <= j   where A[j] == v or j == A.length


*/

#include "utils.h"
#include <stdio.h>

//Returns the index of v, or -1 if not found
int linear_search(int A[], int size, int v){
	for (int j=0; j<size; j++){
		if(A[j] == v)
			return j;
	}
	return -1;
}



//TESTS
#ifndef HASMAIN

int main(){
	int size = 7;
	int A[]={1,4,2,5,6,3,6};
	int v = 2;
	int expected=2;
	
	int result = linear_search(A, size, v);
	
	
	if(expected != result){
		printf("Fail! expected != result => %d != %d.",expected, result);
		return 1;
	}
	
		
	printf("\nSuccess!\n");
	return 0;

}

#endif
