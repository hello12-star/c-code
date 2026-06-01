#include<iostream>
using namespace std;
class circle{
	private:
		double pi=3.14;
	public:
		int banjing;
	double c(){
		return 2*pi*banjing;
	}
	
};

int main(){
	circle yuan;
	yuan.banjing =2;	
	cout<<yuan.c() ;
	return 0;
}
