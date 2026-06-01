#include<iostream>
using namespace std;
struct Person{
	public:
	Person(){
		cout<<"默认构造函数"<<endl;
	}	
	Person(int height){
		m_height=new int(height);//在堆区创建一个int型的变量，然后将这个height的值赋值给这个新变量， 
		//最后返回这个新变量的地址 
		//等同于这样写：this->m_height =new int(height);//表示指向当前对象的指针 
		cout<<"有参构造函数"<<endl;
	}
	~Person(){
		delete m_height; 
		cout<<"析构函数"<<endl; 
	}
	
	int *m_height;
};
int main(){
	Person p(10);
	cout<<*p.m_height<<endl;
	return 0;
}
