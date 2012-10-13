/*
BINARY SEARCH
Ex. 2.3-5, p 39
Introduction to Algorithms 3rd Edition

BIN-SEARCH-ITERATIVE(A,v,low,high)
    while low <= high
        mid = floor((low + high)/2)
        if v == A[mid]
            then return mid
        if v > A[mid]
            low = mid + 1
        else
            high = mid - 1
    
    return NIL

BIN-SEARCH-RECURSIVE(A,v,low,high)
    if low > high
        return NIL

    mid = floor((low+high)/2)
    if v = A[mid]
        return mid
     
    if v > A[mid] 
        return BIN-SEARCH-RECURSIVE(A,v,mid+1,high)
    else
        return BIN-SEARCH-RECURSIVE(A,v,low,mid-1)


Worst-case running time O(lg(n))
*/

#include "bin_search.h"
#include "utils.h"
#include <stdio.h>
#include <math.h>

int bin_search_iter(int A[], int v, int low, int high)
{
    while (low <= high){
        int mid = floor((low+high)/2);
        if(v==A[mid]){
            return mid;
        }
        if(v > A[mid]){
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }
    
    return -1;
}

int bin_search_recursive(int A[], int v, int low, int high)
{
    if(low > high)
        return -1;
        
    int mid = floor((low+high)/2);
    if(v==A[mid]){
        return mid;
    }
    
    if(v > A[mid])
        return bin_search_recursive(A, v, mid+1, high);
    else
        return bin_search_recursive(A,v,low,mid-1);
    
}

//TESTS
#ifndef HASMAIN

int main(){
	int A[]={1,3,5,6,7,9,10};
	int v = 6;
	int expected = 3;
	
	int result = bin_search_iter(A, v, 0, 6);
	
	if(result != expected){
		printf("bin_search_iter Fail! result != expected; %d != %d", result, expected);
		return 1;
	}
	
	result = bin_search_recursive(A, v, 0, 6);
	
	if(result != expected){
		printf("bin_search_recursive Fail! result != expected; %d != %d", result, expected);
		return 1;
	}	
	
	printf("\nSuccess!\n");
	return 0;

}

#endif