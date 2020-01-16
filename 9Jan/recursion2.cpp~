#include<iostream>
using namespace std;

void waish(int a[][1000],int n){
	if(n==1){	//Base Case
		a[0][0] = 1;
		return;
	}
	int x = n/2;
	
	waish(a,x);
	
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			// copy to top right
			a[i][j+x] = a[i][j];
			
			//copy to bottom left
			a[i+x][j] = a[i][j];
			
			//copy to bottom right
			a[i+x][j+x] = -a[i][j];
		}
	}
	
}

int main(){
	int n;
	cout<<"Enter the value of n ";
	cin>>n;
	// check if it is a power of 2
	if(n&(n-1)!=0){
		cout<<"Enter a valid value "<<endl;
		return 0;
	}
	
	int a[1000][1000]={0},sum = 0;
	
	waish(a,n);
	
	//print matrix
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	//print digonal
	cout<<"the digonal element is ";
	for(int i=0;i<n;i++){
		cout<<a[i][i]<<" ";
		sum += a[i][i];
	}
	cout<<endl;
	//print trace
	cout<<"Trace is "<<sum<<endl;
	return 0;
}
