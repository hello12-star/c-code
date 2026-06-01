#include"stdio.h"
#include<iostream>
using namespace std;
int main(){
	int a[5]; 
	int a2[5]= {1,2,4,2,5};
	float b[5]={1.1f,1.4f};
	int c = a2[0];//调试后c的值成为“0”所代表的a中第一号位数字“1” 
	a2[2]=666;//原本中括号"2"是表示第‘三’号位的"4"的，但是被替换成666了 
	char str[10]="123456789";//char中10个就是10个，能少不能多 
	printf("字符串str的值是%s",str);
	printf("%，\n");

	cout<<"age； "<<"18岁"<<"  姓名； "<<"罗亮"<<endl;
	
	int num1=1;
	int num2 =1;
	int num3=1;
	int num4=0;
	int jud1 =(num1==num2);//如果num1=num2，调试后jud为1，反之为0，同理可得“<,>,>=,<=,&&,//.” 
	int jud2 =(num3!=num4)&&(num1==num2);
	
	int range[10]={2,3,45,65,78,9,5};
	for (int i = 0;i < 10; i++){
		printf("第%d个元素为：%d\n",i,range[i]);//第一个%d对应i，第二个%d对应range里面的数字 
	}

	
	return 0; 
}
