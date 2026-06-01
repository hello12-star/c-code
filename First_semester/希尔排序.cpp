#include<iostream>
#include<vector>
#include<fstream>
#include<chrono>
using namespace std;
void Hill_Sort(int arr[],int n){
	//int arr[5]={5,2,7,3,8};
	int i,j,inc,key;
	for(inc=n/2;inc>0;inc=inc/2){//增量递减 
		for(i=inc;i<n;i++){
			key=arr[i];
			for(j=i;j>=inc&&key<arr[j-inc];j=j-inc)
				arr[j]=arr[j-inc];
			arr[j]=key;
		}
	}
}
void print(int arr[],int n){
		for(int k=0;k<n;k++){
		cout<<arr[k]<<" ";
	}
}
int main(){
	ifstream ifs("data.txt",ios::in);
	if(ifs.is_open())
	cout<<"打开成功！"<<endl;
	else{
		cout<<"打开失败！"<<endl;
		return 1; 
	}
	int num;
	vector<int>v;
	while(ifs>>num){
		v.push_back(num); 
	}
	int n=v.size();
	int *arr=v.data();
	auto start=chrono::high_resolution_clock::now();
	Hill_Sort(arr,n);
	auto end=chrono::high_resolution_clock::now();
	auto cost_time=chrono::duration_cast<chrono::milliseconds>(end-start);
	//print(arr,n);
	cout<<"排序用时："<<cost_time.count()<<"毫秒";
	return 0;
}
