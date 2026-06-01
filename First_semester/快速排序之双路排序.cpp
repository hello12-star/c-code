#include<iostream>
#include<vector>
#include<fstream>//双路排序是针对于数据中存在大量相同元素的情况 
#include<chrono>
using namespace std;
void m_swap(int&a,int&b){//&不是取地址，这里表示的是引用 
	int temp=a;
	a=b;
	b=temp;
}
int partition_two(int arr[],int l,int r){//找中间值分界线 
	int pivot=arr[l];//基准
	int i=l+1; 
	int j=r;
	while(true){
		while(i<=r&&arr[i]<pivot){
			i++;
		}
		while(j>=l+1&&arr[j]>pivot){
			j--;
		}
		if(i>j){
			break;
		}
		m_swap(arr[j],arr[i]);
		i++;
		j--;
	}
	m_swap(arr[l],arr[j]);
	return j;
}
void quicksort_two(int arr[],int l,int r){
	if(l>=r){
		return ;
	}
	int pivot_pos=partition_two(arr,l,r);//获取基准最终位置 
	quicksort_two(arr,l,pivot_pos-1); 
	quicksort_two(arr,pivot_pos+1,r);
}
int main(){
	ifstream ifs("data6.txt",ios::in);
	if(ifs.is_open())
		cout<<"打开成功！"<<endl;
	else{
		cout<<"打开失败！"<<endl;
		return 1;
	}
	vector<int>v;
	int num;
	v.reserve(8000000); 
	while(ifs>>num){
		v.push_back(num); 
	}
	ifs.close();
	int *arr=v.data();
	int n=v.size();
	cout<<n<<endl;
	auto start=chrono::high_resolution_clock::now();
	quicksort_two(arr,0,n-1);
	auto end=chrono::high_resolution_clock::now();
	auto cost_time=chrono::duration_cast<chrono::milliseconds>(end-start); 
	cout<<"双路快排消耗"<<cost_time.count()<<"毫秒"<<endl;
//	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
//		cout<<*it<<" "; 
//	}

	return 0;
}
