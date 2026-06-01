#include<iostream>
using namespace std;
void fun(int x){//用法：值传递 
	x=0x77;
	printf("%d\n",x);
	printf("%x\n",x);//%x表示是输出16进制 
}
int main (){
	 
	int a=0x66;
	fun(a);
	printf("%x\n",a); //主函数中的a没有改变；但是在子函数中对a重新进行赋值，
	//主函数传进去的值发生改变，然后子函数就用改变了的值 
}
