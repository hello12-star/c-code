#include<iostream>
#include<fstream>
#include<vector>
#include<chrono>
using namespace std;
void Bubble_Sort(int arr[],int n){
	int left=0,right=n-1,lastswap1;
    while(left<right){
        int flag=0;
        for(int j=left;j<right;j++){//正向找最大值
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
                lastswap1=j;
            }
        }
        if(!flag) break;
        right=lastswap1;
        for(int j=right;j>left;j--){//反向找最小值
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                flag=1;
                lastswap1=j;
            }
        }
        if(!flag) break;
        left=lastswap1;
    }
}
void print(int arr[],int n){
		for(int k=0;k<n;k++){
		cout<<arr[k]<<" ";
	}
}
int main(){
    ifstream ifs("data4.txt",ios::in);
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
	Bubble_Sort(arr,n);
	auto end=chrono::high_resolution_clock::now();
	auto cost_time=chrono::duration_cast<chrono::microseconds>(end-start);
	print(arr,300);
	cout<<"冒泡排序用时："<<cost_time.count()<<"微秒";

    return 0;
}
