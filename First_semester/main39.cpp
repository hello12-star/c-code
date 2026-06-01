#include<iostream>
using namespace std;
class Person{
	public:
	Person  (){
	} 
	Person operator+ (Person&p){
		Person temp;
		temp.m_a =this->m_a +p.m_a;
		temp.m_b =this->m_b +p.m_b;
		return temp;
	}
	int m_a;
	int m_b;
};
//Person operator+(Person&p7,Person&p8){
//	Person temp;
//	temp.m_a =p7.m_a+p8.m_a;
//	temp.m_b =p7.m_b+p8.m_b;
//	return temp;
//}

int main(){
	Person p1;
	p1.m_a =11;
	p1.m_b =12;
	Person p2;
	p2.m_a =13;
	p2.m_b =14;
	Person p3=p1+p2;//相当于这个Person p3=p1.operator+(p2); 
	cout<<p3.m_a <<endl;
	cout<<p3.m_b <<endl;
	return 0;
} 
