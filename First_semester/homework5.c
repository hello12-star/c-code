#include<stdio.h>
int main(){
	int i;
	int n;
	double sum=0;
	printf("请输入1到n分之1的n\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(i%2==1){
		sum=sum+1.0/i;}// 注意加上。0 
		else{
		sum=sum-1.0/i;
		}
	}
	printf("和是%.4lf",sum);//注意是%。 lf。而且是四舍五入 
/*	int main(){
	int n;
	int i;
	double ret;
	double sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	ret=1.0/i;
	sum+=ret;
	}
	printf("%.2lf",sum);
*/	
	return 0;
}
