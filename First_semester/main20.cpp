#include<iostream>
int main(){
	typedef	struct{
	int x;
	char y;
	float z;
	} structname;//结构体类型的名字 
	structname c;//定义结构体变量名 c 
	structname d;
	c.x=6;
	d.z=6.66;
	d.x=5;
	printf("%d\n",c.x);
	printf("%f\n",d.z);
	printf("%d\n",d.x);
	
	typedef enum{monday=1,
	tuesday,
	thursday,}week_t;
	week_t week1;
	week_t week2;
	week1=monday;
	printf("%d\n",week1);
} 
