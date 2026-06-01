#include<iostream>
using namespace std;
class Person{
	public:
		static void test(){
			//b=12; //错误；静态成员函数不能访问普通成员变量 
			cout<<a<<endl;
			cout<<123<<endl;
		}
	static int a;//类内声明 
	int b;
	
}; 
int Person::a=11;
//int Person::b=13; //普通成员变量不能在类外被定义 
int main(){
	Person p;
	p.test();
	return 0;
}
