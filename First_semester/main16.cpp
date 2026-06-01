#include<iostream>
#include<stdlib.h>
using namespace std;
int main(void){
	void *p;
	int cnt;
	while(p=malloc(100*1024*1024)){
		cnt++;
	}
	printf("分配了%d00MB的空间\n",cnt); 
	return 0;
}
