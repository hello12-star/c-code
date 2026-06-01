#include<iostream>
using namespace std;
class Person{
	public: 
	//1.传统初始化方式 
//	Person(int a,int b,int c){
//		m_a=a;
//		m_b=b;
//		m_c=c;
//	}
	//2.新型初始化方式 
	Person(int a,int b,int c):m_a(a),m_b(b),m_c(c){
		
		
	}
	int m_a;
	int m_b;
	int m_c;
	
};

int main(){
//	Person p(10,11,12);
	Person p1(10,11,12); 
	cout<<p1.m_a<<endl<<p1.m_b<<endl<<p1.m_c;
	return 0;
} 
