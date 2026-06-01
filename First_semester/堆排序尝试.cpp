#include<iostream>
#include<fstream>
#include<vector>
#include<chrono>
using namespace std;
void m_swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
//void heapify(int arr[],int amount,int current){//维护堆的性质 
//	int largest=current;
//	int left_son=current*2+1;//是父亲的乘上2	
//	int right_son=current*2+2;
//	if(left_son<amount&&arr[left_son]>arr[largest]){//前一个比较是防止数组越界 
//		largest=left_son;//先交换索引 
//	}
//	if(right_son<amount&&arr[right_son]>arr[largest]){
//		largest=right_son;//先交换索引 
//	}
//	if(largest!=current){
//		m_swap(&arr[largest],&arr[current]);//哪个大就和哪个交换 
//		heapify(arr,amount,largest);
//	}
//} 
void heapify_no_digui(int arr[],int amount,int current){//无递归版本(无栈溢出风险) 
	while(true){
		int largest = current;
        int left_son = 2 * current + 1;
        int right_son = 2 * current + 2;
        if (left_son < amount && arr[left_son] > arr[largest]) 
            largest = left_son;
        if (right_son < amount && arr[right_son] > arr[largest]) 
        largest = right_son;
        if (largest == current) {
            break;
        }
        m_swap(&arr[current], &arr[largest]);
        current = largest;
	}
} 
void  heap_sort(int arr[],int n){//建堆 
	for(int i=n/2-1;i>=0;i--){
		heapify_no_digui(arr,n,i);
	}
	//排序 
	for(int i=n-1;i>0;i--){
		m_swap(&arr[i],&arr[0]);
		heapify_no_digui(arr,i,0);//就是i 因为交换首尾之后，最后的元素不再参与堆的维护 
	} 
}
int main(){
	ifstream ifs("data6.txt",ios::in);
	if(ifs.is_open())
	cout<<"打开成功！"<<endl;
	else{
		cout<<"打开失败！"<<endl;
		return 1;
	}
	vector<int>v;
	v.reserve(10000000);  
	int num;
	while(ifs>>num){
		v.push_back(num); 
	}
	ifs.close();//读完了就可以直接关闭文件了
	int n=v.size();
	int*arr=v.data(); 
	if(v.empty()){//v.begin()与v.end()相比，若相等，则返回1 
		cout<<"容器是空的，没有存进来数据"<<endl;
		return 1;//1表示程序异常错误而退出，0表示程序合乎情理的没有完成，也返回了 
	}
	auto start = chrono::high_resolution_clock::now();
	heap_sort(arr,n);
	auto end = chrono::high_resolution_clock::now();
	auto cost_time=chrono::duration_cast<chrono::milliseconds>(end-start);
	cout<<"堆排序处理时间为"<<cost_time.count()<<"毫秒"<<endl;
	//以下两种方式输出 
//	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
//		cout<<*it<<" ";
//	}
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//	} 
	return 0;
}
