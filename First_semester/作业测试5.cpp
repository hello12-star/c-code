#include<iostream>
using namespace std; 
int findmax(int (*A)[4]){//直接直观地写吧：int A[M][N] 
	int i;
	int j;
	int col;
	int max=0;
	for(j=0;j<4;j++){
		i=0;
		int ret=0;
		while(i!=3){
			ret=A[i][j]+ret;
			i++;
		}
		if(ret>max){
			max=ret;
			col=j; 
		}
	}
	return col;
}
int main(){
	int A[3][4];
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cin>>A[i][j];	
		}
	}
	int col=findmax(A);//直接去数组的首地址放进去，不用加规格大小 
	cout<<"该列是第"<<col+1<<"列"<<endl; 
	for(int i=0;i<3;i++){
		cout<<A[i][col]<<endl;
	}
	return 0;
}
