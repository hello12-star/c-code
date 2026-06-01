#include<iostream>
#include<vector>
using namespace std;
struct Students{
	string name;
	int score;
};
void print(vector<Students>&s){//冒泡排序记住了啊，两个for循环 
	int n=s.size(); 
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){//内层循环是外层循环的 
			if(s[j].score<s[j+1].score){
				Students temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp; 
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<s[i].name<<" "<<s[i].score<<endl;
	}
}
int main(){
	Students s[30];
	cout<<"输入所有学生姓名和成绩："<<endl;
	for(int i=0;i<3;i++){
		cin>>s[i].name>>s[i].score;	
	}
	vector<Students> v;
	for(int i=0;i<3;i++){
		if(s[i].score<60){
		v.push_back(s[i]);
		}
	}
	print(v); 
	return 0;
}
