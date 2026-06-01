#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
void m_swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
int partition(int arr[],int low,int high){
	int i=low;
	int pivot=arr[high];
	for(int j=low;j<high;j++){
		if(arr[j]<pivot){
			m_swap(arr[j],arr[i++]);
		}
	}
	m_swap(arr[high],arr[i]);
	return i;
}
void qsort(int arr[],int low,int high){
	if(low<high){
		int mid=partition(arr,low,high);
		qsort(arr,low,mid-1);
		qsort(arr,mid+1,high);
	}
}
int main(){
	ifstream ifs("data.txt",ios::in);
	if(ifs.is_open())
		cout<<"打开成功！"<<endl;
	else{
	cout<<"打开失败！";
	return 1; 
	}
	vector<int>v;
	v.reserve(10000000);
	int num;
	while(ifs>>num){
		v.push_back(num); 
	}
	ifs.close();
	int n=v.size();
	int *arr=v.data();
	qsort(arr,0,n-1);
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//	}
	return 0;
}
