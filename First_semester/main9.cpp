#include<iostream>
using namespace std;
int main(){
	char a;
	scanf("%c",&a);//%C是指输入的是一个字符
	printf("a=%d\n",a);
	printf("a=%c\n",a);
	char b;
	b='2';
	printf("b=%d\n",b);
	printf("b=%c\n",b);
	char c='A';
	printf("c=%c\n",c);
	printf("A=%d\n",c);
	c=c+2;
	printf("c+2=%c\n",c);
	char i='Z'-'A'; 
	printf("i=%d\n",i);
	return 0;
	
	
	
}
