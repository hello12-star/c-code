#include<iostream>
#include<string.h>
using namespace std;
class information{
	//private:	
	public: 
	//char name[10];
	string name1; 
	int number;
	void show(){
		cout<<name1<<endl;
		cout<<number<<endl;
	}
	
};

int main(){
	information stu1;
	//stu1.name[1] ="luoliang";//错误，数组只能赋值一个字符如stu1.name[1]='a'; 
	//strcpy(stu1.name,"luoliang");
	stu1.name1 ="luoliang";
	stu1.number =123456;
	stu1.show() ;
	return 0;
}
