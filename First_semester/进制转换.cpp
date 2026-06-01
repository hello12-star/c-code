#include<iostream>
using namespace std;
void tenTotwo(int ten);
void tenToeight(int ten);
void tenTosixteen(int ten); 
void twoToten(const char arr[]); 
int main(){
	//十进制转换为其他进制：用十进制的数去除以要转换的进制的数（直至商为0），每次除以都取余数，并且余数逆序排列 
	tenTotwo(56);
	tenToeight(56); 
	tenTosixteen(56); 
	twoToten("1101");
	//其他进制的数转换为十进制则是从该数的个位开始乘自己的进制数（从个位乘进制的0次方开始） 
	return 0;
}
void tenTotwo(int ten){//25十进制转换为二进制 
	int a[32];
	int length=0;
	if(ten==0){
		cout<<0<<endl;
		return ;
	}
	while(ten>0){
		a[length++]=ten%2;//1//0//0//1//1
		ten=ten/2;
	}
	for(int i=length-1;i>=0;i--) 
	cout<<a[i];	
	cout<<endl;
} 
void tenToeight(int ten){//十进制转换为八进制 
	int a[32];
	int length=0;
	if(ten==0){
		cout<<0<<endl;
		return ;
	}
	while(ten>0){
		a[length++]=ten%8;
		ten=ten/8;
	}
	for(int i=length-1;i>=0;i--) 
	cout<<a[i];
	cout<<endl;	
} 
void tenTosixteen(int ten)
{//十进制转十六进制 
	char a[32];
	int length=0;
	char c=0;
	if(ten == 0){
        cout << 0 << endl;
        return;
    }
	while(ten>0){
		int ten1=ten%16;
		if(ten1<=15&&ten1>=10){
			c='A'+(ten1-10);
		}
		else{
			c='0'+ten1;
		}
		a[length++]=c;
		ten=ten/16;
	}
	for(int i=length-1;i>=0;i--){
	cout<<a[i];	
	}
	cout<<endl;
}
void twoToten(const char arr[]){
	int ret=0;
	int i=0;
	while(arr[i]!='\0'){
		if(arr[i]!='0'&&arr[i]!='1'){
			cout<<"非法输入";
			return ;
		}
		int ret1=arr[i]-'0';
		ret=ret*2+ret1;
		i++;
	}
	cout<<ret<<endl;
} 
