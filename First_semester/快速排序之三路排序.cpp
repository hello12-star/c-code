#include<iostream>
#include<vector>
#include<fstream>
#include<chrono>
using namespace std;
void m_swap(int &a,int &b){//引用传参 
	int temp=a;
	a=b;
	b=temp; 
}
void quicksort_three(int arr[],int l,int r){
	if(l>=r){
		return ;
	}
	int pivot=arr[l];
	int lt=l;
	int i=l+1;
	int gt=r+1;
	while(i<gt){
		if(arr[i]<pivot){
			lt++;
			m_swap(arr[i],arr[lt]);
			i++;
		}
		else if(arr[i]==pivot){
			i++;
		}
		else{//arr[i]>pivot
			gt--;
			m_swap(arr[i],arr[gt]);	//后面的i不自增，因为还要对交换过来的值进行值大小的比较		
		}
	}
	m_swap(arr[l],arr[lt]);//lt是位于等于区间的开头，交换它 
	quicksort_three(arr,l,lt-1);
	quicksort_three(arr,gt,r);
}
int main(){
	ifstream ifs("data.txt",ios::in);
	if(ifs.is_open())
		cout<<"打开成功！"<<endl;
	else{
		cout<<"打开失败！"<<endl;
		return 1;
	}
	vector<int>v;
	v.reserve(8000000); 
	int num;
	while(ifs>>num){
		v.push_back(num); 
	}
	ifs.close();
	int n=v.size();
	int *arr=v.data();
	cout<<n<<endl;
	auto start =chrono::high_resolution_clock::now();
	quicksort_three(arr,0,n-1);
	auto end =chrono::high_resolution_clock::now();
	auto cost_time=chrono::duration_cast<chrono::milliseconds>(end-start);
	cout<<"三路快排消耗"<<cost_time.count()<<"毫秒"<<endl; 
//	for(int i=0;i<100;i++){
//		cout<<arr[i]<<" ";
//	}
	return 0;
}
