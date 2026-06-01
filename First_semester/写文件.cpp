#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream ofs;//用fstream头文件中的ofstream类创建输出流对象 
	ofs.open("text.txt",ios::out);//打开文件(文件类型，打开方式是为写文件而打开文件) 
//	ofs<<"罗亮抵达文件夹666！"<<endl;
//	ofs<<"怎么回事？"<<endl; 
//	ofs<<"我又来啦！"; 
	ofs<<11<<" "<<12<<" "<<13<<endl;
	ofs<<14<<" "<<15<<" "<<16<<endl;
	ofs.close();
	return 0;
}
//总结：1、包含头文件，2、创建流对象，3、打开文件，4、输出内容，5、关闭文件 
