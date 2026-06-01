#include<iostream>//静态成员变量：1所有对象都共享一份数据 
using namespace std;			//2在编译时就分配内存 
class hello{					//3类内声明，类外初始化操作 
	public:	
	static void func(){
		cout<<"静态成员函数"<<endl;
	}
	static int age;//类内声明，类外初始化操作 
	private:
	int a; 
	static int height; 
};
int hello::age=11; //"hello::"表示是在类内的成员（未赋值时为0） 
int hello::height=182;
//int hello::a;这个可访问不了哦 （不是静态成员变量，只是普通变量)
int main(){
	hello h;
	h.func() ;//上下两种方式访问静态成员函数（私有静态成员函数不可以在类外被访问） 
	hello::func() ; //这样访问的话只能是在static静态函数成员的情况下 
	cout<<h.age<<endl;//这个也是上下两种访问方式 
	cout<<hello::age<<endl;
	hello h2; 
	h2.age=12;//改变静态变量的值 
	cout<<h.age<<endl;//注意：这里在“另外”一个对象里面改变值，然后用先前对象来访问age，值是改变的 
	//cout<<hello::height;错误啦，这个是私有静态变量，即使在类外被定义，但是不可以访问 
	return 0;
}
