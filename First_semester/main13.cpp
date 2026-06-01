#include<iostream>
using namespace std;
int main(){
	int a[10]={12,15,4,55,4,2,3,35,};
	int i;
	int o;
	//scanf("%d",&a[i]);
	printf("%p\n",&i);
	printf("%p\n",&o);
	printf("%p\n",&a[0]);
	printf("%p\n",&a[1]);
	printf("%p\n",&a[9]);
	printf("%p\n",&a);
	int *p=a;
	printf("p=%p\n",p);
	printf("*p=%d\n",*p);
	printf("*p=%d\n",*(p+1));//首地址取出来的数就是12 
}
