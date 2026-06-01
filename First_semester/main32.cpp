#include<iostream>
using namespace std;
class object{
	private:	
		int m_L;
		int m_W;
		int m_H;
	public:
		void set_(int Length,int Width,int Height){
			m_L=Length;
			m_W=Width;
			m_H=Height;
		}
		int get_L(){
			return m_L;
		}
		int get_W(){
			return m_W;
		}
		int get_H(){
			return m_H;
		}
		int calculateS(){
			return 2*m_L*m_W+2*m_L*m_H+2*m_W+2*m_H;
		}
		int calculateV(){
			return m_L*m_W*m_H;
		}
		bool Is_same(object&object3){//object3只是一个形式参数，它代替object2来执行调用函数 
			if(m_L==object3.get_L() &&m_W==object3.get_W()&&m_H==object3.get_H()){
			return 1;
		}
		return 0;
		}
};
//采用全局函数来判断是否相等 
bool Is_same(object &object1,object &object2){
	if(object1.calculateS()==object2.calculateS()){
		return 1;
	}
	
	return 0;
}

int main(){
	object object1;
	object object2;
	object1.set_(3,4,5); 
	object2.set_(6,2,5); 
	int ret=Is_same(object1,object2);
	if(ret)
	cout<<"相等(全局函数内判断)"<<endl;
	else 
	cout<<"不相等(全局函数内判断)"<<endl ;
	int ret1=object1.Is_same (object2);
	if(ret1)
	cout<<"相等(成员函数内判断)"<<endl;
	else 
	cout<<"不相等(成员函数内判断)" <<endl;
	cout<<object1.calculateS()<<endl ;
	cout<<object1.calculateV()<<endl ;
	cout<<object2.calculateS()<<endl ;
	cout<<object2.calculateV()<<endl ;
	return 0;
} 
