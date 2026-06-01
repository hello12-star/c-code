#include<iostream>
using namespace std;
int main(){
    int i,j,key;
    int arr[6]={4,6,2,1,8,5};
    for(i=1;i<6;i++){
        key=arr[i];
        j=i-1;
        while(arr[j]>key&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}