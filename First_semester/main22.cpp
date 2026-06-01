#include<iostream>
using namespace std;
int main(){
	int a[5];
	int i,j,t,n=5;
	for(i=0;i<=4;i++){
		cin>>a[i];
	}
	for(i=0;i<=4;i++){// 4 3 5 2 1//34521
		for(j=i+1;j<=4;j++){
		if(a[i]>a[j]){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
		}
	}
	for(i=0;i<=4;i++){
		cout<<a[i];
		
	}
	return 0;
}
