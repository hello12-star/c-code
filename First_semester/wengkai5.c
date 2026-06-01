#include<stdio.h>
int main(){
int n=0;
int x;
printf("请输入一个数。\n");
scanf("%d",&x);
//n++;
//x/=10;
while(x){//可以数负数 ，但是当前还不可以数“0”//这里的意思是while后面括号里面只要x大于0，这个循环即可运行 
	printf("hr1\n") ;//表示进行了几次 
	x/=10;
	n++;
	
}
printf("这是%d位数",n);
return 0;

//	cin>>"666";
	
	
}
