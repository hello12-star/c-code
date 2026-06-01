#include<iostream>
#define max 1000
using namespace std;
struct person{
	string m_name;
	string m_sex;
	string m_number;
	int m_age;
	string m_direction;
}; 
struct tonxunlu{
	struct person arr[max];
	int m_size;
};
void showmenu(){
	cout<<"******************"<<endl;
	cout<<"**1、添加联系人 **"<<endl;
	cout<<"**2、显示联系人 **"<<endl;
	cout<<"**3、删除联系人 **"<<endl;
	cout<<"**4、查找联系人 **"<<endl;
	cout<<"**5、修改联系人 **"<<endl;
	cout<<"**6、清空通讯录 **"<<endl;
	cout<<"**0、退出通讯录 **"<<endl;
	cout<<"******************"<<endl;
}
void addperson(tonxunlu *abs)
{
	//abs->m_size=1001;
	if(abs->m_size>=max){//点运算符后面要引出的是对象实例： 
	cout<<"你的通讯录满了"<<endl;//->运算符通过指针访问的不可以是实例对象，只能是多级对象的
	}
	else{
		string name;
		cout<<"请输入姓名"<<endl;
		cin>>name;
		abs->arr[abs->m_size].m_name=name;
		string sex;
		cout<<"请输入性别(1-男，2-女)"<<endl;
		while(true){
		cin>>sex;
		if(sex=="1"||sex=="2"){
		abs->arr[abs->m_size].m_sex=(sex=="1")?"男":"女";
		break;
		}
		cout<<"你输入错了啊"<<endl;
		}
		string number;
		cout<<"请输入联系人的电话："<<endl;
		while(true){
		cin>>abs->arr[abs->m_size].m_number;	
		if(abs->arr[abs->m_size].m_number.size()==11){//这里不可以用strlen，because strlen是c语言的语法，用了会报错 
			number=abs->arr[abs->m_size].m_number;//所以考虑用c++的.size()。 
			break;
		}
		else{
			cout<<"不是，这哪国的电话号码啊(你输入的是几位)"<<endl;
		}
		}  
		int age;
		cout<<"请输入年龄："<<endl;
		while(true){
			cin>>age;
			if(age<150&&age>0){
				age=abs->arr[abs->m_size].m_age;
				break;
			}
			else{
				cout<<"这人几岁？？？"<<endl;
			}
		}
		string direction;
		cout<<"请输入地址："<<endl;
		cin>>abs->arr[abs->m_size].m_direction;
		abs->m_size++;
		cout<<"添加成功"<<endl; 
		cout<<"当前共有"<<abs->m_size<<"个联系人!"<<endl;
	}
	system("pause");
	system("cls");
}
void showperson(tonxunlu *abs){
	if(abs->m_size==0){
		cout<<"啥也没有啊！"<<endl;
	}
	else{
		for(int i=0;i<abs->m_size ;i++){
		cout<<"姓名："<<abs->arr[i].m_name<<"\t";
		cout<<"性别："<<abs->arr[i].m_sex<<"\t";
		cout<<"电话号码："<<abs->arr[i].m_number<<"\t";
		cout<<"年龄："<<abs->arr[i].m_age<<"\t";
		cout<<"地址："<<abs->arr[i].m_direction<<endl;
		}
		cout<<"一共有"<<abs->m_size<<"个联系人"<<endl;
	}
	system("pause");
	system("cls") ;
}
void fucdelete(tonxunlu *abs){
	cout<<"你想删除谁的信息"<<endl; 
	string name;
	cin>>name;
	for(int i=0;i<abs->m_size;i++){
		if(abs->arr[i].m_name==name){
			for(int j=i;j<abs->m_size-1;j++){
				abs->arr[j]=abs->arr[j+1];
			}
			abs->m_size--;
			cout<<"删除信息成功"<<endl;
			break; 
		}
		else{
			cout<<"查无此人"<<endl;
		}	
	}
	system("pause");
	system("cls");
}
void duncfind(tonxunlu *abs){
	cout<<"请输入你想找的人："<<endl;
	string name;
	cin>>name;
	for(int i=0;i<abs->m_size;i++){
		if(abs->arr[i].m_name==name){
			cout<<"找到这个人了"<<endl;
			cout<<"姓名：";
			cout<<abs->arr[i].m_name<<"\t";
			cout<<"性别：";
			cout<<abs->arr[i].m_sex<<"\t";
			cout<<"电话号码：";
			cout<<abs->arr[i].m_number<<"\t";
			cout<<"年龄：";
			cout<<abs->arr[i].m_age<<"\t";
			cout<<"地址：";
			cout<<abs->arr[i].m_direction<<endl;
			break; 
		}
	}
	system("pause");
	system("cls");
}
void reviseperson(tonxunlu *abs){
	cout<<"请输入你想修改的联系人"<<endl;
	string revisename;
	cin>>revisename;
	for(int i=0;i<abs->m_size;i++){
		if(abs->arr[i].m_name==revisename){
			string name;   string sex;   string number;   int age;   string direction;  string reviseplace;
			cout<<"你想修改该联系人的什么信息：(姓名、性别、电话号码、年龄、地址)"<<endl; 
			cin>>reviseplace;
			if(reviseplace=="姓名"){
				cout<<"改成什么姓名："<<endl;
				cin>>name;
				abs->arr[i].m_name=name;
				cout<<"修改成功！"<<endl; 
				break;
			}
			else if(reviseplace=="性别"){
				cout<<"改成什么性别："<<endl;
				cin>>sex;
				abs->arr[i].m_sex=sex;
				cout<<"修改成功！"<<endl;
				break;
			}
			else if(reviseplace=="电话号码"){
				cout<<"改成什么电话号码："<<endl;
				cin>>number;
				abs->arr[i].m_number=number;
				cout<<"修改成功！"<<endl;
				break;
			}
			else if(reviseplace=="年龄"){
				cout<<"改成什么年龄："<<endl;
				cin>>age;
				abs->arr[i].m_age=age;
				cout<<"修改成功！"<<endl;
				break;
			}
			else if(reviseplace=="地址"){
				cout<<"改成什么地址："<<endl;
				cin>>direction;
				abs->arr[i].m_direction=direction;
				cout<<"修改成功！"<<endl;
				break;
			}
		}
		else{
			cout<<"搁这乱输啥呀！"<<endl;
		}
	}
	system("pause");
	system("cls");
}
int main(){
	tonxunlu abs;
	abs.m_size=0;
	int signal=0;
	while(true){
		showmenu();
		cin>>signal;
		switch(signal){
			case 1:
				addperson(&abs);
				break;
			case 2:
				showperson(&abs); 
				break;
			case 3:
				fucdelete(&abs); 
				break;
			case 4:
				duncfind(&abs);
				break;
			case 5:
				reviseperson(&abs);
				break;
			case 6:
			{
				abs.m_size=0;
				cout<<"您已清空通讯录！"<<endl ;
				system("pause") ;
				system("cls");
				break;	
			}
			case 0:{
				cout<<"您已经退出通讯录！"<<endl ;
				return -1; 
				break;
			} 
			default:
				cout<<"您输的是啥呀！再给你一次机会！"<<endl ; 
				system("pause");
				system("cls"); 
				break;
		}
}
	return 0;
}
