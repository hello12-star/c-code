#include<iostream>
using namespace std;
//全局变量 
int g_a=10; 
int g_b=11;
const int c_g_a=10;
const int c_g_b=11;
int main(){
	//在main函数下的局部变量： 
	int a=10;
	int b=11;
	cout<<"局部变量a的地址："<<&a<<endl;
	cout<<"局部变量b的地址："<<&b<<endl;
	cout<<"全局变量a的地址："<<&g_a<<endl;
	cout<<"全局变量b的地址："<<&g_b<<endl;
	//静态变量 
	static int s_a=10;
	static int s_b=11;
	cout<<"静态变量a的地址："<<&s_a<<endl;
	cout<<"静态变量b的地址："<<&s_b<<endl;
	//常量
	//1、字符串常量 
	cout<<"字符串常量地址："<<&"hello world!"<<endl ;
	//2、const修饰的全局变量
	cout<<"const修饰的全局变量的地址："<<&c_g_a<<endl;
	cout<<"const修饰的全局变量的地址："<<&c_g_b<<endl;
	//const修饰的局部变量 
	const int c_l_a=10;
	const int c_l_b=11; 
	cout<<"const修饰的局部变量的地址："<<&c_l_a<<endl;
	cout<<"const修饰的局部变量的地址："<<&c_l_b<<endl;
	//总结：
	//在全局区中：全局变量、静态变量、常量、字符串常量、const修饰的全局变量 
	//不在全局区：局部变量、const修饰的局部变量 
	return 0;
} 
