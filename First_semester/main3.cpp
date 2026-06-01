#include<iostream>
using namespace std;
int main(){
	int *a_ptr;//指针；起标志作用 
	int a=10;
	
	a_ptr=&a;
	
	*a_ptr=5;
	cout<<a<<endl;
	int arr[6]={1,2,3,4,5};//arr也是指针 
	//*arr=4;//等效于 arr[1]=4 ； 
	arr[2]=4;//等效于*（arr+1）=4； 
}
	
/*	int add (int a,int b);
	
	int main(){
	
		
		int res =add(5,7);
		printf("5+7的结果为%d",res);
		
		return 0;		
}
	int add(int a,int b){
		int res=a+b;
		
		return res;
	}
	*/

