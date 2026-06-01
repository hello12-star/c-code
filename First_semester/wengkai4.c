#include<stdio.h>
	int main(){
		printf("请输入两个时间。\n");
		int hour1,hour2,minute1,minute2;
		scanf("%d %d",&hour1,&minute1);
		scanf("%d %d",&hour2,&minute2);
		int ih=hour2-hour1;
		int im=minute2-minute1;
		if(ih<0){
			ih=hour1-hour2;
			im=ih*60-im;
			ih=ih-1;
	}
	
		printf("时间差是%d小时%d分钟\n",ih,im);
		printf("%d",5==4);//   false即为0 
		
		
	}
