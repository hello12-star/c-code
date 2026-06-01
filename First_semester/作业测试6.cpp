#include<iostream>
using namespace std;
class Person{
	public:
		string name;
		char sex;
		Person(string v_name,char v_sex):name(v_name),sex(v_sex){
			
		}
	virtual void print(){
		cout<<name<<" "<<sex<<endl;
	}
};
class Student:public Person{
	public:
	string status;
	Student(string v_name,char v_sex,string v_status)://公有继承父类的子类是需要在构造函数里面写父类的构造函数的 
		Person(v_name,v_sex),status(v_status){
		}
	void print(){
		cout<<name<<" "<<((sex=='M')?"男":"女")<<" "<<status<<endl;
	}
};
class Faculty:public Person{
	private:
		string title;
	public:
		Faculty(string v_name,char v_sex,string v_title):
			Person(v_name,v_sex),title(v_title){
			}
	void print(){
		cout<<name<<" "<<((sex=='M')?"男":"女")<<" "<<title<<endl;
	}
	
};
int main(){
	Student s("张三",'M',"大一");
	Faculty f("杨静",'F',"教授");
//	s.print();
//	f.print();
	Person*p=&s;
	Person*q=&f;
	p->print();
	q->print(); 
	return 0;
} 
