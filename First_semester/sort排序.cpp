#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
int main(){
	vector<int>v1; 
	v1.push_back(61); 
	v1.push_back(11);
	v1.push_back(78);
	v1.push_back(129);
	v1.push_back(65);
	v1.push_back(52);
	//排序算法 ： 属于algorithm库中的函数 
	sort(v1.begin(),v1.end());//默认为升序排列 
	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	{
	cout<<*it<<" ";
	}	
	cout<<endl; 
	sort(v1.begin(),v1.end(),greater<int>());//增加一个参数greater<int>(),表示降序 
	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	{
	cout<<*it<<" ";
	}
	cout<<endl; 
	//打乱排序算法 ：
	srand((unsigned int)time(NULL)); //随机数种子：可以使得每次打乱的顺序都不同 
	random_shuffle(v1.begin(),v1.end());
	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	{
	cout<<*it<<" ";
	}
	cout<<endl;
	reverse(v1.begin(),v1.end());//反转排列顺序 
	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
		cout<<*it<<" ";
	}
	return 0;
}
