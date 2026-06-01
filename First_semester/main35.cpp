#include<iostream>
using namespace std;
class Prom{
	public:
//	Prom(){
//		cout<<"默认构造函数"<<endl;
//	}
	Prom(int a){
		age=a;
		cout<<"有参构造函数"<<endl;
	}//还有就是如果只写了这个有参构造函数，那么系统则不会再提供默认构造函数，但还会再提供拷贝构造函数  
	Prom(const Prom&p){
		age=p.age;
		cout<<"拷贝构造函数"<<endl;
	}//这个拷贝拷贝构造不用写其实都可以，在写了有参函数前提之下系统会自动生成 
	//还有就是如果只写了拷贝构造函数，那么系统则不会再提供默认构造函数有参构造函数 
	~Prom(){
		cout<<"析构函数"<<endl; 
	}
	
	int age;
};
int main(){
	Prom p(66);
	Prom p1(p);
	cout<<"p1:"<<p1.age<<endl;
	
	return 0;
}
