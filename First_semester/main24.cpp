#include<iostream>
using namespace std;
int findmax(int *array,int cnt){//用法：地址传递 
	int i;
	int max=array[0];
	for(i=0;i<cnt;i++){
		if (array[i]>max){
		max=array[i];	
		}
	}//这个时候如果在子函数里面改变值，则改变的值也会在主函数中体现
	//如：在子函数里面令array[1]=66，则在主函数里面输出a[1]的值的时候，不是2，是66 
	//这里表示地址传递，子函数和主函数之间直接可以沟通，子函数直接调用主函数里面的值
	//这个时候为了防止学渣更改学霸的作业，可以在子函数findmax里面加const，变成了findmax(const int*array,int cnt) 
	//这里的const表示静态变量， 表示array只能被读不能被改写 
	return max;
}
int main(void){
	int a[]={1,2,3,4,5,6};
	int max;
	max=findmax(a,6);
	cout<<max;
	return 0;
} 
