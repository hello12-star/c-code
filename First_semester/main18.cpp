#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int i;
	int number;
	scanf("%d",&number);
	int * a;
	a=(int*)malloc(number*sizeof(int));
	for(i=0;i<number;i++)
	scanf("%d",&a[i]);
	for(i=number-1;i>=0;i--)
	cout<<a[i];
	free(a);
	return 0;
} 
