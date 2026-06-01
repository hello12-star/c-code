#include<iostream>
#include<vector>
#include<fstream>
#include<chrono>
using namespace std;
int Digit(int num){
	if (num == 0) return 1;
	int count=0;
	while(num!=0){//123
		num=num/10;
		count++;
	}
	return count;
}
void Base_Sort(int arr[],int n){
	//int b[10][10000];对于需要处理大量数据的时候，静态数组的先分配的栈内存往往会爆（若想看就找TestArrys.cpp文件） 
	vector<vector<int>> vm(10);
//	for (int j=0; j<10;j++) {
//        b[j][0]=0; // b[j][0]表示第j个桶的元素个数
//    }//由于不采用数组，则不用初始化 
	int max=0;
	for(int i=0;i<n;i++){
		if(arr[i]>max) max=arr[i];
	}
	int k=Digit(max);
	int num;
	int Y=1;
	for(int i=1;i<=k;i++){//将数组中的数拿出来放进桶中 
		for(int j=0;j<n;j++){
			num=arr[j]/Y%10;
			//b[num][++b[num][0]]=arr[j];
			vm[num].push_back(arr[j]);  
		}
		int a_len=0;
		for(int j=0;j<10;j++){
//			for(int m=1;m<=b[j][0];m++){
//			arr[a_len++]=b[j][m];
//			}
			for(int val:vm[j]){
				arr[a_len++]=val;
			}
			//b[j][0]=0;
			vm[j].clear();
		}
		Y*=10;
	}
}
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	ifstream ifs("data6.txt",ios::in);
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
	Base_Sort(arr,n);
	auto end=chrono::high_resolution_clock::now();
	auto cost_time=chrono::duration_cast<chrono::milliseconds>(end-start);
	//print(arr,n);
	cout<<"排序用时："<<cost_time.count()<<"毫秒";
	return 0;
} 



