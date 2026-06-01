#include<iostream>
using namespace std;
class Person{
	public:
	Person(int age){
		this->age=age;//this指针指向 被调用的成员函数 所属的对象 
	}
	Person& add(Person &p){//引用方式返回(add的返回值是Person&(对象的引用)).
	//不同于Person add(){}(这个是值返回),自然结果也不同 
		this->age=this->age+p.age;
		cout<<this->age<<endl;
		return *this;//返回当前调用这个函数的对象本身(的引用) 
	} 
	int age;
};
void test1(){
	Person p(11);
	cout<<p.age<<endl; 
}
void test2(){
	Person p1(11);
	Person p2(12);
	p2.add(p1).add(p1).add(p1).add(p1);//链式编程思想(一直返回给p2) 
	cout<<p2.age<<endl;
} 
int main(){
	test2();
	return 0;
} 
