#include<iostream>
using namespace std;
class Person{//1.常函数，2.常对象 
	public://每一个函数内都有一个this指针. 
	//相当于（在前面加一个const表示this指针指向的值不可修改）（const）Person*const this
	//(Person*表示是Peron类中的一个指针,const表示this指针的指向不可修改) 
	Person(){
		
	}
	void func()const//在成员函数后加const,本质是修饰this指针，让指针指向的值不可修改 
	{
	//this->m_a=10;//还有就是this指向创建的对象p,在常函数内不可以修改变量的值 
	//this=NULL; //this指针的本质是指针常量，指针的指向不可修改
	m_b=11;
	}
	void func02(){
		cout<<"不可调用"; 
	} 
	int m_a;
	mutable int m_b;//想要在常函数里面修改，在前面加上mutable 
};
void test01()
{
	Person p;
	p.func();
}
void test02()
{
	const Person p;
	//p.m_a=10;//常对象不可以修改 
	p.m_b=11;
	p.func();//常对象只能调用常函数 
	//p.func02();//调用不了 
} 
int main()
{
	test01();
	
	
	
	return 0;
}
