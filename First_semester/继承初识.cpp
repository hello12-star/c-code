#include<iostream>
using namespace std;
class Base{//这个叫父类或者较基类 
	public:
		void func1(){
			cout<<"111"<<endl;
		}
		void func2(){
			cout<<"222"<<endl;
		}
	
};
class Lei:public Base
{//Lei叫子类或派生类 
	public:
		void funclei(){
			cout<<"lei"<<endl;
		}
};
int main(){
	Lei l;
	l.func1();//直接可以使用父类的函数 (继承来的共性)
	l.func2();
	l.funclei();//独有的个性 
	return 0;
}
