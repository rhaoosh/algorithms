
#include "utils.h"
/*
BIN-ADD

*/

void bin_add(int A[], int B[], int size, int out[]){
	if(size < 1){
		return;
	}
	
	int carry = 0;	 
	for(int i = size -1; i >= 0; i--){		
		out[i+1]= (A[i] ^ B[i]) ^ carry;
		//printf("A[%d]=%d, B[%d]=%d, out[%d] = %d\n",i,A[i],i,B[i], i+1,out[i+1]);
		carry = (A[i] + B[i] + carry) > 1;
	}
	
	out[0] = carry;
	
}

bool bin_add_test_helper(int A[],int B[],int size,int expected[]){
	int result[size+1];
	bin_add(A,B,size,result);
	print_array(A,3);
	printf(" + ");
	print_array(B,3);
	printf(" = ");				
	print_array(result,4);

	if(!equal_array(result, expected, size+1))
		return false;
		
	return true;	
}

bool test_bin_add1(){
	int A[] = {1,0,1};
	int B[] = {1,1,1};
	int expected[]={1,1,0,0};
	
	if(!bin_add_test_helper(A,B,3,expected)){
		printf("test_bin_add1: failed!");
		return false;
	}
	
	return true;
	

}

bool test_bin_add2(){
	int A[] = {1,1,1};
	int B[] = {1,1,1};
	int expected[]={1,1,1,0};
	
	if(!bin_add_test_helper(A,B,3,expected)){
		printf("test_bin_add1: failed!");
		return false;
	}
	
	return true;
	

}


#ifndef HASMAIN
int main() {

	test_bin_add1();	
	test_bin_add2();
}
#endif