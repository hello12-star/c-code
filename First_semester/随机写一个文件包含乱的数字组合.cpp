#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime> 
using namespace std;
int main(){
	ofstream ofs;
	ofs.open("test1.txt",ios::out);
	vector<int>v1;
	v1.push_back(11);
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(15);
	srand((unsigned int)time(NULL));
	random_shuffle(v1.begin(),v1.end());
	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
		ofs<<*it<<" ";
	}
	ofs<<endl;
	sort(v1.begin(),v1.end());
	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
		ofs<<*it<<" ";
	}
	ofs.close();
	ifstream ifs;
	ifs.open("data.txt",ios::in);
	if(ifs.is_open())
	cout<<"打开成功！"<<endl;
	else{
		cout<<"打开失败！"<<endl;
		return 1;
	}
//	string buf;
//	while(getline(ifs,buf)){
//		cout<<buf<<endl;
//	} 
	vector<int>v2;
	int num;
	while(ifs>>num){
		v2.push_back(num);
	} 
	sort(v2.begin(),v2.end());
//	for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
//		cout<<*it<<" ";
//	}
	ifs.close();
	return 0;
} 
