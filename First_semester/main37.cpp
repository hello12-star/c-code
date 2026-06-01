#include<iostream>
#include<string.h>
using namespace std;
class Phone{
	public:
	Phone(string name){
		my_phonename=name;
		cout<<"phone构造函数"<<endl;
	}
	~Phone(){
		cout<<"phone析构函数"<<endl; 
	} 
	string my_phonename;
};
class Person{
	public:
	Person(string name,string pname):m_name(name),m_pname(pname)
	{
		cout<<"Person构造函数"<<endl; 
	}	
	~Person(){
		cout<<"Person析构函数"<<endl;
	}
	string m_name;
	Phone m_pname;//这个是其他类的成员，在这个类里面叫做对象成员 
}; 
//调用构造函数的顺序是先调用对象成员的构造函数再调用本类的构造函数
//析构时则是相反的 
int main(){
//	Phone a("666");
//	cout<<a.my_phonename<<endl;
	Person b("罗亮","一加ace5");
	cout<<b.m_name<<endl; 
	cout<<b.m_pname.my_phonename <<endl;
	return 0;
}
