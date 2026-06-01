#include<iostream>
#include<vector>
#include<fstream>
#include<chrono> 
using namespace std;
void half_insert(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int low=0;
        int high=i-1;
        int insertPos=i;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(temp<arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            insertPos=low;
        }
        for(int j=i-1;j>=insertPos;j--){
            arr[j+1]=arr[j];
        }
        arr[insertPos]=temp;
    }
}
void print(int arr[],int n){
		for(int k=0;k<n;k++){
		cout<<arr[k]<<" ";
	}
}
int main(){
    ifstream ifs("data5.txt",ios::in);
    if(ifs.is_open()){
        cout<<"打开成功！"<<endl;
    }
    else{
        cout<<"打开失败！"<<endl;
        return 1;
    }
    vector<int>v;
    v.reserve(10000);
    int num;
    while(ifs>>num){
        v.push_back(num);
    }
    ifs.close();
    int n=v.size();
    int *arr=v.data();
    auto start=chrono::high_resolution_clock::now();
    half_insert(arr,n);
    auto end=chrono::high_resolution_clock::now();
    auto cost_time=chrono::duration_cast<chrono::milliseconds>(end-start);
    //print(arr,n);
    cout<<"折半插入排序消耗"<<cost_time.count()<<"毫秒"<<endl;
    return 0;
}
