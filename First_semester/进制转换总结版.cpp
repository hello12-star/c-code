#include<iostream>
#include<string.h>
using namespace std;
void tenToany(int ten,int base){
	if(ten==0){
	cout<<0<<endl;	
	return ;
	}
	char arr[64];
	int i=0;
	while(ten>0){
	int rem=ten%base;
	arr[i++]=rem<10?(rem+'0'):(rem+'A'-10);	
	ten=ten/base;
	}
	for(i=i-1;i>=0;i--){
		cout<<arr[i];
	}
	cout<<endl; 
}
void anyToten(const char *any,int base){
	int ret=0;
	int length=strlen(any);//1111
	for(int i=0;i<length;i++){
		char c=any[i];
		int num=0;
		if(c>='0'&&c<='9'){
			num=c-'0';
		}
		else if(c>='A'&&c<='F'){
			num=c-'A'+10;
		}
		else if(c>='a'&&c<='f'){
			num=c-'a'+10;
		}
		else{
			cout<<"·Ç·¨ÊäÈë";
			return ; 
		}
		if(num>=base){
			cout<<"´íÎó";
			return ;
		}
		ret=ret*base+num;
	}
	cout<<ret;
}
int main(){
	tenToany(555,16);
	tenToany(80.25,2); 
	anyToten("10010111",2);
	return 0;
}
