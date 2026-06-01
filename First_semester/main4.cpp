#include"stdio.h"
int main(){
	int *a_ptr;//指针；起标志作用 
	int a=10;
	
	a_ptr=&a;
	
	*a_ptr=5;
	
	int arr[6]={1,2,3,4,5};//arr也是指针 
	//*arr=4;//等效于 arr[1]=4 ； 
	arr[2]=4;//等效于*（arr+1）=4； 
	printf("99"); 
}
