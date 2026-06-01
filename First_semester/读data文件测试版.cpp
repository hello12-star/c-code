#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream ifs("data.txt",ios::in);
	if(ifs.is_open()){
		cout<<"打开成功！";
	}
	else{
		cout<<"打开失败！";
		return 1;
	} 
	string buf;
	while(getline (ifs,buf)){
		cout<<buf;
	}
	ifs.close(); 
	return 0;
}
