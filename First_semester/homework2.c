#include<stdio.h>
int main(){
	/*printf("请输入数字\n");
	int a,b;
	scanf("%d %d",&a,&b);
	double c=(a+b)/2.0;
	printf("(a+b)/2.0=%lf",c);
	return 0;
*/
	int sum=0;
	int count=0;
	int number;
	scanf("%d",&number);
	while(number!=-1){
	count++;
	sum+=number;
	scanf("%d",&number)	;
	}
	printf("平均值是%f\n",1.0*sum/count*1);
	return 0;
}
