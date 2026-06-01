#include<iostream>
using namespace std;
int main(){
	char arr[100]="123abc";//如果不定义数组长度的话，直接取宽度大小是7 
	int a=sizeof(arr);//因为还有末尾的'\0' 
	cout<<"666\n"<<a<<endl;
	return 0;
} 
