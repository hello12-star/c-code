#include<iostream>
using namespace std;
class Person{//核心：成员变量和成员函数是分开存储的 
	int a;//非静态成员变量，属于类的对象上 
	int c;
	int z; 
	static int b;//这里static静态变量不属于类对象上（不会占用空间）
	//而且记得每次声明静态成员变量的时候要在类外定义 
	void func(){//非静态成员函数，不属于类对象上 
	}
	static void func1(){//非静态成员函数，也不属于类的对象上 
	} 
}; 
int Person::b=11;
void test1(){
	//核心：空类对象占多少字节 
	Person p;//即使空类对象，但是为了区分，编译器 
	Person p1; //还是分配1个字节的空间 
	cout<<sizeof(p)<<endl;
	cout<<sizeof(p1)<<endl; 
	printf("%p\n",&p);
	printf("%p\n",&p1);
}
void test2(){
	Person p;
	cout<<sizeof(p)<<endl;
} 

int main(){
	test1();
	
	return 0;
}
