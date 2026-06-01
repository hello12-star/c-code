#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<chrono>
using namespace std;
void merge(int arr[],int temparr[],int left,int mid,int right) {
	int l_pos=left;
	int r_pos=mid+1;
	int pos=left;//标记临时数组的首位数
	while(l_pos<=mid&&r_pos<=right) {
		if(arr[l_pos]<arr[r_pos]) {
			temparr[pos++]=arr[l_pos++];//小的先放在临时数组的前一个，大了的下次就放在比它更大的数的前面
		} else
			temparr[pos++]=arr[r_pos++];
	}
	while(l_pos<=mid) {
		temparr[pos++]=arr[l_pos++];//还剩有的元素直接合并到临时数组的后面即可
	}
	while(r_pos<=right) {			//这两个while只有可能会发生一个
		temparr[pos++]=arr[r_pos++];//不是左边多一个，就是右边多一个
	}
	for(int i=left; i<=right; i++) { //把临时数组里的数全部再放回原来的数组
		arr[i]=temparr[i];
	}
}
void msort(int arr[],int temparr[],int left,int right) { //划分区间
	if(left<right) {
		int mid=(left+right)/2;
		msort(arr,temparr,left,mid);//划分成一个个单独的个体
		msort(arr,temparr,mid+1,right);//同样的
		merge(arr,temparr,left,mid,right);//合并已经排序的部分
	}
}
//void merge_sort(int arr[],int n){
//	int *temparr=(int*)malloc(n*sizeof(int));//给辅助数组分配空间
//	if(temparr){
//		msort(arr,temparr,0,n-1);
//		cout<<"分配到空间了"<<endl;
//		free(temparr);
//	}
//	else
//	cout<<"没分配到空间！"<<endl;
//}
//不需要递归的代码 ：比用递归的代码功能实现要快0.07秒左右
void merge_sort(int arr[],int n) {
	int *temparr=(int*)malloc(n*sizeof(int));//给辅助数组分配空间
	if(temparr) {
		cout<<"分配空间成功！"<<endl;
		for(int size=1; size<n; size*=2) { //size表示当前要合并的数组大小1-2-4-8
			for(int left=0; left<n-size; left+=2*size) {
				int mid=left+size-1;
				int right=left+2*size-1;
				if(right>=n)
					right=n-1;
				merge(arr,temparr,left,mid,right);
			}
		}
		free(temparr);
	} else
		cout<<"没分配到空间！"<<endl;
}
int main() {
	ifstream ifs("data6.txt",ios::in);
	if(ifs.is_open())
		cout<<"打开成功！"<<endl;
	else {
		cout<<"打开失败！"<<endl;
		return 1;
	}
	vector<int>v;
	v.reserve(10000000); 
	int num;
	while(ifs>>num) {
		v.push_back(num);
	}
	ifs.close();
	int n=v.size();
	cout<<n;
	int *arr=v.data();
	auto start=chrono::high_resolution_clock::now();
	merge_sort(arr,n);
	auto end=chrono::high_resolution_clock::now();
	auto cost_time=chrono::duration_cast<chrono::milliseconds>(end-start);
	cout<<"归并排序消耗"<<cost_time.count()<<"毫秒"<<endl;
	if(v.empty()) {
		cout<<"容器是空的哦！"<<endl;
		return 0;
	}
//	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
//		cout<<*it<<" ";
//	}
//	for(int i=0;i<n;i++){
//		cout<<arr[i];
//	}
	return 0;
}
