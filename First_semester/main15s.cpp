#include<iostream>
using namespace std;
int main(){
	char a[10]={0,1,2,3,4,5,6,7,8,9};
	char *p=a;
	printf("%d\n",*(p+1));//这里可以加括号也可以不加 
	printf("%p\n",p);
	printf("%p\n",p+1);
	int b[10]={0,1,2,3,4,5,6,7,8,9};
	int *q=b;
	int *q1=&b[0];//这个和*q=b是一样的 
	printf("%d\n",*q+3);
	printf("%p\n",q);
	printf("%p\n",q+1);
	
}
