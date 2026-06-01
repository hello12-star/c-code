#include<iostream>
using namespace std;
class Point{
	private:
		int x,y;
	public:
		void set_x(int x1){
			x=x1;
		}
		int get_x(){
			return x;
		}
		void set_y(int y1){
			y=y1;
		}
		int get_y(){
			return y;
		}
};
class Circle{
	private:
		int R;
		Point center;//int corex,corey;错误不行	
	public: 
		void set_R(int R1){
			R=R1;
		} 
		int get_R(){
			return R;	
		}
		void set_center(Point center1){
			center=center1;
		}
		Point get_center(){//这里不可以用int 
			return center;
		}
};
void Ison(Circle&c,Point&p){
	int distance=(c.get_center().get_x()-p.get_x())*(c.get_center().get_x()-p.get_x())+
	(c.get_center().get_y()-p.get_y())*(c.get_center().get_y()-p.get_y());
	int RR=c.get_R()*c.get_R(); 
	if(RR==distance)
	cout<<"该点在圆上"<<endl;
	else if(RR>distance)
	cout<<"该点在圆内"<<endl;
	else
	cout<<"该点在圆外"<<endl;
	cout<<RR;
} 
int main(){
	Point p;//要判断的点 
	Point center;//圆心 
	Circle c;
	c.set_R(4);  
	p.set_x(2);  
	p.set_y(3); 
	center.set_x(6);  
	center.set_y(5);
	c.set_center(center);  
	Ison(c,p);
	return 0;
} 
