#include<iostream>
using namespace std;
#include<fstream>
#include<string.h>
class Person{
	public:
	int age; 
	char buf[100];
};

int main(){
	ofstream ofs;
	ofs.open("Person.txt",ios::out|ios::binary);//以二进制的方式写进去 
	Person p;
	p.age =18;
	strcpy(p.buf,"罗亮"); //用strcpy给字符数组赋值 
	ofs.write((const char*)&p,sizeof(Person));//数据地址，长度 。真正二进制写入 
	ofs<<"18"<<endl; //这个<<是文本格式化输入，写进去并不会变成二进制乱码 
	ofs.close();
	return 0;
}
