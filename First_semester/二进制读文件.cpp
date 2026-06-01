#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class Person{
	public: 
	int age;
	char buf[100];
};
int main(){
	ifstream ifs;
	ifs.open("Person.txt",ios::in|ios::binary);
	if(!ifs.is_open()){
		cout<<"文件打开失败！"<<endl;
		return -1;//采用return非零的数表示程序异常退出 
	}
	else{
		cout<<"文件打开成功！"<<endl; 
	}
	Person p;
	ifs.read((char*)&p,sizeof(Person)) ;//强转成char*的数据类型 
	cout<<p.age <<endl;
	cout<<p.buf <<endl;
	ifs.close();
	return 0;
}
