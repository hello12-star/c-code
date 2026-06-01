#include<iostream>
using namespace std;
class graduate {
	public:
		int m_age;
		int m_borth;
		int m_graduateyear;
		string m_name;
		string m_identity;
		string m_major;
		string m_major1;
		graduate(string name,int borth,int graduateyear,string major):m_name(name),m_borth(borth),m_graduateyear(graduateyear),m_major(major) {}
		void display(int x) {
			m_age=x-m_borth;
			cout<<m_name<<" "<<m_age<<" "<<m_graduateyear<<" "<<m_major<<endl;
		}
};
class teacher:public graduate {
	public:
		teacher(string name,int borth,string identity,string major):graduate(name,borth,0,major){
		    m_identity=identity;
		}
		void display(int x) {
			m_age=x-m_borth;
			cout<<m_name<<" "<<m_age<<" "<<m_identity<<" "<<m_major<<endl;
		}

};
class in_service_graduate:public graduate {
	public:
		in_service_graduate(string name,int borth,string identity,string major,int graduateyear,string major1):graduate(name,borth,graduateyear,major){
		    m_identity=identity;
		    m_major1=major1;
		}
		void display(int x) {
			m_age=x-m_borth;
			cout<<m_identity<<" "<<m_age<<" "<<m_major<<" "<<m_graduateyear<<" "<<m_major1<<endl;
		}

};
int main() {
	graduate gr("zhang_ling",1978,2001,"computer");
	teacher te("wang_qiang", 1976,"tutor","electronics");
	in_service_graduate sg("liu_hua",1975,"lectuer","automation",2002,"computer");
	gr.display(2002);
	te.display(2002);
	sg.display(2002);
	return 0;
}
