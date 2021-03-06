#include<iostream>
#include<cstring>
using namespace std;

void permu(char s[],int n,int i){
	if(n==i){
		s[i] = '\0';
		cout<<s<<endl;
		return;
	}
	
	for(int j=i;j<n;j++){
		swap(s[i],s[j]);
		permu(s,n,i+1);
		//Backtracking
		swap(s[i],s[j]);
	}
}

int main(){
	char s[100];
	cin>>s;
	permu(s,strlen(s),0);
	return 0;
}
