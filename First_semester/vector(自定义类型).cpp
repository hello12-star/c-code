#include<iostream>
#include<string.h> 
#include<vector>
using namespace std;
class Person{
	public:
		Person(string name,int age){
			this->m_name=name;
			this->m_age=age;
		}
	int m_age;
	string m_name;
};
int main(){
//	vector<Person>v;
//	Person p1("张三",25);
//	Person p2("张四",26);
//	Person p3("张五",27);	
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
//		//cout<<(*it).m_name<<"\t"<<(*it).m_age<<endl;//(*it)解引用出来的是一个Person类型 
//		cout<<it->m_name<<"\t"<<it->m_age<<endl; //it是一个指针，可以通过箭头的方式拿到信息 
//	}
	vector<Person*>v1;
	Person p1("张三",25);
	Person p2("张四",26);
	Person p3("张五",27);	
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	for(vector<Person*>::iterator it=v1.begin();it!=v1.end();it++){
		cout<<(*it)->m_age;//看<>里面放的是什么，*it解出来的就是什么类型，这里解出来的是Person类型的指针 
	}
	return 0;
}
