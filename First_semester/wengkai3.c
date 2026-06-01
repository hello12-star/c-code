#include<stdio.h>
int main() {
    int TIME;
	int time;
	int time1;
	printf("请输入一个四位数的时间\n");
	scanf("%d",&TIME);
	time = TIME/100;
	time1=TIME%100;
	printf("现在是%d点%d分\n",time,time1);
	int passtime;
	printf("请输入经过时间(分钟)\n");
	scanf("%d",&passtime);
	int TIME1,TIME12,TIME13;
	TIME1=time*60+time1+passtime;
	TIME12=TIME1/60;
	TIME13=TIME1%60;
	printf("现在是北京时间%d点%d分\n",TIME12,TIME13);
	
    return 0;
}
