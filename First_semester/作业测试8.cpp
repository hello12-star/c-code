#include<iostream>
using namespace std;
int main(){
	int arr[8]={675,567,580,633,580,675,580,575};
	int v_arr[8];
	for(int i=0;i<8;i++){
		v_arr[i]=arr[i];//复制数组是一个接一个的复制 
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8-i-1;j++){//注意j要小于n-i-1 （冒泡排序） 
			if(v_arr[j]<v_arr[j+1]){
				int temp=v_arr[j];
				v_arr[j]=v_arr[j+1];
				v_arr[j+1]=temp;
			} 
		}
	}
//	for(int i=0;i<8;i++){
//		cout<<v_arr[i]<<" ";
//	}675 675 633 580 580 580 575 567
	int same=0; 
	int sum=0; 
	for(int i=0;i<8;i++){
		int x=arr[i];
		int rank=1;
		for(int j=0;j<8;j++){
			int y=v_arr[j];
			if(y>x){
				rank++;
			}else{
				break;
			}
		} 
		cout<<rank<<" ";
	} 
	return 0;
}
