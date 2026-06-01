#include<iostream>
using namespace std;
struct hero{
	string m_name;
	string m_sex;
	int m_score;
	//string m_number;
};
void setinfo(struct hero arr[],int len){//c语言中要写struct,c++中可以省略不写 
	string name,sex;
	int score;
	cout<<"依次输入姓名，性别，分数"<<endl; 
	for(int i=0;i<len;i++){
		cin>>name>>score>>sex;
		arr[i].m_name=name;
		arr[i].m_sex=sex;
		arr[i].m_score=score;
	}
	for(int i=0;i<len;i++){
		for(int j=0;j<len-i-1;j++){//记住：冒泡排序两个for循环 
			if(arr[j].m_score>arr[j+1].m_score){
				hero temp=arr[j+1];//直接让一个数组等于另一个数组，信息交换 
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		} 
	}
	for(int i=0;i<len;i++){
		cout<<arr[i].m_name<<"\t"<<arr[i].m_score<<"\t"<<arr[i].m_sex<<endl;
	}
}

int main(){
	struct hero m_arr[3];//c语言中要写struct,c++中可以省略不写 
	int len=sizeof(m_arr)/sizeof(m_arr[0]);
	//int a=sizeof(m_arr);//发现一个小东西：在我的编译环境，int是4，所以按理来说一个m_arr数组的长度是20，
	//cout<<a;            但是通常编译器会按8字节对其(64位计算机)，所以20往上去到8的倍数24 
	setinfo(m_arr,len);
	return 0;
}
