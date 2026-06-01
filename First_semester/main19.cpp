#include<iostream>
using namespace std;
int main(){
	char word[8];
	scanf("%s",word);
	printf("%s",&word[0]);//第二个参数必须传入的是字符串的某个地址,也可以直接传word(首地址)
	//这个%s表示从后面传入的某个字符串中元素开始，依次输出直到字符串末尾的'\0' 
}
