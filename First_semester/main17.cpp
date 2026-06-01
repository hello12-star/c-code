#include<iostream>
using namespace std;
int main(){
//	char*s="hello world";
//	char*s2="hello world";
//	printf("%p\n",s);
//	printf("%p\n",s2);
	
	char a[]="hello world";
	a[0]='m';
	printf("a[0]=%c\n",a[0]);//%c是输出字符 
	printf("%p\n",&a[0]);
	printf("%p\n",a);
	printf("%p\n",a+1);
	cout<<a<<endl;
	printf("%d\n",sizeof(a));
	printf("%d\n",sizeof(a[0]));
	char b[]="helloluoliang";
	printf("%d\n",sizeof(b));//14个长度，因为还有末尾的‘\0’也算一个 
	b[4]='\0'; 
	printf("%s\n",b);//%s是输出到"\0"的时候停下 
}
