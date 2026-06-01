#include<iostream>
using namespace std;
int main(){
	int angle;
	int n;
	cout<<"请输入一个角度：";
	cin>>angle;
	if(angle%90==0){
		if(angle%180==0){
			cout<<"线段在x轴上";
		} 
		else{
		cout<<"线段在y轴上";
		}
		} 
	else{ 
	n=angle/90+1;
	cout<<"线段在"<<n<<"象限";		
		}	
	return 0;
}
