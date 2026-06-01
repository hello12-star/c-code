 #include<iostream>
 using namespace std;
 int main(){
 	char c;
 	cin>>c;
 	char ret=(c>='A'&&c<='Z')?(c+32):(c-32);
 	cout<<ret<<endl;
 	
 	return 0;
 }
