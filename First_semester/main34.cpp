#include<iostream>
using namespace std;
class Person{//class里面默认是私有 //如果用struct来定义类的话则默认为公有 
	public: 
	Person(){
		cout<<"普通构造函数被调用"<<endl; 
	}
	Person(int a){
		age=a; 
		cout<<"有参构造函数被调用"<<endl; 
	} 
	Person(const Person&p){//将Person这个类里面的东西拷贝过来；const的作用是保证在拷贝的时候不改变原类 
		cout<<"拷贝构造函数被调用"<<endl; 
		age=p.age; 
	}
	~Person(){
		cout<<"析构函数被调用"<<endl;
	} 
	int age;
};
int main(){
	//调用构造函数方法：
	//1：括号法 
	//Person p1;//调用普通的构造函数 //注意：调用普通构造函数时不用加括号 
	//Person p2(10); //调用有参构造函数 
	//Person p3(p2); //调用拷贝构造函数
	//cout<<"p2.age="<<p2.age <<endl;
	//cout<<"p3.age="<<p3.age <<endl;
	
	//2.显示法 
	//Person p4; 
	//Person p5=Person(10);//调用有参构造函数 
	//Person p6=Person(p5);//调用拷贝构造函数 
	
	//Person(11);//匿名对象：当前行执行结束后，系统会立即收回匿名对象 (即是析构立马紧跟有参构造函数出现 ) 
	//cout<<"11111"<<endl;
	
	//3.隐式转换法 
	Person p7=22;//调用有参构造函数 相当于Person p7=Person(10); 
	Person p8=p7;//调用拷贝构造函数 相当于Person p8=Person(p7);
	
	return 0;
}
