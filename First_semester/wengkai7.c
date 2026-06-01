#include<stdio.h>
/*int main(){
	int i,j,n;
	printf("请输入几几乘法表\n");
	scanf("%d",&n);
	i=1;
	while(j<=n){
		j=1;
		while(j<=i){
			printf("%d*%d=%d",j,i,i*j);
			j++;
			if(i*j<10)
			printf("    ");
			else 
			printf("   ");
		}
		
		printf("\n");
		i++;
	}
	
	
	return 0;
} */
int main(){
//	int M,N;
//	scanf("%d %d",&M,&N);//5  60
//	int i=M;
//	int n;
//	int count=0;
//	if(1<=M&&M<=N&&N<=500){	
//	while(i<=N){
//		n=2;
//		while(n<=i){
//		if(i%n==0){
//		printf("不是素数");
//		break;}
//		n++;}	
//		count++;
//		i++;
//			}	
//	}
//	return 0;}           //这个是错误的 
//	printf("%d",count);
	int m,n;
	int i;
	int cnt=0,sum=0;
	scanf("%d %d",&m,&n);
	for(i=m;i<n;i++){
	int isprime=1;
	int k;
	for(k=2;k<i-1;k++){
		if(i%k==0){
		isprime=0;
		break;
		}
	}	
	if(isprime){
		printf("%d\t",i);
		cnt++;
		sum+=i;
	}		
}
printf("%d个 和是%d",cnt,sum);
return 0;	
}



