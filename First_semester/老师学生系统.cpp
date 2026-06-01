#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
struct students{
	int score;
	string s_name;
};
struct teacher{
	string t_name;
	struct students s_arr[5];
};
void setinfoteacher(struct teacher arr[],int len){
	string tname="Teacher_";
	string teachername="ABC";
	for(int i=0;i<3;i++){
		arr[i].t_name=tname+teachername[i];
		cout<<"老师姓名："<<arr[i].t_name<<":"<<endl;	
		for(int j=0;j<5;j++){
			string studentsname="ABCDE";
			string sname="student_";
			arr[i].s_arr[j].s_name=sname+studentsname[j];
			int random=rand()%61+40; 
			arr[i].s_arr[j].score=random; 
			cout<<"\t学生姓名："<<arr[i].s_arr[j].s_name<<" 得分是："<<arr[i].s_arr[j].score<<endl;
		}
	}
}
int main(){
	srand(time(NULL));
	struct teacher t_arr[3];
	int len=sizeof(t_arr)/sizeof(t_arr[0]);
	setinfoteacher(t_arr,len);
	return 0;
} 
