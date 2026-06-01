#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
int main(){
	ifstream ifs;
	ifs.open("text.txt",ios::in);
	if(ifs.is_open()){
		cout<<"文件打开成功！"<<endl;
	} 
	else{
		cout<<"文件打开失败！"<<endl;
		return 1; 
	}
	string buf;
	getline(ifs,buf);//只能读取一行的数据
	//cout<<buf<<endl; 
	vector<int>v;
	int num;
	while(ifs>>num){
		v.push_back(num); 
	}
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		cout<<*it<<" "; //如果存在上面的"getline(ifs,buf)",此时读取指针已经到这一行(注意只是这一行的末尾)的末尾，
	}                   //后续再执行ifs>>num时,会导致读取不到任何数据 
	ifs.close();
	return 0;
}
