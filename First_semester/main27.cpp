#include<iostream>
using namespace std;
int main(){
	int a[5];
	int i,j;
	for(i=0;i<5;i++){
		cin>>a[i];
	}
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			int t;
		if(a[i]>a[j]){
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}		
	}
}
	for(i=0;i<5;i++)
	cout<<a[i]<<" ";
	return 0; 
}
