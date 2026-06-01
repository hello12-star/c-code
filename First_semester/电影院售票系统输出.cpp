#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream ofs("电影院售票系统.txt",ios::out);
	ofs<<"666 罗亮你摊上大事了！"<<endl;
	ofs.close();
	return 0;
}
