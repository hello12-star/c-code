#include<iostream>
using namespace std;
int main(){
	int arr[100][100];
	int m,n;
	cout<<"请输入矩阵的长宽"<<endl;
	cin>>m>>n; 
	cout<<"再输入矩阵元素"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	int m2=0;//记录行最大值的行数
	int n2=0;//记录行最大值的列数 
	int andian=0;//鞍点值 
	int count=0;//鞍点数 
	bool found=false;
	for(int i=0;i<m;i++){
		int max_m=arr[i][0];//解决负数兼容问题 
		for(int j=0;j<n;j++){//选行最大值 
			if(arr[i][j]>max_m){
				max_m=arr[i][j];
				//n2=j;//在这里直接赋值是只找出一个最大值下该列也满足的鞍点 
			}
		}
		for(int j=0;j<n;j++){
			if(arr[i][j]==max_m){
				n2=j;
				bool is_andian=true;
				for(int k=0;k<m;k++){
					if(arr[k][j]<max_m){
						is_andian=false;
						break;
					}
				}
			
			if(is_andian){
			m2=i;
			andian=max_m;
			found=true;
			count++;
			cout<<"这是第"<<count<<"个鞍点"<<endl;
			cout<<"鞍点行："<<m2+1<<endl;
			cout<<"鞍点列："<<n2+1<<endl;
			cout<<"鞍点值："<<andian<<endl;
			}
		}
		} 
	}
	cout<<"一共有"<<count<<"个鞍点"<<endl;
		if(!found){
			cout<<"没有鞍点！"<<endl; 
		}
	return 0;
}
