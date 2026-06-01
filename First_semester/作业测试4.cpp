#include<iostream>
using namespace std;
struct infor{
	int bigletter;
	int smallletter;
	int num;
	int other;
};
int main (){
	infor count={0,0,0,0};//老版本不支持在定义的时候直接赋值 
	string input;
	getline(cin,input);
	int n=input.size();
	for(int i=0;i<n;i++){
		char c=input[i];//把字符串中的一个字符赋给c 
		if(c>='A'&&c<='Z'){//string里面的每一个字符就是char类型的
			count.bigletter++; 
		} 
		else if(c>='a'&&c<='z'){
			count.smallletter ++;
		} 
		else if(c>='0'&&c<='9'){
			count.num ++;
		}
		else{
			count.other++;
		}	
	}
	cout<<count.bigletter<<" "<<count.num<<" "<<count.other<<" "<<count.smallletter<<" "<<endl;
	return 0;
} 
