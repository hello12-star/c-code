#include<cstdio>
#include<iostream>
using namespace std;
int digitR(int n,int m){
for(int i=1;i<=m-1;i++)n/=10;
return n%10;
}
int main(){
int n,m;
cin>>n>>m;//scanf("%d%d",&n,&m);
cout<<digitR(n,m); //printf("%d",digitR(n,m));
return 0;
}
