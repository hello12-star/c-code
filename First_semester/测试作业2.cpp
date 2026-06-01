#include<iostream>
using namespace std;
class A{
	public:
		A(){
			cout<<"A类拷贝构造函数"<<endl;
		}
};
class Base{
	public:
	Base(){
		cout<<"Base默认构造函数"<<endl;
	}
};
class Son:public Base{
	public:
	A a;
	Son(){
		cout<<"Son默认构造函数"<<endl; 
	} //即便里面什么也没有，也会先调用父类的默认构造函数，后对象，最后自己 
};//即便有东西，也会调用父类的默认构造函数 
int main(){
	Son s; //只创建了子类的对象 
	
	
	return 0;
}
