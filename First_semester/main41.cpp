#include<iostream>
using namespace std;
class subject{
	public:
	subject(){
		cout<<"默认构造函数";
	}
	void show1(){
		cout<<"123"<<endl;
	} 
	void show2(){
		if(this==NULL){//this表示判断当前调用这个函数的这个指针 
			return ;
		} 
		cout<<"132"; 
	}
	int length;
	int width;
};
int main(){
	subject *s=NULL;	 
	s->show1() ;
	s->show2() ;
	return 0;
}
