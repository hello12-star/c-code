#include<iostream>
using namespace std;
class Person{
	public:
	static int m_a; //类内声明类外定义 ；还有就是所有对象共用一套数据 
	//静态成员变量不属于某一个对象上，所有对象共享一份数据 
	//静态成员变量也可以被私有化，在类外访问不到 
	private:
	static int m_b;
};
int Person::m_a;//不赋值默认为0 
int Person::m_b;//这个可以定义，但是不可以访问 
int main(){
	Person p;
	p.m_a =10;
	cout<<p.m_a<<endl;//两种访问方式：1，通过对象进行访问 
	Person p1;
	p1.m_a =11;
	cout<<Person::m_a<<endl;//2，通过类名进行访问 
	//cout<<Person::m_b<<endl;这个就是访问不到的例子 
	return 0;
}
