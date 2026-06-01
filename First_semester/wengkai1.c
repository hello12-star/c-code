#include<stdio.h>
/*int main(){
	printf("hello,world\n\n\n\n");
	printf("34/14=%d\n",34/14);//"/"是除的意思，结果取商 ，“%”则取余 
	int lx=6.4,ll=5.256;
	printf("lx+ll的值为%d\n",lx+ll);//"%d只能代替整数，有余数则直接舍去"
		return 0;
}*/
int main(){
const int AMOUNT=100;//(const使得AMOUNT为固定不变的值，不能再被修改了，而且后面的AMOUNT一般要大写)
int price=0;
printf("请输入价格:    ");
scanf("%d",&price);
printf("请输入票面:    ");
scanf("%d",&AMOUNT);
//scanf("%d" "%d",&price,&AMOUNT);//将两个整合的情况 （两个%d中间要用空格 
//printf("请输入票面");
//scanf("%d",&AMOUNT) ;
int change=AMOUNT-price;
if(change<0){
	printf("您的现金不足，出口在那一边\n");}
	else{
	
	printf("恭喜你，你的钱带够了\n") ; 
}
printf("找您%d元,",change); 
printf("国庆节快乐！\n"); 


/*再来展示scanf和printf中元素对应的问题*/
int a;
int b; 
printf("请输入两个整数："); 
scanf("%d" "%d",&a,&b);
printf("%d+%d=%d",a,b,a+b);
return 0;
}
