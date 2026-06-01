#include<iostream>
using namespace std;
int main(){
	int n,i;
	for(n=2;n<=200;n++){
		for(i=2;i*i<=n;i++){
			if(n%i==0)
			break;
		}
			if(i*i>=n)
				cout<<n<<" ";
	}
	return 0;
}
