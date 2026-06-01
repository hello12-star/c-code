#include<iostream>
using namespace std;
int main(){
	cout<<"sizeof(char)=="<<sizeof(char)<<endl;
	cout<<"sizeof(int)=="<<sizeof(int)<<endl;
	cout<<"sizeof(short)=="<<sizeof(short)<<endl;
	cout<<"sizeof(double)=="<<sizeof(double)<<endl;
	cout<<"sizeof(long)=="<<sizeof(long)<<endl;
	cout<<"sizeof(long long)=="<<sizeof(long long)<<endl;
	int a=0x12;
	printf("%d\n",a);
	float a1,b,c;
	a1=1.3456;
	b=1.2339;
	c=a1+b;
	printf("%lf",c);
	return 0;
}
