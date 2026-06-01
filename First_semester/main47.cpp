#include<iostream>
using namespace std;
class building; 
class goodgay{
	public:
		goodgay();
		void func();
	private:
		building*build;
};
class building{
	friend goodgay;
		public:
			building(){
				a=11;
				b=12;
			};
			int a;
		private:
			int b;
	
};
goodgay::goodgay(){
	build=new building;
}
void goodgay::func(){
	cout<<build->a<<endl;
	cout<<build->b<<endl;
} 
void test01(){
	goodgay gay;
	gay.func() ;
}
int main (){
	test01(); 
	
	
	return 0;
}
