#include<iostream>
using namespace std;
void power(char s[],char s1[],int i,int j){
	if(s[i]=='\0'){
		s1[j] = '\0';
		cout<<s1<<endl;
		return;
	}
	
	//exclude the char
	power(s,s1,i+1,j);
	//include the char
	s1[j] = s[i];
	power(s,s1,i+1,j+1);
	s1[j] = 0;
}
int main(){
	char s[100],s1[100],j = 0;
	cin>>s;
	power(s,s1,0,j);
}
