#include<iostream>
using namespace std;
#include<fstream>
int main(){
	//ifstream ifs;
	//ifs.open("text.txt",ios::in); 
	//上面两步可以直接写ifstream ifs("text.txt",ios::in) 
	ifstream ifs("text.txt",ios::in);
	if(!ifs.is_open()){//一个可以判断文件是否可以打开的函数 
		cout<<"文件打开失败！"<<endl;
	return 1; 
	}
	else{
		cout<<"文件打开成功！"<<endl;
	}
	//四种读的方法：
	 
//	char buf[1024]={0};
//	while(ifs>>buf){   //直接把文件读入buf的字符数组 
//		cout<<buf<<endl; 
//	} 
//	char buf[1024]={0};
//	while(ifs.getline(buf,sizeof(buf))){ 
//		cout<<buf<<endl;
//	}
	string buf;
	while(getline(ifs,buf)){//流对象，数组 
		cout<<buf<<endl;
	} 
//	char c;
//	while((c=ifs.get())!=EOF){//"end of file"，效率低，一个一个地读，不推荐 
//		cout<<c;
//	}
	ifs.close();
	return 0;
}
