#include<iostream> 
using namespace std;
int main(){
	int a=2.5;
	int b;
	b=2.5/2.5;
	printf("%d\n",b);
	char c='a';
	printf("%d\n",c);
	printf("%d\n",++c);
	printf("%d\n",c);
	printf("%d\n",c++);
	printf("%d\n",c);
	
	char d; 
	cin>>d;
	while(d!='\n'){
		if((d>='a'&&d<='z')||(d>='A'&&d<='Z')){
			if((d>='W'&&d<='Z')||(d>='w'&&d<='z')){
				d=d-22;
			}
			else 
			d=d+4;
		}
		cout<<d;
		cin>>d; 
	}
	cout<<endl;
	
	return 0;
}
