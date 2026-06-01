#include<iostream>
using namespace std;
class car{
	public:
	string name;
	protected:
	string name1; 
	private:
	string name2;
	public: 
	void show(string carname){
		cout<<carname;
	}
};
int main(){
	car car1;
	car1.name="奔驰";
	//car1.name1; //在保护区域不可以访问 
	car1.show(car1.name);
	
	return 0;
}
 
