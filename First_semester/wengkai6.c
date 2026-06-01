#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
int main(){
	srand(time(0));
	int a;
	a=rand()%100+1;//表示随机数 
	int number=0;
	int times=0;
	printf("我已经想好了一个1~100的数\n");
	printf("你来猜猜吧\n");
	do{
	scanf("%d",&number);
	times++;	
	if(number>a){
	printf("你的数大了\n");	
	}
	else if(a>number){
	printf("你猜的数小了\n");	
	}
	}while(a!=number);	
	
	printf("你用了%d次猜到了\n",times);
	
	return 0; 
}
	
	
	
	
	

