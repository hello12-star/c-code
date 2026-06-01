#include<iostream>
int sum(int a,int b){
	int ret=0;
	for(;a<=b;a++){
		ret=ret+a;
	}
	return ret;
	
} 
int main(){
	sum(10,20);
	printf("%d\n",sum(10,20));
	sum(11,66);
	printf("%d\n",sum(11,66));
	sum(1,6);
	printf("%d\n",sum(1,6));//可见这里用int的返回值类型有点麻烦 
	return 0;
}

//void sum(int a,int b); //这里的a与b可以省掉，因为这只是一个声明，告诉编译器有这么一个函数 ，同时也可以写其他的（a与b写成c与d），因为这里只是读类型 
//int main(){
//	sum(10,20);
//	sum(11,66);
//	sum(1,6);
//	return 0;
//}
//void sum(int a,int b){
//	int ret=0;
//	for(;a<=b;a++){
//		ret=ret+a;
//	}
//	printf("%d\n",ret);//这个是用void的形式 
//	
//} 
