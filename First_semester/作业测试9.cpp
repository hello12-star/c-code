#include<iostream>
using namespace std;
static int count;
class animal{
	public:
		animal(){}
		~animal(){}
		int voice;
		virtual void makesound(){
		}  
};
class cat:public animal{
	public:
		cat(){}
		~cat(){}
		void makesound(){
			cout<<"miaomiao"<<endl;
			count++;
		} 	 
};
class dog:public animal{
	public:
		dog(){}
		~dog(){}
		void makesound(){
			cout<<"wangwang"<<endl;
			count++;
		}
};
class duck:public animal{
	public:
		duck(){}
		~duck(){}
		void makesound(){
			cout<<"gaga"<<endl;
			count++; 
		}
};
int main(){
	cat c;
	dog g;
	duck d;
	animal *p; 
	p=&c;
	p->makesound();
	p=&g;
	p->makesound();
	p=&g;
	p->makesound();
	cout<<count<<endl;
	return 0;
} 
