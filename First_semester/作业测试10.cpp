#include<iostream>
using namespace std;
 
void upCopy(char *upstr, char *oldstr) {
/**********Program**********/
	int i=0;
	int j=0; 
	while(oldstr[i]!='\0'){
		if(oldstr[i]>='A'&&oldstr[i]<='Z'){
			upstr[j]=oldstr[i];
			j++;
		}
		i++;
	}
	upstr[j]='\0';


/**********  End  **********/
}
 
int main() {
    char oldStr[] = "foiwABEifjCDB";
    char newStr[50]; 
    upCopy(newStr, oldStr);
    cout<<newStr; 
    return 0;
}
