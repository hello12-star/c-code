#include<stdio.h>
int main(){
/*	int x;
 	int pp;    
 	int ret=0;
 	scanf("%d",&x);
 	while(x>0){
		pp=x%10;
		ret=ret*10+pp;
		printf("%d %d %d \n",x,pp,ret);
		x=x/10;			
	 }
	 printf("%d",ret);
*/
/*	int x;
	int ret=1;
	int i=1;
	scanf("%d",&x);
	while(i<=x){
	ret =ret*i;	
	i++;	
	}
	printf("%d!=%d",x,ret);
	*/
	int x;
	int ret=1;
	printf("你想算几的阶乘\n");
	scanf("%d",&x) ;
	int i=1;
/*	for(;i<=x;i++){
	ret=ret*i;		
	}
	printf("%d!是%d",x,ret);  */
	for(;i<=x;x--){
	ret=ret*x;		
	}
	printf("%d",ret);
 	return 0;
 }
 
