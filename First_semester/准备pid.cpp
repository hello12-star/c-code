#include<iostream>
using namespace std;
typedef struct{
	float Kp;
	float Ki;
	float Kd;
	float error;
	float last_error;
	float integral;
	float output;
	int first_run;
}pidcanshu;
void PID_Init(pidcanshu *pid,float p,float i,float d){
	pid->Kp=p;
	pid->Ki=i;
	pid->Kd=d;
	pid->integral=0;
	pid->error=0;
	pid->last_error=0;
	pid->output=0;
	pid->first_run=1;
}
float PID_Calculate(pidcanshu *pid,float target,float current){
	pid->error=target-current;//一开始计算误差 
	if(pid->first_run){
		pid->last_error=pid->error;
		pid->first_run=0;
	}
	float d_i=pid->error-pid->last_error;
	pid->integral=pid->error+pid->integral;//算积分 
	pid->output=pid->Kp*pid->error+pid->Ki*pid->integral+pid->Kd*d_i;
	pid->last_error=pid->error;
	return pid->output;
}
int main(){
//	pid project={
//	.Kp=11.0,
//	.Ki=12.0,
//	.Kd=14.0,
//	};			//一种命名方式 
//	cout<<project.Kp<<" "<<project.Ki<<" "<<project.Kd<<" "; 
	pidcanshu project1;
	PID_Init(&project1,1.0,0.02,0.05);
	float v_target=1000.0;
	float v_current=0.0;
	float inertia=0.02;		//可以增加惯性指数(防止突变） 
	for(int i=0;i<500;i++){
		float pwm=PID_Calculate(&project1,v_target,v_current);
		//v_current=v_current+pwm*0.05;
		v_current=v_current+(pwm-v_current)*inertia;	//新速度=旧速度+（pwm-旧速度）*惯性指数 
		printf("第%d次：误差=%.2f,输出PWM=%.2f,当前转速v=%.2f\n",
		i+1,project1.error,pwm,v_current);
	}
	return 0;
}
