#include<stdio.h>
int main(){			//直接运行 
	int x=2;  
	//scanf("%d",&x);
	int count=0;
	while(count<50){
		int isprime=1;
		int i;
		for(i=2;i<x;i++){
		if(x%i==0){
			isprime=0;
			break;}
		}
		if(isprime==1){
			printf("%d  ",x);
			count++;
		}
		x++;
	}
printf("\n");
	return 0;
}
//int main(){
//	int x=2;
//	int count=0;
//	while(count<20){
//		int isprime=1;
//		int i=2;
//		for( i=2;i<x;i++){
//			if(x%i==0){
//			isprime=0;
//			break;}}
//		if(isprime==1){
//				printf("%d   ",x);
//				count++;
//			}
//			
//		x++;
//	}
//	printf("\n");
//	return 0;
//}




