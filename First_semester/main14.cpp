#include<iostream>
using namespace std;
void swap(int *pa,int *pb);
int main(){
	int a=1;
	int b=2;
	swap(&a,&b);
	return 0;
	
}
void swap(int *pa,int *pb){
	int t;
	t=*pa;
	*pa=*pb;
	*pb=t;
	printf("a=%d\n",*pa);
	printf("b=%d\n",*pb);
}
